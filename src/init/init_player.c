/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: napark <napark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/23 16:54:56 by napark            #+#    #+#             */
/*   Updated: 2021/04/23 17:29:00 by napark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cube3d.h>

void    init_player(t_cube3d *s, t_vec position, int *flag)
{
    if (*flag)
        ft_strexit("ERROR : Invalide map format(init_player)");
    s->player_position = position;
    if (s->map.data[(int)position.y][(int)position.x] == 'N')
        s->player_direction = new_vec(0, -1);
    else if (s->map.data[(int)position.y][(int)position.x] == 'S')
        s->player_direction = new_vec(0, 1);
    else if (s->map.data[(int)position.y][(int)position.x] == 'W')
        s->player_direction = new_vec(-1, 0);
    else if (s->map.data[(int)position.y][(int)position.x] == 'E')
        s->player_direction = new_vec(1, 0);
    s->fov = FOV * M_PI_180;
    s->fov_h = s->timg.width / 2 / tan(s->fov / 2);
    s->plane_vector = rot_vec(s->player_direction, 90 * M_PI_180);
    s->plane_vector.x *= tan(s->fov / 2);
    s->plane_vector.y *= tan(s->fov / 2);
    *flag = 1;
}