/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: napark <napark@studenst.42seoul.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 17:00:05 by mihykim           #+#    #+#             */
/*   Updated: 2021/03/15 23:09:11 by napark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** - Contiguously allocates enough space for 'count' objects
**   that are 'size' bytes of memory each.
** - The allocated memory is filled with bytes of value zero.
** - Returns a pointer to the allocated memory.
*/

void	*ft_calloc(size_t count, size_t size)
{
	void	*res;

	res = (void *)malloc(count * size);
	if (res == 0)
		return (0);
	ft_memset(res, 0, count * size);
	return (res);
}
