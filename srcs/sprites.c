/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkiloul <lkiloul@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 23:54:23 by lkiloul           #+#    #+#             */
/*   Updated: 2025/02/24 20:35:47 by lkiloul          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	init_sprites(t_game *vars)
{
	vars_sprites(vars);
	vars->sprite.background.xpm = mlx_xpm_file_to_image(vars->mlx,
			"assets/ground.xpm", &vars->sprite.background.x,
			&vars->sprite.background.y);
	if (!vars->sprite.background.xpm)
		return (0);
	vars->sprite.wall.xpm = mlx_xpm_file_to_image(vars->mlx, "assets/wall.xpm",
			&vars->sprite.wall.x, &vars->sprite.wall.y);
	if (!vars->sprite.wall.xpm)
		return (0);
	vars->sprite.player.xpm = mlx_xpm_file_to_image(vars->mlx,
			"assets/player.xpm", &vars->sprite.player.x,
			&vars->sprite.player.y);
	if (!vars->sprite.player.xpm)
		return (0);
	vars->sprite.coins.xpm = mlx_xpm_file_to_image(vars->mlx,
			"assets/coins.xpm", &vars->sprite.coins.x, &vars->sprite.coins.y);
	if (!vars->sprite.coins.xpm)
		return (0);
	vars->sprite.exit.xpm = mlx_xpm_file_to_image(vars->mlx, "assets/exit.xpm",
			&vars->sprite.exit.x, &vars->sprite.exit.y);
	if (!vars->sprite.exit.xpm)
		return (0);
	return (1);
}

void	vars_sprites(t_game *vars)
{
	vars->sprite.background.xpm = (void *) NULL;
	vars->sprite.coins.xpm = (void *) NULL;
	vars->sprite.wall.xpm = (void *) NULL;
	vars->sprite.exit.xpm = (void *) NULL;
	vars->sprite.player.xpm = (void *) NULL;
	vars->win = (void *) NULL;
}
