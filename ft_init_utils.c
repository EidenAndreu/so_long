/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ereinald <ereinald@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 12:21:45 by ereinald          #+#    #+#             */
/*   Updated: 2023/09/11 12:22:08 by ereinald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_init_player(t_game *game)
{
    game->player_x = 0;
    game->player_y = 0;
}

void	ft_init_collectible(t_game *game)
{
    game->collectible = 0;
}

void	ft_init_exit(t_game *game)
{
    game->exit = 0;
}

void	ft_init_enemy(t_game *game)
{
    game->enemy = 0;
}