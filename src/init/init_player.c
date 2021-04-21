/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: napark <napark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 01:10:46 by napark            #+#    #+#             */
/*   Updated: 2021/04/22 02:07:48 by napark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cube3d.h>

void    init_player(t_cube3d *s, t_vec  point,  int *flag)
{
    if (*flag)
        ft_strexit("ERROR : Not exist player position(init_player)");
    s->player_position = point;
    if (s->map.data[(int)point.y][(int)point.x] == 'N')
        s->player_direction = new_vec(0, -1);
    else if (s->map.data[(int)point.y][(int)point.x] == 'S')
        s->player_direction = new_vec(0, 1);
    else if (s->map.data[(int)point.y][(int)point.x] == 'W')
        s->player_direction = new_vec(-1, 0);
    else if (s->map.data[(int)point.y][(int)point.x] == 'E')
        s->player_direction = new_vec(1, 0);
    s->fov = FOV * M_PI_180;
    s->fov_h = s->timg.width / 2 / tan(s->fov / 2);
    s->plane_vector = rot_vec(s->player_direction, 90 * M_PI_180);
    s->plane_vector.x = tan(s->fov / 2);
    s->plane_vector.y = tan(s->fov / 2);
    *flag = 1; // 플레이어 위치 산정 완료 flag
}