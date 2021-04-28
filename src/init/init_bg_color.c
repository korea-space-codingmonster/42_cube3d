/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_bg_color.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: napark <napark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/24 16:15:38 by napark            #+#    #+#             */
/*   Updated: 2021/04/28 17:15:28 by napark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

static void	ft_free_arr(char **s, int i)
{
	while (i--)
		free(s[i]);
	free(s);
}

static int	itoa(t_cube3d *s, char *word)
{
	int		len;
	int		n;

	n = 0;
	if (!(len = ft_strlen(word)))
		exit_cub3d_msg(s, "ERROR : ft_strlen fail(init_bg_color_itoa)");
	while (len > 0 && ft_strchr("0123456789", *word))
	{
		n *= 10;
		n += *word++ - '0';
		--len;
	}
	if (len != 0 || n > 256)
		exit_cub3d_msg(s, "ERROR : exit_cub3d_msg(init_bg_color_itoa)");
	return (n);
}

void		init_bg_color(t_cube3d *s, char *line, int bg_i)
{
	int		word_cnt;
	char	**split;

	if (((g_parse_check >> bg_i) & 1) == 1)
		exit_cub3d_msg(s, "ERROR : exit_cub3d_msg(init_bg_color)");
	g_parse_check |= 1 << bg_i;
	if (!(split = ft_split_cnt(line, ',', &word_cnt)) && word_cnt != 3)
		exit_cub3d_msg(s, word_cnt != 3 ? "invaild map file" : "malloc failed");
	s->bg_color[bg_i - F].i = 0;
	s->bg_color[bg_i - F].bit.r = itoa(s, split[0]);
	s->bg_color[bg_i - F].bit.g = itoa(s, split[1]);
	s->bg_color[bg_i - F].bit.b = itoa(s, split[2]);
	ft_free_arr(split, word_cnt);
}
