/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkiloul <lkiloul@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 23:04:49 by lkiloul           #+#    #+#             */
/*   Updated: 2025/01/21 01:05:34 by lkiloul          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void init_sprites(t_game *vars)
{
    vars->background.xpm = mlx_xpm_file_to_image(vars->mlx, "assets/ground.xpm", &vars->background.x, &vars->background.y);
    vars->wall.xpm = mlx_xpm_file_to_image(vars->mlx, "assets/wall.xpm", &vars->wall.x, &vars->wall.y);
    vars->player.xpm = mlx_xpm_file_to_image(vars->mlx, "assets/player.xpm", &vars->player.x, &vars->player.y);
}

void    draw_background(t_game *vars, int x, int y)
{
    mlx_put_image_to_window(vars->mlx, vars->win, vars->background.xpm, x, y);

}

void   draw_wall(t_game *vars, int x, int y)
{
    mlx_put_image_to_window(vars->mlx, vars->win, vars->wall.xpm, x, y);
}

void    draw_player(t_game *vars, int x, int y)
{
    mlx_put_image_to_window(vars->mlx, vars->win, vars->player.xpm, x, y);
}