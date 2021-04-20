/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: napark <napark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 19:12:42 by napark            #+#    #+#             */
/*   Updated: 2021/04/20 20:03:11 by napark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cube3d.h>

void    init_player(t_cube3d *s, t_vec point, int *flag)
{
    if (*flag)
        ft_strexit("ERROR : Invalid map file");
    s->position = point;
    if (s->map.data[(int)point.y][(int)point.x] == 'N')
        s->dir = new_vec(0, -1);
    else if (s->map.data[(int)point.y][(int)point.x] == 'S')
        s->dir = new_vec(0, 1);
    else if (s->map.data[(int)point.y][(int)point.x] == 'W')
        s->dir = new_vec(-1, 0);
    else if (s->map.data[(int)point.y][(int)point.x] == 'E')
        s->dir = new_dir(1, 0);
    
}