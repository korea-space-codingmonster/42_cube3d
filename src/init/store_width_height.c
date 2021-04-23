/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store_width_height.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: napark <napark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 16:26:12 by napark            #+#    #+#             */
/*   Updated: 2021/04/23 16:35:46 by napark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cube3d.h>

void    store_width_height(t_cube3d  *s, char **split)
{
    t_ivec  ti;

    if (((s_parse_check >> R) & 1) == 1)
        ft_strexit("ERROR : Already stock information(store_information)");
    s_parse_check |= 1 << R;
    ti.x = ft_atoi(split[0]);
    ti.y = ft_atoi(split[1]);
    if (ti.x < s->tw.width)
        s->tw.width = ti.x;
    if (ti.y < s->tw.height)
        s->tw.height = ti.y;
}
