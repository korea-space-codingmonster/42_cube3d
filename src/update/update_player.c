/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_player.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: napark <napark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/25 02:06:51 by napark            #+#    #+#             */
/*   Updated: 2021/04/28 17:16:12 by napark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void	update_player(t_cube3d *s)
{
	int		turn_dir;
	t_ivec	walk_dir;
	t_vec	turn_vec;
	t_vec	new_pos;

	turn_dir = s->key.left ? -1 : 0;
	turn_dir += s->key.right ? 1 : 0;
	walk_dir.y = s->key.w ? 1 : 0;
	walk_dir.y += s->key.s ? -1 : 0;
	walk_dir.x = s->key.a ? -1 : 0;
	walk_dir.x += s->key.d ? 1 : 0;
	s->dir = rot_vec(s->dir, turn_dir * TURN_S * M_PI_180);
	s->plane = rot_vec(s->plane, turn_dir * TURN_S * M_PI_180);
	turn_vec = rot_vec(s->dir, 90 * M_PI_180);
	if (walk_dir.x != 0 || walk_dir.y != 0)
	{
		new_pos.x = s->pos.x + s->dir.x * (walk_dir.y * WALK_S);
		new_pos.y = s->pos.y + s->dir.y * (walk_dir.y * WALK_S);
		new_pos.x += turn_vec.x * (walk_dir.x * WALK_S);
		new_pos.y += turn_vec.y * (walk_dir.x * WALK_S);
		if (s->map.data[(int)s->pos.y][(int)new_pos.x] != '1')
			s->pos.x = new_pos.x;
		if (s->map.data[(int)new_pos.y][(int)s->pos.x] != '1')
			s->pos.y = new_pos.y;
	}
}
