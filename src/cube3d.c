/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3d.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: napark <napark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 17:44:05 by napark            #+#    #+#             */
/*   Updated: 2021/04/07 16:19:59 by napark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

int     main(int argc, char **argv)
{
    int     save;
    t_cube3d    s;
    
    check_save_option(argc, argv[2], &save);//만약 save option을 입력하면 save = 1, 아니면 save = 0
    // save = ./cube3d --save test.cub    // not save = ./cube3d test.cub
    
    if (argc < 2)
    {
        ft_strexit("ERROR : Please enter more characters due to lack of word");
    }
    else
    {
        init(&s, argv[1 + save], save);
    }

    // if (save)
    //     save_bmp();
    
}