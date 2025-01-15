/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkiloul <lkiloul@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 15:34:17 by lkiloul           #+#    #+#             */
/*   Updated: 2025/01/15 16:19:55 by lkiloul          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <stdio.h>
typedef struct s_vars
{
	void	*mlx;
	void	*win;
}			t_vars;

int	close(t_vars *vars)
{		
    mlx_destroy_window(vars->mlx, vars->win);
    mlx_loop_end(vars->mlx);
	return (0);
}

int key_hook(int keycode, t_vars *vars)
{
	printf("Keycode : %d\n", keycode);
	if (keycode == 65307)
		close(vars);
}



int	main(void)
{
	t_vars	vars;

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 1920, 1080, "Hello world!");
	mlx_key_hook(vars.win, key_hook, &vars);
	mlx_hook(vars.win, 17, 0, close, &vars);
	mlx_loop(vars.mlx);
}
