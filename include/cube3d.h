/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: napark <napark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 17:44:15 by napark            #+#    #+#             */
/*   Updated: 2021/04/19 17:57:54 by napark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <math.h>
#include <libft.h>
#include <mlx.h>

#define OFF 0
#define ON 1
#define ERROR 0
#define SUCCESS 1
///#define NULL 0

# define NO 0
# define SO 1
# define WE 2
# define EA 3
# define S 4
# define F 5
# define C 6
# define R 7

typedef unsigned char t_uc;
typedef unsigned int  t_ui;
extern  t_uc s_parse_check;



typedef struct s_window
{
    int width;
    int height;
}               t_window;

typedef struct  s_window_size
{
    int x;
    int y;
}               t_window_size;

//cubfile width, height
typedef struct s_ivec
{
    int     data_width;
    int     data_height;
}               t_ivec;


typedef union   u_color
{
    struct
    {
        t_ui    b   :8;
        t_ui    g   :8;
        t_ui    r   :8;
        t_ui    t   :8;
    }               bit;
    int         i;
}               t_color;

//realwindow width, height
typedef struct s_img
{
    void    *ptr;
    t_color *data;
    int     bpp;
    int     width;
    int     height;
    int     size_l;
    int     endian;
    int     line;
}               t_img;

typedef struct  s_map
{
    char **data;
    int     width;
    int     hight;
}               t_map;

typedef struct  s_cube3d
{
    t_window    tw;
    t_img       timg;
    t_img       path[7];
    t_color     tc[2];
    t_map       map;
    void *mlx;
    void *win;
}               t_cube3d;

void        check_save_option(int argc, char *argv, int *save);
void    init(t_cube3d   *s, char *argv, int save);
void    parse(t_cube3d *s, char *argv);
void    init_rgb_color(t_cube3d *s, char *path, char info_FC);
void    init_texture(t_cube3d *s, char *path, char direc);
void    store_width_height(t_cube3d  *s, char **split);
void    init_map(t_cube3d *s, int fd, char *line, int *check);