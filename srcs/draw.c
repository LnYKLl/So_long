/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkiloul <lkiloul@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 23:04:49 by lkiloul           #+#    #+#             */
/*   Updated: 2025/01/25 23:58:24 by lkiloul          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	draw_wall(t_game *vars, int x, int y)
{
	mlx_put_image_to_window(vars->mlx, vars->win, vars->wall.xpm, x * 64, y
		* 64);
}

void	draw_player(t_game *vars, int x, int y)
{
	mlx_put_image_to_window(vars->mlx, vars->win, vars->player.img.xpm, x * 64,
		y * 64);
}

void	draw_coins(t_game *vars, int x, int y)
{
	mlx_put_image_to_window(vars->mlx, vars->win, vars->coins.xpm, x * 64, y
		* 64);
	vars->map.collectibles++;
}

void	draw_exit(t_game *vars, int x, int y)
{
	mlx_put_image_to_window(vars->mlx, vars->win, vars->exit.xpm, x * 64, y
		* 64);
}

void	draw_background(t_game *vars, int x, int y)
{
	mlx_put_image_to_window(vars->mlx, vars->win, vars->background.xpm, x * 64,
		y * 64);
}