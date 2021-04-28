/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_wall.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: napark <napark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/25 02:34:41 by napark            #+#    #+#             */
/*   Updated: 2021/04/28 17:15:58 by napark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

static void	render_wall_texture(t_cube3d *s, t_ray *ray, t_vec pos, int wall_h)
{
	int		y;
	t_ivec	iv;
	float	step;
	t_vec	tex_p;

	tex_p.x = ray->side ? s->pos.x + ray->dist * ray->dir.x :
		s->pos.y + ray->dist * ray->dir.y;
	tex_p.x = (int)((tex_p.x - floor(tex_p.x)) * ray->tex->width);
	if ((!ray->side && ray->dir.x < 0) || (ray->side && ray->dir.y > 0))
		tex_p.x = ray->tex->width - tex_p.x - 1;
	step = (float)ray->tex->height / wall_h;
	(pos.y < 0 ? (pos.y = 0) : 0);
	tex_p.y = (pos.y - s->v.height / 2 + wall_h / 2) * step;
	(wall_h > s->v.height ? (wall_h = s->v.height - 1) : 0);
	iv.y = 0;
	while (iv.y < wall_h)
	{
		y = ((int)tex_p.y & ray->tex->height - 1);
		g_color = ray->tex->data[y * ray->tex->line + (int)tex_p.x];
		iv.x = 0;
		while (iv.x < WALL_STRIP_WIDTH)
			put_pixel(&s->v, pos.x + iv.x++, pos.y + iv.y);
		tex_p.y += step;
		iv.y++;
	}
}

void		render_wall(t_cube3d *s)
{
	int		i;
	int		wall_h;
	t_vec	pos;

	i = -1;
	while (++i < s->num_rays)
	{
		wall_h = s->fov_h / s->rays[i].dist;
		pos.x = i * WALL_STRIP_WIDTH;
		pos.y = s->v.height / 2 - wall_h / 2;
		render_wall_texture(s, &s->rays[i], pos, wall_h);
	}
}
