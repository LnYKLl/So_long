/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkiloul <lkiloul@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 20:50:42 by lkiloul           #+#    #+#             */
/*   Updated: 2025/01/21 02:19:13 by lkiloul          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int game_loop(char **argv)
{
    int i;
    int j;

    i = 15;
    j = 15;
    t_game	*vars = malloc(sizeof(t_game));
    if (!vars)
        return (1);
    if(check_map(argv) == 0)
    {
        printf("Error in the map.\n");
        free(vars);
        return (0);
    }
    vars->mlx = mlx_init();
    vars->win = mlx_new_window(vars->mlx, i * 40, j * 40, "So_Long");
    init_sprites(vars);
    draw_background(vars, 1 * 30, 1 * 30);
    draw_wall(vars, 5 * 40, 5 * 40);
    draw_player(vars, 0, 0);
    mlx_key_hook(vars->win, key_hook, vars);
    mlx_hook(vars->win, 17, 0L, close_window, vars);
    mlx_loop(vars->mlx);
    return (0);
}