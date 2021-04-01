/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: napark <napark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 22:49:17 by napark            #+#    #+#             */
/*   Updated: 2021/04/01 17:42:09 by napark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

t_uc    s_parse_check = 0;//1바이트 공간 확보

void    init(t_cube3d *s, char *argv, int save)
{
    s->mlx = mlx_init();
    mlx_get_screen_size(s->mlx, &s->tw.width, &s->tw.height);//스크린 사이즈 가져오기
    parse(s, argv);
}
