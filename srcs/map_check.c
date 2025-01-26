/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkiloul <lkiloul@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 00:04:23 by lkiloul           #+#    #+#             */
/*   Updated: 2025/01/26 00:26:53 by lkiloul          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "so_long.h"

int	is_valid_line(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] != '1' && line[i] != '0' && line[i] != 'P' && line[i] != 'E'
			&& line[i] != 'C' && line[i] != '\n')
			return (0);
		i++;
	}
	return (1);
}

int	check_file(char **argv)
{
	if (ft_strncmp(argv[1] + ft_strlen(argv[1]) - 4, ".ber", 4) != 0)
	{
		ft_printf("Error\nThe map file must have the .ber extension.\n");
		return (0);
	}
	return (1);
}

int	map_parsing(t_game *vars, char **argv)
{
	char	*line;
	int		fd;

	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		return (0);
	line = get_next_line(fd);
	while (line != NULL)
	{
		if (!is_valid_line(line))
		{
			free(line);
			close(fd);
			return (0);
		}
		if (vars->map.width == 0)
			vars->map.width = ft_strlen(line) - 1;
		vars->map.height++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (1);
}

int	check_map(t_game *vars, char **argv)
{
	int		fd;
	char	*line;
	int		i;

	vars->map.width = 0;
	vars->map.height = 0;
	if (check_file(argv) == 0)
		return (0);
	if (!map_parsing(vars, argv))
		return (0);
	vars->map.map = malloc(sizeof(char *) * vars->map.height);
	if (!vars->map.map)
		return (0);
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		return (0);
	i = 0;
	while ((line = get_next_line(fd)) != NULL)
	{
		vars->map.map[i] = ft_strdup(line);
		free(line);
		i++;
	}
	close(fd);
	return (1);
}
