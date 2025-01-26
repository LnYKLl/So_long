/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkiloul <lkiloul@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 23:54:23 by lkiloul           #+#    #+#             */
/*   Updated: 2025/01/25 23:58:17 by lkiloul          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_sprites(t_game *vars)
{
	vars->background.xpm = mlx_xpm_file_to_image(vars->mlx, "assets/ground.xpm",
			&vars->background.x, &vars->background.y);
	vars->wall.xpm = mlx_xpm_file_to_image(vars->mlx, "assets/wall.xpm",
			&vars->wall.x, &vars->wall.y);
	vars->player.img.xpm = mlx_xpm_file_to_image(vars->mlx, "assets/player.xpm",
			&vars->player.img.x, &vars->player.img.y);
	vars->coins.xpm = mlx_xpm_file_to_image(vars->mlx, "assets/coins.xpm",
			&vars->coins.x, &vars->coins.y);
	vars->exit.xpm = mlx_xpm_file_to_image(vars->mlx, "assets/exit.xpm",
			&vars->exit.x, &vars->exit.y);
}
