/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: napark <napark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/24 15:31:32 by napark            #+#    #+#             */
/*   Updated: 2021/04/28 17:15:23 by napark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

static void	init_window(t_cube3d *s, int flag)
{
	if (!flag)
	{
		if (!(s->win =
			mlx_new_window(s->mlx, s->v.width, s->v.height, CUBE3D_TITLE)))
			exit_cub3d_msg(s, "ERROR : mlx_new_window(init_window)");
	}
	if (!(s->v.ptr = mlx_new_image(s->mlx, s->v.width, s->v.height)))
		exit_cub3d_msg(s, "ERROR : mlx_new_image(init_window)");
	if (!(s->v.data = (t_color *)mlx_get_data_addr(
		s->v.ptr, &s->v.bpp, &s->v.size_l, &s->v.endian)))
		exit_cub3d_msg(s, "ERROR : mlx_get_data_addr(init_window)");
	s->v.line = s->v.size_l / (s->v.bpp / 8);
}

void		init(t_cube3d *s, char *path, int flag)
{
	(!(s->mlx = mlx_init()) ? exit_cub3d_msg(s, "ERROR : mlx_init(init)") : 0);
	mlx_get_screen_size(s->mlx, &s->v.width, &s->v.height);
	init_parse(s, path);
	init_window(s, flag);
	s->num_rays = s->v.width / WALL_STRIP_WIDTH;
	if (!(s->rays = malloc(sizeof(t_ray) * s->num_rays)))
		exit_cub3d_msg(s, "ERROR : allocate memory malloc fail(init)");
}
