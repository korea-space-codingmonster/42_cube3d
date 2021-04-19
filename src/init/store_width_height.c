/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store_width_height.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: napark <napark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 16:26:12 by napark            #+#    #+#             */
/*   Updated: 2021/04/19 15:52:42 by napark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cube3d.h>

void    store_width_height(t_cube3d  *s, char **split)
{
    t_ivec  ti;

    if (((s_parse_check >> R) & 1) == 1)
        ft_strexit("ERROR : Already stock information(store_information)");
    s_parse_check |= 1 << R;
    ti.data_width = ft_atoi(split[0]);
    ti.data_height = ft_atoi(split[1]);
    
    if (ti.data_height < s->tw.height)
        s->tw.height = ti.data_height;
    if (ti.data_width < s->tw.width)
        s->tw.width = ti.data_width;
}
