/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_cal.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: napark <napark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 14:07:30 by napark            #+#    #+#             */
/*   Updated: 2021/04/20 19:07:47 by napark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cube3d.h>

t_ivec   new_ivec(int x, int y)
{
    t_ivec  result;
    
    result.x = x;
    result.y = y;
    return (result);
}

t_vec   new_vec(float x, float y)
{
    t_vec   result;

    result.x = x;
    result.y = y;
    return (result);
}