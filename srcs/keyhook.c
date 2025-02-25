/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyhook.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkiloul <lkiloul@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 20:47:51 by lkiloul           #+#    #+#             */
/*   Updated: 2025/02/25 19:18:11 by lkiloul          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_player(t_game *vars, int keycode)
{
	if (keycode == KEY_W)
	{
		vars->player.y--;
		vars->player.moves++;
		draw_background(vars, vars->player.x, vars->player.y + 1);
	}
	if (keycode == KEY_S)
	{
		vars->player.y++;
		vars->player.moves++;
		draw_background(vars, vars->player.x, vars->player.y - 1);
	}
	if (keycode == KEY_A)
	{
		vars->player.x--;
		vars->player.moves++;
		draw_background(vars, vars->player.x + 1, vars->player.y);
	}
	if (keycode == KEY_D)
	{
		vars->player.x++;
		vars->player.moves++;
		draw_background(vars, vars->player.x - 1, vars->player.y);
	}
	draw_player(vars, vars->player.x, vars->player.y);
}

void	check_place(t_game *vars, int x, int y, int keycode)
{
	if (vars->map.map[y][x] != '1')
	{
		move_player(vars, keycode);
		ft_printf("Moves: %d\n", vars->player.moves);
	}
	if (vars->map.map[vars->player.y][vars->player.x] == 'C')
	{
		vars->map.collectibles--;
		vars->map.map[vars->player.y][vars->player.x] = '0';
		if (vars->map.collectibles == 0)
		{
			draw_exit(vars, vars->map.exit_x, vars->map.exit_y);
		}
	}
	if (vars->map.map[vars->player.y][vars->player.x] == 'E')
	{
		if (vars->map.collectibles == 0)
		{
			close_window(vars);
		}
	}
	display_moves(vars);
}

void	moves(int keycode, t_game *vars)
{
	if (keycode == KEY_W)
	{
		check_place(vars, vars->player.x, vars->player.y - 1, keycode);
	}
	if (keycode == KEY_S)
	{
		check_place(vars, vars->player.x, vars->player.y + 1, keycode);
	}
	if (keycode == KEY_A)
	{
		check_place(vars, vars->player.x - 1, vars->player.y, keycode);
	}
	if (keycode == KEY_D)
	{
		check_place(vars, vars->player.x + 1, vars->player.y, keycode);
	}
}

int	key_hook(int keycode, t_game *vars)
{
	if (keycode == KEY_ESC)
		close_window(vars);
	if (keycode == KEY_W || keycode == KEY_A || keycode == KEY_S
		|| keycode == KEY_D)
		moves(keycode, vars);
	return (0);
}
