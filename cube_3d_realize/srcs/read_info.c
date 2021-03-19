/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: napark <napark@studenst.42seoul.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 12:35:34 by napark            #+#    #+#             */
/*   Updated: 2021/03/19 12:22:28 by napark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

void    read_info(t_all *s)
{
    char *line;
    char **info;
    char *flag;

    while (get_next_line(s->fd, &line) > 0)
    {
        if (line[0] == EMPTY_LINE)
            continue;
        info = ft_split(line, ' ');//스페이스가 있을 시 분리하여 info에 초기화
        if (!info)
            ft_strexit("ERROR : Invalid .cub File!");
        flag = decide_store_what_info(s, info);//맵파싱
        ft_free_2d(info);
        if (flag = MAP_COMPLETE)
            break;
        free(line);
    }
    s->line = line;//맵 정보 파싱 후 맵정보까지만
}

int     decide_store_what_info(t_all *s, char **info)//.xpm이 저장된 경로를 저장한다.
{
    if (ft_strcmp(info[0], "R") == 0)
        store_map_size(s, info[1], info[2]);
    else if (ft_strcmp(info[0], "NO") == 0)
        store_location_path(s, info[1], NORTH);
    else if (ft_strcmp(info[0], "SO") == 0)
        store_location_path(s, info[1], SOUTH);
    else if (ft_strcmp(info[1], "WE") == 0)
        store_location_path(s, info[1], WEST);
    else if (ft_strcmp(info[1], "WA") == 0)
        store_location_path(s, info[1], EAST);
    else if (ft_strcmp(info[1], "S") == 0)
        store_location_path(s, info[1], SPRITE);
    else if (ft_strcmp(info[1], "F") == 0)
        store_color(s, info[1], FLOOR);
    else if (ft_strcmp(info[1], "C") == 0)
        store_color(s, info[1], CEILING);
    else
        return MAP_COMPLETE;
    return (0);
}

void    store_map_size(t_all *s, char *width, char *height)
{
    if (!width || !height)
        ft_strexit("ERROR : Empty width height. Please check your .cubs file");
    if (!ft_only_digit(width) && !ft_only_digit(height))
        ft_strexit("ERROR : Either one of them is not a number.");
    s->width = ft_atoi(width);
    s->height = ft_atoi(height);
    s->width = s->width > 1920 ? 1920 : s->width;
    s->width = s->width < 848 ? 848 : s->width;
    s->height = s->height > 1080 ? 1080 : s->height;
    s->height = s->height < 480 ? 480 : s->height;
    
}

void    store_location(t_all *s, char *path, int location)
{
    int     fd;

    if (!path || !ft_isformat(path, ".xpm"))
        ft_strexit("ERROR : Path is empty or path is Invalid format");
    
    fd = open(path, O_RDONLY);
    if (fd == -1)
        ft_strexit("ERROR : File(.xpm) is not exisit");
    s->tex.path[location] = ft_strdup(path);
    close(fd);
}

void    store_color(t_all *s, char *rgb_comma, int flag)
{
    char **rgb;
    int i;
    int hex;
    int temp;

    if (!(rgb = ft_split(rgb_comma, ',')))
        ft_strexit("ERROR : Invalid RGB Syntex!!");

    i = 0;
    hex = 0;
    while (i < 3)
    {
        if (!rgb[i] || !ft_only_digit(rgb[i]))
            ft_strexit("ERROR : RGB empty or Not number");
        temp = ft_atoi(rgb[i]);
        if (temp > 255 || temp < 0)
            ft_strexit("ERROR : RGB over range");
        hex = hex * 256 + temp;
        i++;
    }
    if (flag == FLOOR)
        s->tex.floor = hex;
    else if (flag == CEILING)
        s->tex.floor = hex;
    fd_free_2d(rgb);
}