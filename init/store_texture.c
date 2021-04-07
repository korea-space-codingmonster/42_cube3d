/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store_texture.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: napark <napark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 15:40:16 by napark            #+#    #+#             */
/*   Updated: 2021/04/07 16:46:08 by napark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cube3d.h>

void    init_texture(t_cube3d *s, char *path, char text_direc)
{
    t_img   *img;

    if (((s_parse_check >> text_direc) & 1) == 1)
        ft_strexit("EEROR : Invalid map file or already reload path");
    s_parse_check |= 1 << text_direc;
    img = &s->path[text_direc];

    if (!(img->ptr = mlx_xpm_file_to_image(s->mlx, path, &img->width, &img->height)))
        ft_strexit("ERROR : fail to img load!");
    if (!(img->data = (t_color *)mlx_get_data_addr(img->ptr, &img->bpp, &img->size_l, &img->endian)))
        ft_strexit("ERROR : texture data load error!");
    img->line = img->size_l / (img->bpp / 8);
}