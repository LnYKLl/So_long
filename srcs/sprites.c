/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkiloul <lkiloul@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 23:04:49 by lkiloul           #+#    #+#             */
/*   Updated: 2025/01/23 00:23:42 by lkiloul          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void init_sprites(t_game *vars)
{
    vars->background.xpm = mlx_xpm_file_to_image(vars->mlx, "assets/ground.xpm", &vars->background.x, &vars->background.y);
    vars->wall.xpm = mlx_xpm_file_to_image(vars->mlx, "assets/wall.xpm", &vars->wall.x, &vars->wall.y);
    vars->player.img.xpm = mlx_xpm_file_to_image(vars->mlx, "assets/player.xpm", &vars->player.img.x, &vars->player.img.y);
    vars->coins.xpm = mlx_xpm_file_to_image(vars->mlx, "assets/coins.xpm", &vars->coins.x, &vars->coins.y);
    vars->exit.xpm = mlx_xpm_file_to_image(vars->mlx, "assets/exit.xpm", &vars->exit.x, &vars->exit.y);
}

void   draw_wall(t_game *vars, int x, int y)
{
    mlx_put_image_to_window(vars->mlx, vars->win, vars->wall.xpm, x * 64, y * 64);
}

void    draw_player(t_game *vars, int x, int y)
{
    mlx_put_image_to_window(vars->mlx, vars->win, vars->player.img.xpm, x * 64, y * 64);
}

void    draw_coins(t_game *vars, int x, int y)
{
    mlx_put_image_to_window(vars->mlx, vars->win, vars->coins.xpm, x * 64, y * 64);
    vars->map.collectibles++;
}

void    draw_exit(t_game *vars, int x, int y)
{
    mlx_put_image_to_window(vars->mlx, vars->win, vars->exit.xpm, x * 64, y * 64);
}

void    draw_background(t_game *vars, int x, int y)
{
    mlx_put_image_to_window(vars->mlx, vars->win, vars->background.xpm, x * 64, y * 64);
}