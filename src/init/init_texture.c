/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: napark <napark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/24 16:13:34 by napark            #+#    #+#             */
/*   Updated: 2021/04/28 17:15:24 by napark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void	init_texture(t_cube3d *s, char *path, int tex_i)
{
	t_img	*img;

	if (((g_parse_check >> tex_i) & 1) == 1)
		exit_cub3d_msg(s, "ERROR : already parsing texture(init_texture)");
	g_parse_check |= 1 << tex_i;
	img = &s->tex[tex_i];
	if (!(img->ptr = \
		mlx_xpm_file_to_image(s->mlx, path, &img->width, &img->height)))
		exit_cub3d_msg(s, "ERROR : mlx_xpm_file_to_image(init_texture)");
	if (!(img->data = (t_color *)mlx_get_data_addr(\
			img->ptr, &img->bpp, &img->size_l, &img->endian)))
		exit_cub3d_msg(s, "ERROR : mlx_get_data_addr(init_texture)");
	img->line = img->size_l / (img->bpp / 8);
}
