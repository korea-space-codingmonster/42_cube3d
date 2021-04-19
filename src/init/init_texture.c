/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: napark <napark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 16:38:29 by napark            #+#    #+#             */
/*   Updated: 2021/04/19 15:47:45 by napark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cube3d.h>

static int check_map_valid(char *path)
{
    int len;

    len = ft_strlen(path);

    if (path[len-1] == 'm' && path[len - 2] == 'p' && path[len - 3] == 'x')
        return (SUCCESS);
    else
        return (ERROR);
}

void    init_texture(t_cube3d *s, char *path, char direc)
{
    t_img   *img;

    if (!(check_map_valid(path)))
    {
        ft_strexit("ERROR : Invalid file format(check_map_valid)");
    }
    else
    {
        if (((s_parse_check >> direc) & 1) == 1)
            ft_strexit("ERROR : Already stock inforamtion(init_texture)");
        s_parse_check |= 1 << direc;

        img = &s->path[direc];//0, 1, 2, 3 방향의 각각 공간확보
        if (!(img->ptr = mlx_xpm_file_to_image(s->mlx, path, &img->width, &img->height)))
            ft_strexit("ERROR : we can't stock image texture(init_texture)");
        if (!(img->data = (t_color *)mlx_get_data_addr(img->ptr, &img->bpp, &img->size_l, &img->endian)))
            ft_strexit("ERROR : we can't stock image color(init_texture)");
        img->line = img->size_l / (img->bpp / 8);
    }
}