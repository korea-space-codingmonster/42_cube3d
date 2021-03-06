/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_itoa_base_width.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: napark <napark@studenst.42seoul.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/17 00:38:12 by mihykim           #+#    #+#             */
/*   Updated: 2021/03/06 14:17:15 by napark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		get_itoa_base_width(long n, long size)
{
	int			i;
	long long	long_n;

	i = n < 1 ? 1 : 0;
	n = n < 0 ? -n : n;
	long_n = n < 0 ? -(long long)n : (long long)n;
	while (long_n != 0)
	{
		long_n = long_n / size;
		i++;
	}
	return (i);
}

/*
** get return value except '-' sign to meet 'prcs' requiremnet
*/
