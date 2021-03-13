/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: napark <napark@studenst.42seoul.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 11:48:59 by napark            #+#    #+#             */
/*   Updated: 2021/03/13 11:54:08 by napark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void    *ft_calloc(size_t count, size_t size)//count * size만큼 할당(count = 블록단위, size = 블록 개수)
{
    void    *res;

    res = (void *)malloc(count * size);
    if (res == 0)
        return (0);
    ft_memset(res, 0, count * size);
    return (res);
}