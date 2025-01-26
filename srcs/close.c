/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkiloul <lkiloul@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 20:46:08 by lkiloul           #+#    #+#             */
/*   Updated: 2025/01/26 00:18:41 by lkiloul          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void free_resources(t_game *vars)
{
    if (vars->map.map)
    {
        for (int i = 0; i < vars->map.height; i++)
            free(vars->map.map[i]);
        free(vars->map.map);
    }
    if (vars->background.xpm)
        mlx_destroy_image(vars->mlx, vars->background.xpm);
    if (vars->wall.xpm)
        mlx_destroy_image(vars->mlx, vars->wall.xpm);
    if (vars->coins.xpm)
        mlx_destroy_image(vars->mlx, vars->coins.xpm);
    if (vars->exit.xpm)
        mlx_destroy_image(vars->mlx, vars->exit.xpm);
    if (vars->player.img.xpm)
        mlx_destroy_image(vars->mlx, vars->player.img.xpm);
    if (vars->win)
        mlx_destroy_window(vars->mlx, vars->win);
    if (vars->mlx)
    {
        mlx_loop_end(vars->mlx);
        mlx_destroy_display(vars->mlx);
    }
    free(vars);
}

int close_window(t_game *vars)
{
    free_resources(vars);
    exit(0);
    return (0);
}

