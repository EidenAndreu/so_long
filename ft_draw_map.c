/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ereinald <ereinald@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 12:23:36 by ereinald          #+#    #+#             */
/*   Updated: 2023/09/11 12:24:58 by ereinald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


void	ft_draw_map(t_game *game)
{
    int	x;
    int	y;

    y = 0;
    while (y < game->map_height)
    {
        x = 0;
        while (x < game->map_width)
        {
            if (game->map[y][x] == '1')
                ft_draw_wall(game, x, y);
            if (game->map[y][x] == '0')
                ft_draw_floor(game, x, y);
            if (game->map[y][x] == 'C')
                ft_draw_collectible(game, x, y);
            if (game->map[y][x] == 'E')
                ft_draw_exit(game, x, y);
            if (game->map[y][x] == 'P')
                ft_draw_player(game, x, y);
            if (game->map[y][x] == 'M')
                ft_draw_enemy(game, x, y);
            x++;
        }
        y++;
    }
}

void	ft_draw_wall(t_game *game, int x, int y)
{
    int	i;
    int	j;

    i = 0;
    while (i < game->height / game->map_height)
    {
        j = 0;
        while (j < game->width / game->map_width)
        {
            ft_draw_pixel(game, x * (game->width / game->map_width) + j,
                y * (game->height / game->map_height) + i, 0x000000);
            j++;
        }
        i++;
    }
}

void	ft_draw_floor(t_game *game, int x, int y)
{
    int	i;
    int	j;

    i = 0;
    while (i < game->height / game->map_height)
    {
        j = 0;
        while (j < game->width / game->map_width)
        {
            ft_draw_pixel(game, x * (game->width / game->map_width) + j,
                y * (game->height / game->map_height) + i, 0x00FF00);
            j++;
        }
        i++;
    }
}

void	ft_draw_collectible(t_game *game, int x, int y)
{
    int	i;
    int	j;

    i = 0;
    while (i < game->height / game->map_height)
    {
        j = 0;
        while (j < game->width / game->map_width)
        {
            ft_draw_pixel(game, x * (game->width / game->map_width) + j,
                y * (game->height / game->map_height) + i, 0x0000FF);
            j++;
        }
        i++;
    }
}

void	ft_draw_exit(t_game *game, int x, int y)
{
    int	i;
    int	j;

    i = 0;
    while (i < game->height / game->map_height)
    {
        j = 0;
        while (j < game->width / game->map_width)
        {
            ft_draw_pixel(game, x * (game->width / game->map_width) + j,
                y * (game->height / game->map_height) + i, 0xFF0000);
            j++;
        }
        i++;
    }
}