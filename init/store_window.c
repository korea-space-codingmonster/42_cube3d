/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store_window.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: napark <napark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/05 18:35:11 by napark            #+#    #+#             */
/*   Updated: 2021/04/07 16:46:15 by napark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cube3d.h>


static  int     new_atoi1(t_cube3d *s, char *value)
{
    int     len;
    int     n;

    n = 0;
    len = ft_strlen(value);
    while (len > 0 && ft_strchr("0123456789", value))
    {
        n *= 10;
        n += *value++ - '0';
        --len; 
    }
    if (len != 0)
        ft_strexit("ERROR : parsing error store_information");
    return (n);

}

void    store_information(t_cube3d *s, char **width, char **height)
{
    t_ivec  ti;


    if (((s_parse_check >> R) & 1) == 1)
        ft_strexit("ERROR : Already stack value");
    if (!width || !height)
        ft_strexit("ERROR : No data in width and height");
    else if (ft_only_digit(width) || ft_only_digit(height))
        ti.data_width = new_atoi1(s, width);
        ti.data_height = new_atoi1(s, height);
    
    if (ti.data_height < s->timg.height)
        s->timg.height = ti.data_height;
    if (ti.data_width < s->timg.width)
        s->timg.width = ti.data_width;
}