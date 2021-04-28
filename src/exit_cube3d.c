/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_cube3d.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: napark <napark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/24 15:47:31 by napark            #+#    #+#             */
/*   Updated: 2021/04/28 17:16:41 by napark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

static void	check_free(void *memory)
{
	if (memory)
		free(memory);
}

void		exit_cub3d(t_cube3d *s, int code)
{
	int		i;

	i = -1;
	while (++i < 7)
		(s->tex[i].ptr ? mlx_destroy_image(s->mlx, s->tex[i].ptr) : 0);
	check_free(s->rays);
	check_free(s->sp);
	check_free(s->sp_order);
	check_free(s->sp_dist);
	i = -1;
	while (++i < s->map.h)
		check_free(s->map.data[i]);
	(s->v.ptr ? mlx_destroy_image(s->mlx, s->v.ptr) : 0);
	(s->win ? mlx_destroy_window(s->mlx, s->win) : 0);
	(s->mlx ? mlx_destroy_display(s->mlx) : 0);
	exit(s ? code : 0);
}

void		exit_cub3d_msg(t_cube3d *s, char *msg)
{
	write(STDERR_FILENO, "ERROR\n", 6);
	write(STDERR_FILENO, msg, ft_strlen(msg));
	write(STDERR_FILENO, "\n", 1);
	exit_cub3d(s, ERROR);
}
