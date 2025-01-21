/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyhook.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkiloul <lkiloul@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 20:47:51 by lkiloul           #+#    #+#             */
/*   Updated: 2025/01/21 02:16:43 by lkiloul          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int key_hook(int keycode, t_game *vars)
{
    printf("Keycode : %d\n", keycode);
    if (keycode == 65307) // 65307 corresponds to the ESC key
        close_window(vars);
    return (0);
}