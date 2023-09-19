/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ereinald <ereinald@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 12:14:26 by ereinald          #+#    #+#             */
/*   Updated: 2023/09/11 12:52:14 by ereinald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_game_loop(t_game *game)
{
    ft_draw_map(game);
    return (0);
}

int	ft_close(t_game *game)
{
    mlx_destroy_window(game->mlx, game->win);
    exit(0);
    return (0);
}

int	ft_error(char *str)
{
    ft_putstr_fd(str, 2);
    exit(1);
    return (0);
}