/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: napark <napark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/23 16:44:19 by napark            #+#    #+#             */
/*   Updated: 2021/04/23 17:25:04 by napark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cube3d.h>

t_vec   new_vec(float x, float y)
{
    t_vec   result;

    result.x = x;
    result.y = y;
    return (result);
}

t_ivec   new_ivec(int x, int y)
{
    t_ivec result;

    result.x = x;
    result.y = y;
    return(result);
}

t_vec   rot_vec(t_vec v, float angle)
{
    t_vec   result;
    t_vec   rotate;

    if (angle == 0)
        return (v);
    rotate = new_vec(cos(angle), sin(angle));
    result.x = rotate.x * v.x - rotate.y * v.y;
    result.y = rotate.y * v.x + rotate.x * v.y;
    return (result);
}