/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: napark <napark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 22:49:17 by napark            #+#    #+#             */
/*   Updated: 2021/04/01 15:05:28 by napark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

t_uc    s_parse_check = 0;

void    init(t_cube3d *s, char *argv, int save)
{
    s->mlx = mlx_init();
    mlx_get_screen_size(s->mlx, &s->tw.width, &s->tw.height);//스크린 사이즈 가져오기
    parse(s, argv);
}

void    parse(t_cube3d *s, char *argv)
{
    int fd;

    if (check_path(argv))
        ft_strexit("ERROR : Invalid file (.cub)");
    if ((fd = open(argv, O_RDONLY)) == -1)
        ft_strexit("ERROR : we can't open .cub file");
}

static int     check_path(char *argv)
{
    int     len;

    if (ft_strlen(argv) < 4)
            ft_strexit("ERROR : unavailable .cub file");
            return(ERROR);
    if (argv[len - 1] == 'b' && argv[len - 2] == 'u' && argv[len - 3] == 'c' && argv[len - 4] == '.')
            return (SUCCESS);
    return (ERROR);
}