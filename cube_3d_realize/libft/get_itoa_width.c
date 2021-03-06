/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_itoa_width.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: napark <napark@studenst.42seoul.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/17 00:37:55 by mihykim           #+#    #+#             */
/*   Updated: 2021/03/06 14:17:19 by napark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		get_itoa_width(long n)
{
	int		i;

	i = n < 1 ? 1 : 0;
	n = n < 0 ? -n : n;
	while (n != 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

/*
** line 15 : change from 'int' to 'long' to pass test 640 with long numbers
*/
