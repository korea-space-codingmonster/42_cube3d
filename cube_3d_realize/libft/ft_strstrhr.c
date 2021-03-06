/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstrhr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: napark <napark@studenst.42seoul.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/17 00:40:29 by mihykim           #+#    #+#             */
/*   Updated: 2021/03/06 14:16:56 by napark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstrhr(const char *s, char *set)
{
	int i;
	int j;

	if (s == 0)
		return (0);
	i = 0;
	if (set == 0)
		return ((char *)s + ft_strlen(s));
	while (s[i])
	{
		j = 0;
		while (set[j])
		{
			if (s[i] == set[j])
				return ((char *)s + i);
			j++;
		}
		i++;
	}
	return (0);
}
