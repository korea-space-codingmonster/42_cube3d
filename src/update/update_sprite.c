/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_sprite.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: napark <napark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/24 02:26:34 by napark            #+#    #+#             */
/*   Updated: 2021/04/24 11:26:50 by napark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cube3d.h>

static  void    sort_sprite(t_cube3d *s)
{
    int     temp_o;
    float   temp_d;
    float   max;
    t_ivec  iv;

    iv.x = 0;
    while (iv.x < s->num_sp - 1)
    {
        max = s->sp_dist[iv.x];
        iv.y = iv.x;
        while (++iv.y < s->num_sp)
        {
            if (max < s->sp_dist[iv.y] && (max = s->sp_dist[iv.y]))
            {
                temp_o = s->sp_order[iv.x];
                s->sp_order[iv.x] = s->sp_order[iv.y];
                s->sp_order[iv.y] = temp_o;
                temp_d = s->sp_dist[iv.x];
                s->sp_dist[iv.x] = s->sp_dist[iv.y];
                s->sp_dist[iv.y] = temp_d;
            }
        }
    }
}

void    update_sprite(t_cube3d *s)
{
    int         i;
    float       inv_det;
    t_vec       sprite;
    t_sprite    *sp;

    i = 0;
    while (i < s->num_sp)
    {
        s->sp_order[i] = i;
        s->sp_dist[i] = (s->player_position.x - s->ts[i].position.x) * (s->player_position.x - s->ts[i].position.x)
                    + (s->player_position.y - s->ts[i].position.y) * (s->player_position.y - s->ts[i].position.y);
        i++;
    }
    ((i = -1) == -1 ? sort_sprite(s) : 0);
    while (++i < s->num_sp)
    {
        sp = &s->ts[s->sp_order[i]];
        sprite.x = sp->position.x - s->player_position.x;
        sprite.y = sp->position.y - s->player_position.y;
        inv_det = 1.0 / (s->plane_vector.x * s->player_direction.y - s->player_direction.x * s->plane_vector.y);
        sp->transform.x = inv_det *
                        (s->player_direction.y * sprite.x - s->player_direction.x * sprite.y);
        sp->transform.y = inv_det *
                        (-s->plane_vector.y * sprite.x + s->plane_vector.x * sprite.y);
    }
}