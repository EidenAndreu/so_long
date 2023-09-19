/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_map_structure.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ereinald <ereinald@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 12:26:06 by ereinald          #+#    #+#             */
/*   Updated: 2023/09/11 13:08:25 by ereinald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_check_map(char *map, t_game *game)
{
    int	fd;
    int	ret;
    int	i;
    char	*line;

    fd = open(map, O_RDONLY);
    if (fd == -1)
        ft_error("Error\nInvalid map\n");
    ret = get_next_line(fd, &line);
    if (ret == -1)
        ft_error("Error\nInvalid map\n");
    game->map_width = ft_strlen(line);
    i = 0;
    while (ret)
    {
        ret = get_next_line(fd, &line);
        if (ret == -1)
            ft_error("Error\nInvalid map\n");
        if (game->map_width != ft_strlen(line))
            ft_error("Error\nInvalid map\n");
        i++;
    }
    game->map_height = i;
    close(fd);
    return (0);
}

int	ft_check_map_wall(char *map)
{
    int	fd;
    int	ret;
    int	i;
    char	*line;

    fd = open(map, O_RDONLY);
    if (fd == -1)
        ft_error("Error\nInvalid map\n");
    ret = get_next_line(fd, &line);
    if (ret == -1)
        ft_error("Error\nInvalid map\n");
    i = 0;
    while (line[i])
    {
        if (line[i] != '1')
            ft_error("Error\nInvalid map\n");
        i++;
    }
    while (ret)
    {
        ret = get_next_line(fd, &line);
        if (ret == -1)
            ft_error("Error\nInvalid map\n");
        i = 0;
        while (line[i])
        {
            if (line[i] != '1')
                ft_error("Error\nInvalid map\n");
            i++;
        }
    }
    close(fd);
    return (0);
}

int	ft_check_map_char(char *map)
{
    int	fd;
    int	ret;
    char	*line;

    fd = open(map, O_RDONLY);
    if (fd == -1)
        ft_error("Error\nInvalid map\n");
    ret = get_next_line(fd, &line);
    if (ret == -1)
        ft_error("Error\nInvalid map\n");
    while (ret)
    {
        if (ft_check_map_line(line))
            ft_error("Error\nInvalid map\n");
        ret = get_next_line(fd, &line);
        if (ret == -1)
            ft_error("Error\nInvalid map\n");
    }
    close(fd);
    return (0);
}

int	ft_check_map_size(char *map)
{
    int	fd;
    int	ret;
    int	i;
    char	*line;

    fd = open(map, O_RDONLY);
    if (fd == -1)
        ft_error("Error\nInvalid map\n");
    ret = get_next_line(fd, &line);
    if (ret == -1)
        ft_error("Error\nInvalid map\n");
    i = ft_strlen(line);
    while (ret)
    {
        if (i != ft_strlen(line))
            ft_error("Error\nInvalid map\n");
        ret = get_next_line(fd, &line);
        if (ret == -1)
            ft_error("Error\nInvalid map\n");
    }
    close(fd);
    return (0);
}

int	ft_check_map_line(char *line)
{
    int	i;

    i = 0;
    while (line[i])
    {
        if (line[i] != '0' && line[i] != '1' && line[i] != 'C'
            && line[i] != 'E' && line[i] != 'P' && line[i] != 'M')
            return (1);
        i++;
    }
    return (0);
}