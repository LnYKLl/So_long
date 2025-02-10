/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_valid.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkiloul <lkiloul@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 10:45:22 by lkiloul           #+#    #+#             */
/*   Updated: 2025/02/10 16:58:31 by lkiloul          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
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
		vars->map.map[i] = ft_strdup(line);
		free(line);
		i++;
		line = get_next_line(fd);
	}
	close(fd);
	return (1);
}
int	map_copy(t_game *vars)
{
	int	i;

	i = 0;
	vars->map_copy.map = malloc(sizeof(char *) * (vars->map.height + 1));
	if (!vars->map_copy.map)
		return (0);
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
	vars->map_copy.exit = vars->map.exit;
	vars->map_copy.exit_x = vars->map.exit_x;
	vars->map_copy.exit_y = vars->map.exit_y;
	return (1);
}

int	path_alg(t_game *vars, int x, int y)
{
	int	up;
	int	down;
	int	left;
	int	right;

	if (x < 0 || y < 0 || x >= vars->map.width || y >= vars->map.height)
		return (0);
	if (vars->map_copy.map[y][x] == '1' || vars->map_copy.map[y][x] == '~')
		return (0);
	if (vars->map_copy.map[y][x] == 'C')
		vars->map_copy.collectibles--;
	vars->map_copy.map[y][x] = '~';
	right = path_alg(vars, x + 1, y);
	left = path_alg(vars, x - 1, y);
	up = path_alg(vars, x, y + 1);
	down = path_alg(vars, x, y - 1);
	if (right || left || up || down)
		return (1);
	return (0);
}

int	path_checker(t_game *vars)
{
	int i;
	int j;

	i = 0;
	while (i < vars->map_copy.height)
	{
		j = 0;
		while (j < vars->map_copy.width)
		{
			if (!path_alg(vars, j, i))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}