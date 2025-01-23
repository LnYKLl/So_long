/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkiloul <lkiloul@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 20:50:42 by lkiloul           #+#    #+#             */
/*   Updated: 2025/01/23 02:25:11 by lkiloul          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int game_loop(char **argv)
{
    t_game	*vars = malloc(sizeof(t_game));
    if (!vars)
        return (1);
    if(check_map(vars, argv) == 0) 
    {
        printf("Error in the map.\n");
        free(vars);
        return (0);
    }
    vars->mlx = mlx_init();
    vars->win = mlx_new_window(vars->mlx, vars->map.width * 64, vars->map.height * 64, "So_Long");
    init_sprites(vars);
    draw_map(vars, argv);
    mlx_key_hook(vars->win, key_hook, vars);
    mlx_hook(vars->win, 17, 0L, close_window, vars);
    mlx_loop(vars->mlx);
    return (0);
}
