/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: napark <napark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 16:40:28 by napark            #+#    #+#             */
/*   Updated: 2021/04/24 11:42:30 by napark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cube3d.h>

static void     init_window(t_cube3d *s, int save)
{
    if (!save)
    {
        if (!(s->win = mlx_new_window(s->mlx, s->timg.width, s->timg.height, CUBE3D_TITLE)))
            ft_strexit("ERROR : s, fail mlx_new_window(init_window)");
    }
    if (!(s->timg.ptr = mlx_new_image(s->mlx, s->timg.width, s->timg.height)))
        ft_strexit("ERROR : fail mlx_new_image(init_window)");
    if (!(s->timg.data = (t_color *)mlx_get_data_addr(s->timg.ptr, &s->timg.bpp, &s->timg.size_l, &s->timg.endian)))
        ft_strexit("ERROR : fail mlx_get_data_addr(init_window)");
    s->timg.line = s->timg.size_l / (s->timg.bpp / 8);
} 

void    init(t_cube3d   *s, char *argv, int save)
{
    (!(s->mlx = mlx_init()) ? ft_strexit("ERROR : fail mlx_init()") : 0);
    mlx_get_screen_size(s->mlx, &s->tw.width, &s->tw.height);
    parse(s, argv);
    init_window(s, save);
    s->num_rays = s->timg.width / WALL_STRIP_WIDTH;
    if (!(s->rays = malloc(sizeof(t_rays) * s->num_rays)))
        ft_strexit("ERROR : ray malloc failed(init_window)");
}