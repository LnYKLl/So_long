/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkiloul <lkiloul@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 00:04:23 by lkiloul           #+#    #+#             */
/*   Updated: 2025/02/25 19:18:18 by lkiloul          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	is_char_valid(t_game *vars, char *line, int j, int i)
{
	if (line[0] == '\n' && line[1] == '\0')
		return (1);
	if (line[0] != '1' || line[ft_strlen(line) - 2] != '1')
		return (ft_printf("Error : Invalid wall configuration.\n"), 0);
	while (line[++i])
	{
		if (!ft_strchr("10PEC\n", line[i]))
			return (ft_printf("Error : Invalid character.\n"), 0);
		if (line[i] == 'P' && vars->player.players++)
			return (ft_printf("Error : Multiple players.\n"), 0);
		if (line[i] == 'P')
		{
			vars->player.x = i;
			vars->player.y = j;
		}
		if (line[i] == 'E' && vars->map.exit++)
			return (ft_printf("Error : Too many exits.\n"), 0);
		if (line[i] == 'E')
		{
			vars->map.exit_x = i;
			vars->map.exit_y = j;
		}
		vars->map.collectibles += (line[i] == 'C');
	}
	return (1);
}

int	check_file(char **argv)
{
	if (ft_strncmp(argv[1] + ft_strlen(argv[1]) - 4, ".ber", 4) != 0)
	{
		ft_printf("Error : The file is not a .ber file.\n");
		return (0);
	}
	return (1);
}

int	map_parsing(t_game *vars, char **argv)
{
	int		fd;
	char	*line;
	int		line_length;

	line = NULL;
	line_length = 0;
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
	{
		perror("Error");
		return (-1);
	}
	if (!map_checker(vars, fd, line, line_length))
	{
		close(fd);
		return (0);
	}
	if (vars->map.height > 30 || vars->map.width > 60)
	{
		ft_printf("Error : The map is too big.\n");
		close(fd);
		return (0);
	}
	close(fd);
	return (1);
}

int	check_map(t_game *vars, char **argv)
{
	vars->map.width = 0;
	vars->map.height = 0;
	if (check_file(argv) == 0)
		return (0);
	if (map_parsing(vars, argv) != 1)
		return (0);
	vars->map.map = malloc(sizeof(char *) * vars->map.height);
	if (!vars->map.map)
		return (0);
	if (!map_read(vars, argv))
		return (0);
	if (!map_copy(vars))
		return (0);
	if (vars->map.collectibles <= 0 || vars->player.players != 1
		|| vars->map.exit_x == -1 || vars->map.exit_y == -1)
	{
		ft_printf("Error : The map is missing something.\n");
		return (0);
	}
	if (check_path(vars) != 1)
	{
		ft_printf("Error : the map does not have a valid path.\n");
		return (0);
	}
	return (1);
}

int	map_checker(t_game *vars, int fd, char *line, int line_length)
{
	line = get_next_line(fd);
	while (line != NULL)
	{
		if (!is_char_valid(vars, line, vars->map.height, -1))
			return (free(line), 0);
		line_length = ft_strlen(line) - (line[ft_strlen(line) - 1] == '\n');
		if (vars->map.width == 0 && line[0] != '\n')
			vars->map.width = line_length;
		if (line[0] != '\n' && vars->map.width != line_length)
		{
			free(line);
			line = get_next_line(fd);
			while (line != NULL)
			{
				free(line);
				line = get_next_line(fd);
			}
			return (ft_printf("Error: The map is not rectangular.\n"), 0);
		}
		vars->map.height += (line[0] != '\n');
		free(line);
		line = get_next_line(fd);
	}
	return (1);
}
