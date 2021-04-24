/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_ceiling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: napark <napark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/24 03:32:06 by napark            #+#    #+#             */
/*   Updated: 2021/04/24 03:34:08 by napark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cube3d.h>

void    render_ceiling(t_cube3d *s)
{
    s_color = s->tc[C - F];
    rect(&s->timg, new_vec(0, 0), s->timg.width, s->timg.height / 2);
}