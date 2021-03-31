/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: napark <napark@studenst.42seoul.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 22:49:17 by napark            #+#    #+#             */
/*   Updated: 2021/03/31 23:31:33 by napark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

void    init(t_cube3d *s, char *argv, int save)
{
    s->mlx = mlx_init();
    mlx_get_screen_size(s->mlx, &s->tw.width, &s->tw.height);//스크린 사이즈 가져오기
    parse(s, argv);
}

