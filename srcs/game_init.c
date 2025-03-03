/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkiloul <lkiloul@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 20:50:42 by lkiloul           #+#    #+#             */
/*   Updated: 2025/03/03 13:11:17 by lkiloul          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	game_loop(char **argv)
{
	t_game	*vars;

	vars = malloc(sizeof(t_game));
	if (!vars)
		return (1);
	vars_init(vars);
	if (check_map(vars, argv) != 1)
	{
		close_window(vars);
		return (0);
	}
	vars->mlx = mlx_init();
	if (init_sprites(vars) == 0)
	{
		close_window(vars);
		return (ft_printf("A sprite cannot be loaded"), 0);
	}
	vars->win = mlx_new_window(vars->mlx, vars->map.width * 64, vars->map.height
			* 64, "So_Long");
	vars->player.moves = 0;
	draw_map(vars, argv);
	mlx_key_hook(vars->win, key_hook, vars);
	mlx_hook(vars->win, 17, 0L, close_window, vars);
	mlx_loop(vars->mlx);
	return (0);
}

void	vars_init(t_game *vars)
{
	vars->map.height = 0;
	vars->map.width = 0;
	vars->map.collectibles = 0;
	vars->player.x = -1;
	vars->player.y = -1;
	vars->player.players = 0;
	vars->map.exit_x = -1;
	vars->map.exit_y = -1;
	vars->map.map = NULL;
	vars->map_copy.exit = 0;
	vars->map.exit = 0;
	vars->mlx = NULL;
	vars->win = NULL;
	vars->map_copy.map = NULL;
	vars->sprite.background.xpm = NULL;
	vars->sprite.wall.xpm = NULL;
	vars->sprite.coins.xpm = NULL;
	vars->sprite.exit.xpm = NULL;
	vars->sprite.player.xpm = NULL;
}
