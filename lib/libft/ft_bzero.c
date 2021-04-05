/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: napark <napark@studenst.42seoul.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 05:55:00 by mihykim           #+#    #+#             */
/*   Updated: 2021/03/15 23:09:08 by napark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** - Writes 'n' zeroed bytes to the string 's'.
** - Does nothing if 'n' is zero.
*/

void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, 0, n);
}
