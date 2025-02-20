/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkiloul <lkiloul@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 20:50:42 by lkiloul           #+#    #+#             */
/*   Updated: 2025/02/20 01:34:19 by lkiloul          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int game_loop(char **argv)
{
    t_game	*vars = malloc(sizeof(t_game));
    if (!vars)
        return (1);
    vars->map.height = 0;
    vars->map.width = 0;
    vars->map.collectibles = 0;
    vars->player.x = -1;
    vars->player.y = -1;
    vars->map.exit_x = -1;
    vars->map.exit_y = -1;
    vars->map.map = NULL;
    if(check_map(vars, argv) != 1) 
    {
        free(vars);
        return (0);
    }
    
    vars->mlx = mlx_init();
    vars->win = mlx_new_window(vars->mlx, vars->map.width * 64, vars->map.height * 64, "So_Long");
    init_sprites(vars);
    vars->player.moves = 0;
    draw_map(vars, argv);
    mlx_key_hook(vars->win, key_hook, vars);
    mlx_hook(vars->win, 17, 0L, close_window, vars);
    mlx_loop(vars->mlx);
    return (0);
}
/*
int	game_loop(char **argv)
{
	t_game	vars;

	//vars = malloc(sizeof(t_game));
	//if (!vars)
	//	return (1);
	if (check_map(&vars, argv) != 1)
	{
		//free(vars);
		return (0);
	}
	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, vars.map.width * 64, vars.map.height
			* 64, "So_Long");
	init_sprites(&vars);
	vars.player.moves = 0;
	draw_map(&vars, argv);
	mlx_key_hook(&vars.win, key_hook, &vars);
	mlx_hook(&vars.win, 17, 0L, close_window, &vars);
	mlx_loop(&vars.mlx);
	return (0);
}*/