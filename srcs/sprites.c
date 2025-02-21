/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkiloul <lkiloul@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 23:54:23 by lkiloul           #+#    #+#             */
/*   Updated: 2025/02/21 04:21:36 by lkiloul          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_sprites(t_game *vars)
{
	vars->sprite.background.xpm = mlx_xpm_file_to_image(vars->mlx,
			"assets/ground.xpm", &vars->sprite.background.x,
			&vars->sprite.background.y);
	vars->sprite.wall.xpm = mlx_xpm_file_to_image(vars->mlx, "assets/wall.xpm",
			&vars->sprite.wall.x, &vars->sprite.wall.y);
	vars->sprite.player.xpm = mlx_xpm_file_to_image(vars->mlx,
			"assets/player.xpm", &vars->sprite.player.x,
			&vars->sprite.player.y);
	vars->sprite.coins.xpm = mlx_xpm_file_to_image(vars->mlx,
			"assets/coins.xpm", &vars->sprite.coins.x, &vars->sprite.coins.y);
	vars->sprite.exit.xpm = mlx_xpm_file_to_image(vars->mlx, "assets/exit.xpm",
			&vars->sprite.exit.x, &vars->sprite.exit.y);
}
