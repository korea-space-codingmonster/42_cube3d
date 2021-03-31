/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3d.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: napark <napark@studenst.42seoul.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 17:44:05 by napark            #+#    #+#             */
/*   Updated: 2021/03/31 22:49:06 by napark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

int     main(int argc, char **argv)
{
    int     save;
    t_cube3d    s;
    
    check_save_option(argc, argv[2], &save);

    if (argc > 2)
    {
        init(s, argv[1 + save], save);
    }

    if (save == OFF)
    {
        //저장안함
    }
    else if (save == ON){
        //저장함
    }
}