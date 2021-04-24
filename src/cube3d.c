/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3d.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: napark <napark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 14:22:31 by napark            #+#    #+#             */
/*   Updated: 2021/04/24 14:03:16 by napark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cube3d.h>

int main(int argc, char **argv)
{
    int         save;
    t_cube3d    s;

    check_save_option(argc, argv[1], &save);

    if (argc < 2)
        ft_strexit("ERROR : Please enter more characters due to lack of word(main)");
    // ./cube3D --save ./map/test.cub        ./cube3D ./map/test.cub
    init(&s, argv[1 + save], save);
    // if (save)
    //     return (save_bmp(&s));
    mlx_hook(s.win, X_KEY_PRESS, X_KEY_PRESS_MASK, handle_key_pressed, &s);
    mlx_hook(s.win, X_KEY_PRESS, X_KEY_RELEASE_MASK, handle_key_released, &s);
    mlx_hook(s.win, X_DESTROY_NOTIFY, X_SUB_STRUCTURE_NOTIFY_MASK, handle_exit_window, &s);
    mlx_loop_hook(s.mlx, handle_loop, &s);
    mlx_loop(s.mlx);
    return (0);
}