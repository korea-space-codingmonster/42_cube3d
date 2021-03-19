/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_info_map.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: napark <napark@studenst.42seoul.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 03:10:57 by napark            #+#    #+#             */
/*   Updated: 2021/03/19 03:22:33 by napark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

void    validate_info(t_all *s)
{
    if (!s->width || !s->height)
        ft_strexit("EROOR : NO data in width, height");
    if (!s->tex.path[NORTH] || !s->tex.path[SOUTH] || !s->tex.path[EAST] || 
            !s->tex.path[WEST] || !s->tex.path[SPRITE] || !s->tex.floor == -1
                || !s->tex.ceiling == -1)
        ft_strexit("ERROR : NO data in NSEW or SPRITE or floor ceiling");
}