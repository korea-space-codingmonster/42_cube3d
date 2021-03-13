/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isformat.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: napark <napark@studenst.42seoul.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 12:27:37 by napark            #+#    #+#             */
/*   Updated: 2021/03/13 20:48:00 by napark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int     ft_isformat(char *str, char *format)
{
    int     len_str;
    int     len_fmt;
    char    *fmt_of_str;

    len_str = ft_strlen(str);//str개수
    len_fmt = ft_strlen(format);
    if (len_str <= len_fmt)
        return (0);
    fmt_of_str = str + len_str - len_fmt;//공간확보
    if (ft_strcmp(fmt_of_str, format) == 0)//두 문자열이 같으면 0 아니면 스펠링의 아스키코드 순서에 따라 음수 양수 반환
        return (1);
    return (0);
}