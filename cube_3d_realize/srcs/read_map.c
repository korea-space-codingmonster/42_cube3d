/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: napark <napark@studenst.42seoul.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 12:35:34 by napark            #+#    #+#             */
/*   Updated: 2021/03/16 14:42:29 by napark           ###   ########.fr       */
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
        
}

void    store_map_size(t_all *s, char *width, char *height)
{
    if (!width || !height)
        ft_strexit("ERROR : Empty width height. Please check your cubs file");
}