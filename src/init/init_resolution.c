/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_resolution.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: napark <napark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/24 16:10:56 by napark            #+#    #+#             */
/*   Updated: 2021/04/28 17:15:25 by napark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

static int	itoa(t_cube3d *s, char *word)
{
	int		len;
	int		n;

	n = 0;
	len = ft_strlen(word);
	while (len > 0 && ft_strchr("0123456789", *word))
	{
		n *= 10;
		n += *word++ - '0';
		--len;
	}
	if (len != 0)
		exit_cub3d_msg(s, "ERROR : itoa fail(init_resolution_itoa");
	return (n);
}

void		init_resolution(t_cube3d *s, char **split)
{
	t_ivec	resolution;

	if (((g_parse_check >> R) & 1) == 1)
		exit_cub3d_msg(s, "ERROR : already parsing(init_resolution)");
	g_parse_check |= 1 << R;
	resolution.x = itoa(s, split[0]);
	resolution.y = itoa(s, split[1]);
	if (resolution.x < s->v.width)
		s->v.width = resolution.x;
	if (resolution.y < s->v.height)
		s->v.height = resolution.y;
}
