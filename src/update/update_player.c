/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_player.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: napark <napark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/24 01:58:30 by napark            #+#    #+#             */
/*   Updated: 2021/04/24 01:58:59 by napark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cube3d.h>

void    update_player(t_cube3d *s)
{
    int     turn_dir;
    t_ivec  walk_dir;
    t_vec   turn_vec;
    t_vec   new_position;

    turn_dir = s->key.left ? -1 : 0;
    turn_dir += s->key.right ? 1 : 0;
    walk_dir.y = s->key.w ? 1 : 0;
    walk_dir.y += s->key.s ? -1 : 0;
    walk_dir.x = s->key.a ? -1 : 0;
    walk_dir.x += s->key.d ? 1 : 0;
    s->player_direction = rot_vec(s->player_direction, turn_dir * TURN_S * M_PI_180);
    s->plane_vector = rot_vec(s->plane_vector, turn_dir * TURN_S * M_PI_180);
    turn_vec = rot_vec(s->player_direction, 90 * M_PI_180);

    if (walk_dir.x != 0 || walk_dir.y != 0)
    {
        new_position.x = s->player_position.x + s->player_direction.x * (walk_dir.y * WALK_S);
        new_position.y = s->player_position.y + s->player_direction.y * (walk_dir.y * WALK_S);
        new_position.x += turn_vec.x * (walk_dir.x * WALK_S);
        new_position.y += turn_vec.y * (walk_dir.x * WALK_S);
        if (s->map.data[(int)s->player_position.y][(int)new_position.x] != '1')
            s->player_position.x = new_position.x;
        if (s->map.data[(int)new_position.y][(int)s->player_position.x] != '1')
            s->player_position.y = new_position.y;
    }
}