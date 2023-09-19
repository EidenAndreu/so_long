/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_game.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ereinald <ereinald@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 12:20:20 by ereinald          #+#    #+#             */
/*   Updated: 2023/09/11 12:23:01 by ereinald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_init_game(t_game *game)
{
    game->mlx = NULL;
    game->win = NULL;
    game->img = NULL;
    game->addr = NULL;
    game->bits_per_pixel = 0;
    game->line_length = 0;
    game->endian = 0;
    game->width = 0;
    game->height = 0;
    game->map_width = 0;
    game->map_height = 0;
    game->player_x = 0;
    game->player_y = 0;
    game->collectible = 0;
    game->exit = 0;
    game->enemy = 0;
    game->move = 0;
    game->map = NULL;
}

void	ft_init_window(t_game *game)
{
    game->mlx = mlx_init();
    game->win = mlx_new_window(game->mlx, game->width, game->height, "so_long");
}

void	ft_init_image(t_game *game)
{
    game->img = mlx_new_image(game->mlx, game->width, game->height);
    game->addr = mlx_get_data_addr(game->img, &game->bits_per_pixel,
            &game->line_length, &game->endian);
}

void	ft_init_map(t_game *game, char *map)
{
    int	fd;

    fd = open(map, O_RDONLY);
    if (fd == -1)
        ft_error("Error\nInvalid map\n");
    ft_check_map(map, game);
    ft_parse_map(fd, game);
    close(fd);
}

void	ft_init_game_loop(t_game *game)
{
    mlx_hook(game->win, 2, 1L << 0, ft_key_press, game);
    mlx_hook(game->win, 3, 1L << 1, ft_key_release, game);
    mlx_hook(game->win, 17, 1L << 17, ft_close, game);
    mlx_loop_hook(game->mlx, ft_game_loop, game);
    mlx_loop(game->mlx);
}