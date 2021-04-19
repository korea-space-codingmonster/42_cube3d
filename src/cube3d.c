/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3d.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: napark <napark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 14:22:31 by napark            #+#    #+#             */
/*   Updated: 2021/04/19 11:57:37 by napark           ###   ########.fr       */
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
}