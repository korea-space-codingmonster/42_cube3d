/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_sprite.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: napark <napark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/25 02:11:19 by napark            #+#    #+#             */
/*   Updated: 2021/04/28 17:16:15 by napark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

static void	sort_sprite(t_cube3d *s)
{
	int			tmp_o;
	float		tmp_d;
	float		max;
	t_ivec		iv;

	iv.x = -1;
	while (++iv.x < s->num_sp - 1)
	{
		max = s->sp_dist[iv.x];
		iv.y = iv.x;
		while (++iv.y < s->num_sp)
		{
			if (max < s->sp_dist[iv.y] && (max = s->sp_dist[iv.y]))
			{
				tmp_o = s->sp_order[iv.x];
				s->sp_order[iv.x] = s->sp_order[iv.y];
				s->sp_order[iv.y] = tmp_o;
				tmp_d = s->sp_dist[iv.x];
				s->sp_dist[iv.x] = s->sp_dist[iv.y];
				s->sp_dist[iv.y] = tmp_d;
			}
		}
	}
}

void		update_sprite(t_cube3d *s)
{
	int			i;
	float		inv_det;
	t_vec		sprite;
	t_sprite	*sp;

	i = -1;
	while (++i < s->num_sp)
	{
		s->sp_order[i] = i;
		s->sp_dist[i] = \
			(s->pos.x - s->sp[i].pos.x) * (s->pos.x - s->sp[i].pos.x)
			+ (s->pos.y - s->sp[i].pos.y) * (s->pos.y - s->sp[i].pos.y);
	}
	((i = -1) == -1 ? sort_sprite(s) : 0);
	while (++i < s->num_sp)
	{
		sp = &s->sp[s->sp_order[i]];
		sprite.x = sp->pos.x - s->pos.x;
		sprite.y = sp->pos.y - s->pos.y;
		inv_det = 1.0 / (s->plane.x * s->dir.y - s->dir.x * s->plane.y);
		sp->trans.x = inv_det *
			(s->dir.y * sprite.x - s->dir.x * sprite.y);
		sp->trans.y = inv_det *
			(-s->plane.y * sprite.x + s->plane.x * sprite.y);
	}
}
