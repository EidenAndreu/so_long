/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ereinald <ereinald@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 12:11:36 by ereinald          #+#    #+#             */
/*   Updated: 2023/09/11 12:15:40 by ereinald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
    t_game	game;

    if (argc != 2)
        return (ft_error("Error\nUsage: ./so_long [map.ber]\n"));
    ft_init_game(&game);
    if (ft_check_map(argv[1], &game))
        return (ft_error("Error\nInvalid map\n"));
    ft_init_window(&game);
    ft_init_image(&game);
    ft_init_player(&game);
    ft_init_collectible(&game);
    ft_init_exit(&game);
    ft_init_enemy(&game);
    ft_init_map(&game, argv[1]);
    ft_init_game_loop(&game);
    return (0);
}
