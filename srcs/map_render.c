/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_render.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkiloul <lkiloul@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 00:03:05 by lkiloul           #+#    #+#             */
/*   Updated: 2025/01/26 00:26:01 by lkiloul          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "so_long.h"

void	draw_map(t_game *vars, char **argv)
{
	char	*line;
	int		fd;
	int		j;

	j = 0;
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		return ;
	line = get_next_line(fd);
	while (line != NULL)
	{
		draw_line(vars, line, j);
		j++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
}

void	draw_line(t_game *vars, char *line, int j)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] == '1')
			draw_wall(vars, i, j);
		else if (line[i] == 'P')
		{
			draw_player(vars, i, j);
			vars->player.x = i;
			vars->player.y = j;
		}
		else if (line[i] == '0')
			draw_background(vars, i, j);
		else if (line[i] == 'C')
			draw_coins(vars, i, j);
		else if (line[i] == 'E')
		{
			draw_background(vars, i, j);
			vars->map.exit_x = i;
			vars->map.exit_y = j;
		}
		i++;
	}
}

int	render_map(t_game *vars, char **argv)
{
	char	*line;
	int		fd;
	int		i;

	i = 0;
	vars->map.map = malloc(sizeof(char *) * vars->map.height);
	if (!vars->map.map)
		return (0);
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
	free(line);
	close(fd);
	return (1);
}