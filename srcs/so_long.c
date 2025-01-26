/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkiloul <lkiloul@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 15:34:17 by lkiloul           #+#    #+#             */
/*   Updated: 2025/01/25 23:53:26 by lkiloul          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int agrc, char **argv)
{
	if (agrc != 2)
	{
		printf("Error in the arg\n");
		return (1);
	}
	game_loop(argv);
	return (0);
}
