/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_event.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: napark <napark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/25 01:53:37 by napark            #+#    #+#             */
/*   Updated: 2021/04/28 17:15:35 by napark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

int		handle_key_pressed(int keycode, t_cube3d *s)
{
	(keycode == KEY_W ? s->key.w = 1 : 0);
	(keycode == KEY_A ? s->key.a = 1 : 0);
	(keycode == KEY_S ? s->key.s = 1 : 0);
	(keycode == KEY_D ? s->key.d = 1 : 0);
	(keycode == KEY_UP ? s->key.up = 1 : 0);
	(keycode == KEY_DOWN ? s->key.down = 1 : 0);
	(keycode == KEY_LEFT ? s->key.left = 1 : 0);
	(keycode == KEY_RIGHT ? s->key.right = 1 : 0);
	if (keycode == KEY_ESC)
		exit_cub3d(s, SUCCES);
	return (0);
}

int		handle_key_released(int keycode, t_cube3d *s)
{
	(keycode == KEY_W ? s->key.w = 0 : 0);
	(keycode == KEY_A ? s->key.a = 0 : 0);
	(keycode == KEY_S ? s->key.s = 0 : 0);
	(keycode == KEY_D ? s->key.d = 0 : 0);
	(keycode == KEY_UP ? s->key.up = 0 : 0);
	(keycode == KEY_DOWN ? s->key.down = 0 : 0);
	(keycode == KEY_LEFT ? s->key.left = 0 : 0);
	(keycode == KEY_RIGHT ? s->key.right = 0 : 0);
	return (0);
}

int		handle_exit_window(t_cube3d *s)
{
	exit_cub3d(s, SUCCES);
	return (0);
}

int		handle_loop(t_cube3d *s)
{
	update(s);
	render(s);
	mlx_put_image_to_window(s->mlx, s->win, s->v.ptr, 0, 0);
	mlx_do_sync(s->mlx);
	return (0);
}
