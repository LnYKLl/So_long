/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_valid.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkiloul <lkiloul@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 10:45:22 by lkiloul           #+#    #+#             */
/*   Updated: 2025/02/25 19:18:26 by lkiloul          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	map_read(t_game *vars, char **argv)
{
	char	*line;
	int		fd;
	int		i;

	i = 0;
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		return (0);
	line = get_next_line(fd);
	while (line != NULL)
	{
		if (line[0] != '\n')
		{
			vars->map.map[i] = ft_strdup(line);
			i++;
		}
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (1);
}

int	map_copy(t_game *vars)
{
	int	i;

	vars->map_copy.map = malloc(sizeof(char *) * (vars->map.height + 1));
	if (!vars->map_copy.map)
		return (0);
	i = 0;
	while (i < vars->map.height)
	{
		vars->map_copy.map[i] = ft_strdup(vars->map.map[i]);
		if (!vars->map_copy.map[i])
		{
			while (--i >= 0)
				free(vars->map_copy.map[i]);
			free(vars->map_copy.map);
			return (0);
		}
		i++;
	}
	vars->map_copy.width = vars->map.width;
	vars->map_copy.height = vars->map.height;
	vars->map_copy.collectibles = vars->map.collectibles;
	vars->map_copy.exit_x = vars->map.exit_x;
	vars->map_copy.exit_y = vars->map.exit_y;
	return (1);
}

void	path_alg(t_game *vars, int x, int y)
{
	if (x < 0 || y < 0 || x >= vars->map.width || y >= vars->map.height)
		return ;
	if (vars->map_copy.map[y][x] == '1' || vars->map_copy.map[y][x] == '~')
		return ;
	if (vars->map_copy.map[y][x] == 'E')
		vars->map_copy.exit = 1;
	if (vars->map_copy.map[y][x] == 'C')
		vars->map_copy.collectibles--;
	vars->map_copy.map[y][x] = '~';
	path_alg(vars, x + 1, y);
	path_alg(vars, x - 1, y);
	path_alg(vars, x, y + 1);
	path_alg(vars, x, y - 1);
}

int	check_path(t_game *vars)
{
	path_alg(vars, vars->player.x, vars->player.y);
	if (vars->map_copy.exit == 0 || vars->map_copy.collectibles != 0)
		return (0);
	return (1);
}
