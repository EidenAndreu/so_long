/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_map_others.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ereinald <ereinald@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 20:39:19 by ereinald          #+#    #+#             */
/*   Updated: 2023/09/19 20:43:04 by ereinald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_check_map_player(char *map)
{
    int	fd;
    int	ret;
    int	i;
    int	j;
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
        if (line[i] != '1' && line[i] != 'P')
            ft_error("Error\nInvalid map\n");
        i++;
    }
    j = 0;
    while (ret)
    {
        ret = get_next_line(fd, &line);
        if (ret == -1)
            ft_error("Error\nInvalid map\n");
        i = 0;
        while (line[i])
        {
            if (line[i] != '1' && line[i] != 'P')
                ft_error("Error\nInvalid map\n");
            i++;
        }
        j++;
    }
    close(fd);
    return (0);
}

int	ft_check_map_collectible(char *map)
{
    int	fd;
    int	ret;
    int	i;
    int	j;
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
        if (line[i] != '1' && line[i] != 'C')
            ft_error("Error\nInvalid map\n");
        i++;
    }
    j = 0;
    while (ret)
    {
        ret = get_next_line(fd, &line);
        if (ret == -1)
            ft_error("Error\nInvalid map\n");
        i = 0;
        while (line[i])
        {
            if (line[i] != '1' && line[i] != 'C')
                ft_error("Error\nInvalid map\n");
            i++;
        }
        j++;
    }
    close(fd);
    return (0);
}

int	ft_check_map_exit(char *map)
{
    int	fd;
    int	ret;
    int	i;
    int	j;
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
        if (line[i] != '1' && line[i] != 'E')
            ft_error("Error\nInvalid map\n");
        i++;
    }
    j = 0;
    while (ret)
    {
        ret = get_next_line(fd, &line);
        if (ret == -1)
            ft_error("Error\nInvalid map\n");
        i = 0;
        while (line[i])
        {
            if (line[i] != '1' && line[i] != 'E')
                ft_error("Error\nInvalid map\n");
            i++;
        }
        j++;
    }
    close(fd);
    return (0);
}

int	ft_check_map_enemy(char *map)
{
    int	fd;
    int	ret;
    int	i;
    int	j;
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
        if (line[i] != '1' && line[i] != 'M')
            ft_error("Error\nInvalid map\n");
        i++;
    }
    j = 0;
    while (ret)
    {
        ret = get_next_line(fd, &line);
        if (ret == -1)
            ft_error("Error\nInvalid map\n");
        i = 0;
        while (line[i])
        {
            if (line[i] != '1' && line[i] != 'M')
                ft_error("Error\nInvalid map\n");
            i++;
        }
        j++;
    }
    close(fd);
    return (0);
}

int	ft_check_map_closed(char *map)
{
    int	fd;
    int	ret;
    int	i;
    int	j;
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
    j = 0;
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
        j++;
    }
    close(fd);
    return (0);
}