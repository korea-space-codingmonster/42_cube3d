/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: napark <napark@studenst.42seoul.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 12:35:34 by napark            #+#    #+#             */
/*   Updated: 2021/03/16 16:08:13 by napark           ###   ########.fr       */
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
        flag = decide_what_info(s, info);
            
    }
}

int     decide_store_what_info(t_all *s, char **info)
{
    if (ft_strcmp(info[0], "R") == 0)
        store_map_size(s, info[1], info[2]);
    else if (ft_strcmp(info[0], "NO") == 0)
        store_location_path(s, info[1], NORTH);
    else if (ft_strcmp(info[0], "SO") == 0)
        store_location_path(s, info[1], SOUTH);
        
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