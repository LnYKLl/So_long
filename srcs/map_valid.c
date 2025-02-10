/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_valid.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkiloul <lkiloul@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 10:45:22 by lkiloul           #+#    #+#             */
/*   Updated: 2025/02/10 15:58:42 by lkiloul          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "so_long.h"

int	map_read(t_game *vars, char **argv)
{
	char *line;
	int fd;
	int i;

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
int map_copy(t_game *vars)
{
    int i;

    i = 0;
    vars->map.map_copy = malloc(sizeof(char *) * (vars->map.height + 1));
    if (!vars->map.map_copy)
        return (0);
    while (i < vars->map.height)
    {
        vars->map.map_copy[i] = ft_strdup(vars->map.map[i]);
        if (!vars->map.map_copy[i])
        {
            while (--i >= 0)
                free(vars->map.map_copy[i]);
            free(vars->map.map_copy);
            return (0);
        }
        i++;
    }
    return (1);
}

int path_alg(t_game *vars, int x, int y)
{
    if (x < 0 || y < 0 || x >= vars->map.width || y >= vars->map.height)
        return (0);
    if (vars->map.map_copy[y][x] == '1' || vars->map.map_copy[y][x] == '~')
        return (0);
    vars->map.map_copy[y][x] = '~';
    path_alg(vars, x + 1, y);
    path_alg(vars, x - 1, y);
    path_alg(vars, x, y + 1);
    path_alg(vars, x, y - 1);
    return (1);
}

int path_checker(t_game *vars)
{
    int i;
    int j;

    i = 0;
    while (i < vars->map.height)
    {
        j = 0;
        while (j < vars->map.width)
        {
            if (!path_alg(vars, j, i))
                return (0);
            j++;
        }
        i++;
    }
    return (1);
}