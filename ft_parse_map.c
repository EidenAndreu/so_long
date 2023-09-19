/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ereinald <ereinald@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 12:27:49 by ereinald          #+#    #+#             */
/*   Updated: 2023/09/11 13:08:25 by ereinald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


int	ft_parse_map(int fd, t_game *game)
{
    int	ret;
    int	i;
    char	*line;

    game->map = malloc(sizeof(int *) * game->map_height);
    if (!game->map)
        ft_error("Error\nMalloc failed\n");
    i = 0;
    while (i < game->map_height)
    {
        game->map[i] = malloc(sizeof(int) * game->map_width);
        if (!game->map[i])
            ft_error("Error\nMalloc failed\n");
        i++;
    }
    i = 0;
    while (ret)
    {
        ret = get_next_line(fd, &line);
        if (ret == -1)
            ft_error("Error\nInvalid map\n");
        ft_parse_map_line(line, game, i);
        i++;
    }
    return (0);
}

int	ft_parse_map_line(char *line, t_game *game, int i)
{
    int	j;

    j = 0;
    while (j < game->map_width)
    {
        game->map[i][j] = line[j];
        if (line[j] == 'P')
        {
            game->player_x = j;
            game->player_y = i;
        }
        if (line[j] == 'C')
            game->collectible++;
        if (line[j] == 'E')
            game->exit++;
        if (line[j] == 'M')
            game->enemy++;
        j++;
    }
    return (0);
}
