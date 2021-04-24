/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_floor.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: napark <napark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/24 03:18:15 by napark            #+#    #+#             */
/*   Updated: 2021/04/24 03:31:42 by napark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cube3d.h>

void    render_floor(t_cube3d *s)
{
    s_color = s->tc[F - F];
    rect(&s->timg, new_vec(0, s->timg.height / 2), s->timg.width, s->timg.height / 2);
}