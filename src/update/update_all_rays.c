/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_all_rays.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: napark <napark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/24 01:59:51 by napark            #+#    #+#             */
/*   Updated: 2021/04/24 02:26:49 by napark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cube3d.h>

static  void    cast_ray(t_cube3d *s, t_rays *ray)
{
    t_vec   side_d;
    t_vec   delta_d;
    t_ivec  step;
    int     hit;

    delta_d.x = fabsf(1 / ray->dir.x);
    delta_d.y = fabsf(1 / ray->dir.y);
    step = new_ivec(ray->dir.x < 0 ? -1 : 1, ray->dir.y < 0 ? -1 : 1);
    side_d.x = ray->dir.x < 0 ? (s->player_position.x - ray->map.x) * delta_d.x :
                        (ray->map.x + 1.0 - s->player_position.x) * delta_d.x;
    side_d.y = ray->dir.y < 0 ? (s->player_position.y - ray->map.y) * delta_d.y :
                        (ray->map.y + 1.0 - s->player_position.y) * delta_d.y;
    hit = 0;
    while (!hit)
    {
        if (side_d.x < side_d.y && !(ray->side = 0))
            ((side_d.x += delta_d.x) || 1 ? (ray->map.x += step.x) : 0);
        else if ((ray->side = 1))
            ((side_d.y += delta_d.y) || 1 ? (ray->map.y += step.y) : 0);
        (s->map.data[ray->map.y][ray->map.x] == '1' ? hit = 1 : 0);
    }
    ray->dist = (ray->side ?
            (ray->map.y - s->player_position.y + (1 - step.y) / 2) / ray->dir.y :
            (ray->map.x - s->player_position.x + (1 - step.x) / 2) / ray->dir.x);
}

void        update_all_rays(t_cube3d *s)
{
    int i;
    int tex_i;
    float   camera_x;

    i = -1;
    while (++i < s->num_rays)
    {
        camera_x = 2 * (i * WALL_STRIP_WIDTH) / (float)s->timg.width - 1;
        ft_memset(&s->rays[i], 0, sizeof(t_rays));
        s->rays[i].dir.x = s->player_direction.x + s->plane_vector.x + camera_x;
        s->rays[i].dir.y = s->player_direction.y + s->plane_vector.y * camera_x;
        s->rays[i].map = new_ivec(s->player_position.x, s->player_position.y);
        cast_ray(s, &s->rays[i]);
        if (s->rays[i].side)
            tex_i = s->rays[i].dir.y < 0 ? NO : SO;
        else
            tex_i = s->rays[i].dir.x < 0 ? EA : WE;
        s->rays[i].tex = &s->path[tex_i];
    }
}