/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: napark <napark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/25 02:53:22 by napark            #+#    #+#             */
/*   Updated: 2021/04/28 17:16:25 by napark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

t_color g_color = (t_color)0x00000000;

void	color_rgba(t_uc r, t_uc g, t_uc b, float a)
{
	if (a > 1)
		a = 1;
	g_color.bit.t = 255 - a * 255;
	g_color.bit.r = r;
	g_color.bit.g = g;
	g_color.bit.b = b;
}

t_color	rgba(t_uc r, t_uc g, t_uc b, float a)
{
	t_color	color;

	if (a > 1)
		a = 1;
	color.bit.t = 255 - a * 255;
	color.bit.r = r;
	color.bit.g = g;
	color.bit.b = b;
	return (color);
}

t_color	calc_rgba(t_color background, t_color color)
{
	float	alpha;
	t_color	result;

	if (color.bit.t == 0)
		return (color);
	alpha = ((255 - (color.bit.t)) / 255.0);
	result.i = 0;
	result.bit.r = ((1 - alpha) * (background.bit.r) + alpha * (color.bit.r));
	result.bit.g = ((1 - alpha) * (background.bit.g) + alpha * (color.bit.g));
	result.bit.b = ((1 - alpha) * (background.bit.b) + alpha * (color.bit.b));
	return (result);
}
