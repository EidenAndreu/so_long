/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_keys.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ereinald <ereinald@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 12:33:50 by ereinald          #+#    #+#             */
/*   Updated: 2023/09/11 12:54:18 by ereinald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_key_press(int keycode, t_game *game)
{
    if (keycode == KEY_W)
        game->player_y -= 1;
    if (keycode == KEY_S)
        game->player_y += 1;
    if (keycode == KEY_A)
        game->player_x -= 1;
    if (keycode == KEY_D)
        game->player_x += 1;
    if (keycode == KEY_ESC)
        ft_close(game);
    return (0);
}

int	ft_key_release(int keycode, t_game *game)
{
    if (keycode == KEY_W)
        game->player_y -= 1;
    if (keycode == KEY_S)
        game->player_y += 1;
    if (keycode == KEY_A)
        game->player_x -= 1;
    if (keycode == KEY_D)
        game->player_x += 1;
    return (0);
}
