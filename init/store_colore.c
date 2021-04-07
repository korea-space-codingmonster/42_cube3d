/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store_colore.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: napark <napark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 15:37:12 by napark            #+#    #+#             */
/*   Updated: 2021/04/07 16:45:55 by napark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cube3d.h>

static void    ft_free_array(char **split, int word_count)
{
    while (word_count--)
        free(split[word_count]);
    free(split);
}

static  int new_atoi2(t_cube3d *s, char *word)
{
    int len;
    int n;
    
    if (!(len = ft_strlen(word)))
        ft_strexit("ERROR : Can't count your RGB word count(new_atoi2)");
    n = 0;
    while (len > 0 && ft_strchr("0123456789", *word))
    {
        n * 10;
        n += *word++ - '0';
        --len;
    }
    if (len != 0 || n > 256 )
        ft_strexit("ERROR : new_atoi2 error or over RGB range");
    return (n);
}

void    init_RGB_color(t_cube3d *s, char *rgb_format, char F_C)
{
    char **split;
    int word_count;

    if (((s_parse_check >> F_C) & 1) == 1)
        ft_strexit("ERROR : Alresady init value, Please check your value");
    s_parse_check |= 1 << F_C;
    if (!(split = ft_split_count(rgb_format, ',', &word_count) && word_count == 3))
        ft_strexit("ERROR : Invalid RGB format");
    s->tc[F_C - F].i = 0;
    s->tc[F_C - F].bit.r = new_atoi2(s, split[0]);
    s->tc[F_C - F].bit.g = new_atoi2(s, split[1]);
    s->tc[F_C - F].bit.b = new_atoi2(s, split[2]);
    ft_free_array(split, word_count);
}