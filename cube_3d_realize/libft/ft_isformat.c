/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isformat.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: napark <napark@studenst.42seoul.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 15:25:21 by mihykim           #+#    #+#             */
/*   Updated: 2021/03/16 16:04:37 by napark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isformat(char *str, char *format)
{
	int		len_str;
	int		len_fmt;
	char	*fmt_of_str;

	len_str = ft_strlen(str);//huge.cub
	len_fmt = ft_strlen(format);//.cub
	if (len_str <= len_fmt)
		return (0);
	fmt_of_str = str + len_str - len_fmt;//huge.cub + 8 + 4 =  
	if (ft_strcmp(fmt_of_str, format) == 0)//.cub .cub을 비교
		return (1);
	return (0);
}
