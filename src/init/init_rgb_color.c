/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_rgb_color.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: napark <napark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 17:37:46 by napark            #+#    #+#             */
/*   Updated: 2021/04/19 16:52:36 by napark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cube3d.h>

static void     free_arr(char **split, int word_count)
{
    while (word_count--)
    {
        free(split[word_count]);
    }
    free(split);
}

void    init_rgb_color(t_cube3d *s, char *path, char info_FC)
{
    char **split;
    int     word_count;

    if (((s_parse_check >> info_FC) & 1) == 1)
        ft_strexit("ERROR : Already stock rgb data(init_rgb_color)");
    s_parse_check |= 1 << info_FC;
    if (!(split = ft_split_cnt(path, ',', &word_count)) && word_count != 3)
        ft_strexit("ERROR : split error(init_rgb_color)");
    s->tc[info_FC - F].i = 0;
    s->tc[info_FC - F].bit.r = ft_atoi(split[0]);
    s->tc[info_FC - F].bit.g = ft_atoi(split[1]);
    s->tc[info_FC - F].bit.b = ft_atoi(split[2]);
    free_arr(split, word_count);
}