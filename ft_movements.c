/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_movements.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ereinald <ereinald@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 12:33:09 by ereinald          #+#    #+#             */
/*   Updated: 2023/09/11 12:33:33 by ereinald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_move_player(t_game *game, int x, int y)
{
    if (game->map[game->player_y + y][game->player_x + x] == '1')
        return (0);
    if (game->map[game->player_y + y][game->player_x + x] == 'C')
    {
        game->map[game->player_y + y][game->player_x + x] = '0';
        game->collectible--;
    }
    if (game->map[game->player_y + y][game->player_x + x] == 'E')
    {
        if (game->collectible == 0)
            ft_close(game);
        return (0);
    }
    if (game->map[game->player_y + y][game->player_x + x] == 'M')
        ft_close(game);
    game->map[game->player_y][game->player_x] = '0';
    game->player_x += x;
    game->player_y += y;
    game->map[game->player_y][game->player_x] = 'P';
    game->move++;
    return (0);
}

int	ft_move_enemy(t_game *game, int x, int y)
{
    if (game->map[game->player_y + y][game->player_x + x] == '1')
        return (0);
    if (game->map[game->player_y + y][game->player_x + x] == 'C')
    {
        game->map[game->player_y + y][game->player_x + x] = '0';
        game->collectible--;
    }
    if (game->map[game->player_y + y][game->player_x + x] == 'E')
    {
        if (game->collectible == 0)
            ft_close(game);
        return (0);
    }
    if (game->map[game->player_y + y][game->player_x + x] == 'M')
        ft_close(game);
    game->map[game->player_y][game->player_x] = '0';
    game->player_x += x;
    game->player_y += y;
    game->map[game->player_y][game->player_x] = 'P';
    game->move++;
    return (0);
}

int	ft_move(t_game *game)
{
    if (game->player_x < game->map_width - 1)
        ft_move_enemy(game, 1, 0);
    else
        ft_move_enemy(game, -1, 0);
    return (0);
}