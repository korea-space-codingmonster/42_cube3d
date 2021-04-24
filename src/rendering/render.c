/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: napark <napark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/24 02:51:32 by napark            #+#    #+#             */
/*   Updated: 2021/04/24 11:13:21 by napark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cube3d.h>

void    rendering(t_cube3d *s)
{
    render_floor(s);
    render_ceiling(s);
    render_wall(s);
    render_sprite(s);
}