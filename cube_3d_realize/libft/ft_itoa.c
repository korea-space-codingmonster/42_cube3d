/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: napark <napark@studenst.42seoul.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 17:04:11 by napark            #+#    #+#             */
/*   Updated: 2021/03/13 20:48:01 by napark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	put_zero_or_minus(int n, char *res)
{
	if (n == 0)
		res[0] = '0';
	else if (n < 0)
		res[0] = '-';
}

char	*ft_itoa(int n)
{
	char	*res;
	long	long_n;
	long	i;

	i = n < 1 ? 1 : 0;
	long_n = n < 0 ? -(long)n : (long)n;
	while (long_n != 0)
	{
		long_n = long_n / 10;
		i++;
	}
	res = (char *)malloc(sizeof(char) * (i + 1));
	if (res == 0)
		return (0);
	res[i] = '\0';
	long_n = n < 0 ? -(long)n : (long)n;
	while (i >= 0)
	{
		res[i - 1] = long_n % 10 + '0';
		long_n = long_n / 10;
		i--;
	}
	put_zero_or_minus(n, res);
	return (res);
}
