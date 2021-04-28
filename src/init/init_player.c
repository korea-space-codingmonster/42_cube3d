/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: napark <napark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/24 16:18:39 by napark            #+#    #+#             */
/*   Updated: 2021/04/28 17:15:26 by napark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void	init_player(t_cube3d *s, t_vec pos, int *flag)
{
	if (*flag)
		exit_cub3d_msg(s, "ERROR : already allocate(init_player)");
	s->pos = pos;
	if (s->map.data[(int)pos.y][(int)pos.x] == 'N')
		s->dir = new_vec(0, -1);
	else if (s->map.data[(int)pos.y][(int)pos.x] == 'S')
		s->dir = new_vec(0, 1);
	else if (s->map.data[(int)pos.y][(int)pos.x] == 'W')
		s->dir = new_vec(-1, 0);
	else if (s->map.data[(int)pos.y][(int)pos.x] == 'E')
		s->dir = new_vec(1, 0);
	s->fov = FOV * M_PI_180;
	s->fov_h = s->v.width / 2 / tan(s->fov / 2);
	s->plane = rot_vec(s->dir, 90 * M_PI_180);
	s->plane.x *= tan(s->fov / 2);
	s->plane.y *= tan(s->fov / 2);
	*flag = 1;
}
