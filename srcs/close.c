/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkiloul <lkiloul@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 20:46:08 by lkiloul           #+#    #+#             */
/*   Updated: 2025/01/28 10:40:56 by lkiloul          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
void free_map(t_game *vars)
{
    if (vars->map.map)
    {
        while (vars->map.height)
            free(vars->map.map[--vars->map.height]);
        free(vars->map.map);
    }
}
void	free_resources(t_game *vars)
{
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
