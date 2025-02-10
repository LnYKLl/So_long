/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkiloul <lkiloul@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 00:04:23 by lkiloul           #+#    #+#             */
/*   Updated: 2025/02/10 16:41:54 by lkiloul          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "so_long.h"
#include <stdio.h>

int	is_char_valid(char *line)
{
	int	i;
	int	p;

	i = 0;
	p = 0;
	if (line[0] != '1' || line[ft_strlen(line) - 2] != '1')
	{
		ft_printf("Error : The map is not surrounded by walls.\n");
		return (0);
	}
	while (line[i])
	{
		if (line[i] != '1' && line[i] != '0' && line[i] != 'P' && line[i] != 'E'
			&& line[i] != 'C' && line[i] != '\n')
		{
			ft_printf("Error :Invalid character in the map.\n");
			return (0);
		}
		if (line[i] == 'P' && p == 0)
			p++;
		else if (line[i] == 'P' && p == 1)
			perror("Error : There is more than one player in the map file.\n");
		i++;
	}
	return (1);
}

int	check_file(char **argv)
{
	if (ft_strncmp(argv[1] + ft_strlen(argv[1]) - 4, ".ber", 4) != 0)
	{
		perror("Error : The file is not a .ber file.\n");
		return (0);
	}
	return (1);
}

int	map_parsing(t_game *vars, char **argv)
{
	int		fd;

	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
	{
		perror("Error");
		return (-1);
	}
	map_checker(vars, fd);
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
	if (path_checker(vars) != 1)
	{
		ft_printf("Error : the map does not have a valid path.\n");
		return (0);
	}
	return (1);
}
void map_checker(t_game *vars, int fd)
{
	char *line;
	
	line = get_next_line(fd);
	while (line != NULL)
	{
		if (!is_char_valid(line))
		{
			free(line);
			close(fd);
			return;
		}
		if (vars->map.width == 0)
			vars->map.width = ft_strlen(line) - 1;
		else if (vars->map.width != (int)ft_strlen(line) - 1)
		{
			free(line);
			close(fd);
			ft_printf("Error : The map is not rectangular.\n");
			return;
		}
		vars->map.height++;
		free(line);
		line = get_next_line(fd);
	}
}
