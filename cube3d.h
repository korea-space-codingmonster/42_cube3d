/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: napark <napark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 17:44:15 by napark            #+#    #+#             */
/*   Updated: 2021/04/01 15:41:02 by napark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <math.h>
#include "./libft/libft.h"
#include "./mlx/mlx.h"

#define OFF 0
#define ON 1
#define EROOR 0
#define SUCCESS 1

쇼ㅔㅇㄷ

extern  t_uc s_parse_check;

typedef struct s_window
{
    int width;
    int height;
}               t_window;


typedef struct  s_cube3d
{
    t_window    tw;
    void *mlx;
    void *win;
}               t_cube3d;