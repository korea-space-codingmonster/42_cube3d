/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: napark <napark@studenst.42seoul.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 17:44:15 by napark            #+#    #+#             */
/*   Updated: 2021/03/31 23:08:29 by napark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <math.h>
#include "./libft/libft.h"
#include "./mlx/mlx.h"

#define OFF 0;
#define ON 1;

typedef struct s_window
{
    /* data */
}               t_window;


typedef struct  s_cube3d
{
    t_window    tw;
    void *mlx;
    void *win;
}               t_cube3d;