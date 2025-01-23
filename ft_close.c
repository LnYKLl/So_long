/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_close.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkiloul <lkiloul@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 20:46:08 by lkiloul           #+#    #+#             */
/*   Updated: 2025/01/22 23:03:01 by lkiloul          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	close_window(t_game *vars)
{
    if (vars->mlx && vars->win)
    {
        mlx_destroy_window(vars->mlx, vars->win);
        mlx_loop_end(vars->mlx);
        free(vars);
    }
    return (0);
}