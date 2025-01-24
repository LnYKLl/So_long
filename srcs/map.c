/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkiloul <lkiloul@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 00:04:23 by lkiloul           #+#    #+#             */
/*   Updated: 2025/01/24 10:23:44 by lkiloul          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "libft.h"
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

int	check_map(t_game *vars, char **argv)
{
	char	*line;
	int		fd;
	int		i;

	i = 0;
	vars->map.width = 0;
	vars->map.height = 0;
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		return (0);
	while ((line = get_next_line(fd)) != NULL)
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
	}
	close(fd);
	vars->map.map = malloc(sizeof(char *) * vars->map.height);
	if (!vars->map.map)
		return (0);
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		return (0);
	while ((line = get_next_line(fd)) != NULL)
	{
		vars->map.map[i] = ft_strdup(line);
		free(line);
		i++;
	}
	close(fd);
	return (1);
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
			draw_coins(vars, i , j);
		else if (line[i] == 'E')
		{
			draw_background(vars, i, j);
			vars->map.exit_x = i;
			vars->map.exit_y = j;
		}
		i++;
	}
}

void	draw_map(t_game *vars, char **argv)
{
	char *line;
	int fd;
	int j = 0;

	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		return ;
	while ((line = get_next_line(fd)) != NULL)
	{
		draw_line(vars, line, j);
		j++;
		free(line);
	}
	close(fd);
}