/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3d.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: napark <napark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/24 15:06:13 by napark            #+#    #+#             */
/*   Updated: 2021/04/28 17:16:38 by napark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

int		main(int ac, char **av)
{
	int			flag;
	t_cube3d	s;

	flag = !ft_strcmp(av[1], "--save");
	ft_memset(&s, 0, sizeof(t_cube3d));
	if (ac < 2)
		exit_cub3d_msg(&s, "please recheck your typing");
	init(&s, av[1 + flag], flag);
	if (flag)
		return (save_bmp(&s));
	mlx_hook(s.win, X_KEY_PRESS, X_KEY_PRESS_MASK, handle_key_pressed, &s);
	mlx_hook(s.win, X_KEY_RELEASE, \
		X_KEY_RELEASE_MASK, handle_key_released, &s);
	mlx_hook(s.win, X_DESTROY_NOTIFY,
			X_SUB_STRUCTURE_NOTIFY_MASK, handle_exit_window, &s);
	mlx_loop_hook(s.mlx, handle_loop, &s);
	mlx_loop(s.mlx);
	return (0);
}
