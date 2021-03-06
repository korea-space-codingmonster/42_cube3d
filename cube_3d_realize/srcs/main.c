/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: napark <napark@studenst.42seoul.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/06 13:48:18 by napark            #+#    #+#             */
/*   Updated: 2021/03/06 16:42:29 by napark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

void    open_cub(char *file_name, t_all *s)
{
    if (!ft_isformat(file_name, ".cub"))
        return (ft_strexit("ERROR : You cna't open your '.cub' file"));
    else
        s->fd = open("file_name", O_RDONLY);
        if (s->fd == -1)
            ft_strexit("The file you are looking for is not found.");
}

int     initial_struct(t_all *ta)
{
    
}

int     check_save_format(int ac_count, char *argv, t_all *ta)
{
    if (ac_count > 3)//argc == 2인 경우 : ./test.cub --save
        ft_strexit("so many argument you write!");
    else if (ac_count < 2)
        ft_strexit("so less argument you write!");
    else if (ac_count == 2)
        ta->save = OFF;
    else if (ac_count == 3 && ft_strcmp(argv, "--save") == 0)
        ta->save = ON;
    else
        ft_strexit("It is not a valid value.");
}

int     main(int argc, char **argv)
{
    t_all *ta;

    if(!(ta = malloc(sizeof(ta))))
        return (ERROR);
    
    check_save_format(argc, argv[3], ta);
    initialize_struct(ta);
    
}