/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ereinald <ereinald@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 12:25:26 by ereinald          #+#    #+#             */
/*   Updated: 2023/09/11 12:25:41 by ereinald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_draw_player(t_game *game, int x, int y)
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
                y * (game->height / game->map_height) + i, 0xFFFF00);
            j++;
        }
        i++;
    }
}

void	ft_draw_enemy(t_game *game, int x, int y)
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
                y * (game->height / game->map_height) + i, 0x00FFFF);
            j++;
        }
        i++;
    }
}

void	ft_draw_move(t_game *game)
{
    char	*str;

    str = ft_itoa(game->move);
    mlx_string_put(game->mlx, game->win, 10, 10, 0xFFFFFF, str);
    free(str);
}

void	ft_draw_pixel(t_game *game, int x, int y, int color)
{
    char	*dst;

    dst = game->addr + (y * game->line_length + x * (game->bits_per_pixel / 8));
    *(unsigned int *)dst = color;
}

void	ft_draw_game(t_game *game)
{
    mlx_put_image_to_window(game->mlx, game->win, game->img, 0, 0);
}
