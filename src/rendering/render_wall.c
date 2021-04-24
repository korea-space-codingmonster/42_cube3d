/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_wall.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: napark <napark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/24 03:34:46 by napark            #+#    #+#             */
/*   Updated: 2021/04/24 04:18:33 by napark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cube3d.h>

static void     render_wall_texture(t_cube3d *s, t_rays *ray, t_vec pos, int wall_h)
{
    int y;
    float   step;
    t_ivec  iv;
    t_vec   tex_p;

    tex_p.x = ray->side ? s->player_position.x + ray->dist * ray->dir.x :
            s->player_position.y + ray->dist * ray->dir.y;
    tex_p.x = (int)((tex_p.x - floor(tex_p.x)) * ray->tex->width);
    if ((!ray->side && ray->dir.x < 0) || (ray->side && ray->dir.y > 0))
        tex_p.x = ray->tex->width - tex_p.x - 1;
    step = (float)ray->tex->height - tex_p.x - 1;
    (pos.y < 0 ? (pos.y = 0) : 0);
    tex_p.y = (pos.y - s->timg.height / 2 + wall_h / 2) * step;
    (wall_h > s->timg.height ? (wall_h = s->timg.height - 1) : 0);
    iv.y = 0;
    while (iv.y < wall_h)
    {
        y = ((int)tex_p.y & ray->tex->height - 1);
        s_color = ray->tex->data[y * ray->tex->line + (int)tex_p.x];
        iv.x = 0;
        while (iv.x < WALL_STRIP_WIDTH)
            put_pixel(&s->timg, pos.x + iv.x++, pos.y + iv.y);
        tex_p.y += step;
        iv.y++;
    }
}

void    render_wall(t_cube3d *s)
{
    int i;
    int wall_h;
    t_vec   pos;

    i = -1;
    while (++i < s->num_rays)
    {
        wall_h = s->fov_h / s->rays[i].dist;
        pos.x = i * WALL_STRIP_WIDTH;
        pos.y = s->timg.height / 2 - wall_h / 2;
        render_wall_texture(s, &s->rays[i], pos, wall_h);
    }
}