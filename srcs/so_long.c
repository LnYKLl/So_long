/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkiloul <lkiloul@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 15:34:17 by lkiloul           #+#    #+#             */
/*   Updated: 2025/02/03 09:58:34 by lkiloul          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "libft.h"
int	main(int agrc, char **argv)
{
	if (agrc != 2)
	{
		ft_printf("Error : Invalid number of arguments\n");
		return (1);
	}
	game_loop(argv);
	return (0);
}
