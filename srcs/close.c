/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkiloul <lkiloul@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 20:46:08 by lkiloul           #+#    #+#             */
/*   Updated: 2025/02/24 20:27:16 by lkiloul          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_map(t_game *vars)
{
	if (vars->map.map)
	{
		while (vars->map.height)
			free(vars->map.map[--vars->map.height]);
		free(vars->map.map);
	}
	if (vars->map_copy.map)
	{
		while (vars->map_copy.height)
			free(vars->map_copy.map[--vars->map_copy.height]);
		free(vars->map_copy.map);
	}
}

void	free_resources(t_game *vars)
{
	if (vars->sprite.background.xpm)
		mlx_destroy_image(vars->mlx, vars->sprite.background.xpm);
	if (vars->sprite.wall.xpm)
		mlx_destroy_image(vars->mlx, vars->sprite.wall.xpm);
	if (vars->sprite.coins.xpm)
		mlx_destroy_image(vars->mlx, vars->sprite.coins.xpm);
	if (vars->sprite.exit.xpm)
		mlx_destroy_image(vars->mlx, vars->sprite.exit.xpm);
	if (vars->sprite.player.xpm)
		mlx_destroy_image(vars->mlx, vars->sprite.player.xpm);
	if (vars->win)
		mlx_destroy_window(vars->mlx, vars->win);
	if (vars->mlx)
	{
		mlx_loop_end(vars->mlx);
		mlx_destroy_display(vars->mlx);
		free(vars->mlx);
	}
	free_map(vars);
	free(vars);
}

int	close_window(t_game *vars)
{
	free_resources(vars);
	exit(0);
	return (0);
}
