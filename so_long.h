/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ereinald <ereinald@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 12:11:48 by ereinald          #+#    #+#             */
/*   Updated: 2023/09/19 20:37:02 by ereinald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "get_next_line/get_next_line.h"
#include "Libft/libft.h"
#include "minilibx-linux/mlx.h"

#define KEY_W 119
#define KEY_S 115
#define KEY_A 97
#define KEY_D 100
#define KEY_ESC 27

typedef struct s_game
{
    void	*mlx;
    void	*win;
    void	*img;
    char	*addr;
    int		bits_per_pixel;
    int		line_length;
    int		endian;
    int		width;
    int		height;
    int		map_width;
    int		map_height;
    int		player_x;
    int		player_y;
    int		collectible;
    int		exit;
    int		enemy;
    int		move;
    int		**map;
}	t_game;

int    ft_game_loop(t_game *game);
int    ft_close(t_game *game);
int    ft_error(char *str);
int    ft_check_map(char *map);
int    ft_check_map_player(char *map);
int    ft_check_map_collectible(char *map);
int    ft_check_map_exit(char *map);
int    ft_check_map_enemy(char *map);
int    ft_check_map_others(char *map);
int    ft_check_map_size(char *map);
int    ft_check_map_wall(char *map);
int    ft_check_map_line(char *map);

int    ft_draw_map(t_game *game);
void    ft_draw_wall(t_game *game, int x, int y);
void    ft_draw_floor(t_game *game, int x, int y);
void    ft_draw_collectible(t_game *game, int x, int y);
void    ft_draw_exit(t_game *game, int x, int y);
void    ft_draw_player(t_game *game, int x, int y);
void    ft_draw_enemy(t_game *game, int x, int y);
void    ft_draw_move(t_game *game);
void    ft_draw_pixel(t_game *game, int x, int y, int color);

int    ft_key_press(int keycode, t_game *game);
int    ft_key_release(int keycode, t_game *game);

#endif