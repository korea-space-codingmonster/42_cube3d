/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_sprite.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: napark <napark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/24 04:21:12 by napark            #+#    #+#             */
/*   Updated: 2021/04/24 04:42:12 by napark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cube3d.h>

void    render_sprite_tex(t_cube3d *s, t_sprite *sp, t_ivec size, t_ivec move)
{
    t_ivec  iv;
    t_ivec  tex;
    t_ivec  start;
    t_ivec  end;

    start.x = -size.x / 2 + move.x;
    end.x = size.x / 2 + move.x;
    start.y = -size.y / 2 + s->timg.height / 2;
    end.y = size.y / 2 + s->timg.height / 2;
    normalise_ipos(s, &start);
    normalise_ipos(s, &end);
    iv.x = start.x - 1;
    while (++iv.x < end.x)
    {
        tex.x = ((iv.x - (-size.x / 2 + move.x)) * sp->tex->width / size.x);
        iv.y = (sp->transform.y > 0 && iv.x > 0 && iv.x < s->timg.width && sp->transform.y
                < s->rays[iv.x / WALL_STRIP_WIDTH].dist ? start.y - 1 : end.y);
        while (++iv.y < end.y)
        {
            tex.y = (iv.y - move.y) * 256 - s->timg.height * 128 + size.y * 128;
            tex.y = ((tex.y * sp->tex->height) / size.y) / 256;
            s_color = sp->tex->data[sp->tex->line * tex.y + tex.x];
            (s_color.bit.t !=255 ? put_pixel(&s->timg, iv.x, iv.y) : 0);
        }
    }
}

void    render_sprite(t_cube3d *s)
{
    int     i;
    t_ivec  move;
    t_ivec  size;
    t_sprite    *sp;

    i = -1;
    while (++i < s->num_sp)
    {
        sp = &s->ts[s->sp_order[i]];
        move.x = (int)((s->timg.width / 2) * (1 + sp->transform.x / sp->transform.y));
        move.y = (int)(V_MOVE / sp->transform.y);
        size.x = (int)fabs((s->fov_h / sp->transform.y) / U_DIV);
        size.y = (int)fabs((s->fov_h / sp->transform.y) / V_DIV);
        render_sprite_tex(s, sp, size, move);
    }
}