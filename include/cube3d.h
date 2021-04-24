/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: napark <napark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 17:44:15 by napark            #+#    #+#             */
/*   Updated: 2021/04/24 14:02:51 by napark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <math.h>
#include <libft.h>
#include <mlx.h>

#define CUBE3D_TITLE "napark's cube3d"
#define WALL_STRIP_WIDTH 1
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

# define FOV 66
# define M_PI_180 0.017453292519943295769236907684886

# define X_KEY_PRESS 2
# define X_KEY_RELEASE 3
# define X_DESTROY_NOTIFY 17

# ifdef __APPLE__ 
# define X_KEY_PRESS_MASK 0
# define X_KEY_RELEASE_MASK 0
# define X_SUB_STRUCTURE_NOTIFY_MASK 0 
#else
#  define X_KEY_PRESS_MASK 1
#  define X_KEY_RELEASE_MASK 2
#  define X_SUB_STRUCTURE_NOTIFY_MASK 524288
# endif

# define KEY_W		13
# define KEY_A		0
# define KEY_S		1
# define KEY_D		2
# define KEY_ESC	53
# define KEY_UP		126
# define KEY_DOWN	125
# define KEY_LEFT	123
# define KEY_RIGHT	124

# define TURN_S   3
# define WALK_S   0.08

# define V_MOVE 0.0
# define U_DIV  1
# define V_DIV  1
# define V_MOVE 0.0

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

typedef struct  s_ivec
{
    int     x;
    int     y;
}               t_ivec;

typedef struct  s_vec
{
    float x;
    float y;
}               t_vec;

// //cubfile width, height
// typedef struct s_ivec
// {
//     int     data_width;
//     int     data_height;
// }               t_ivec;

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

extern  t_color s_color;
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

typedef struct s_key
{
    char    w       :1;
    char    a       :1;
    char    s       :1;
    char    d       :1;
    char    up      :1;
    char    down    :1;
    char    left    :1;
    char    right   :1;
    char    esc     :1;
}                   t_key;


typedef struct  s_map
{
    char    **data;
    int     width;
    int     hight;
}               t_map;

typedef struct s_rays
{
    t_vec   dir;
    t_ivec  map;
    float   dist;
    char    side;
    t_img   *tex;
}               t_rays;


typedef struct s_sprite
{
    t_vec   position;
    t_vec   transform;
    t_img   *tex;
}               t_sprite;

typedef struct  s_cube3d
{
    t_window    tw;

    t_img       timg;
    t_img       path[7];

    t_color     tc[2];

    t_map       map;

    void *mlx;
    void *win;

    float     fov;
    float     fov_h;

    t_vec       player_position;
    t_vec       player_direction;
    t_vec       plane_vector;

    int         num_sp;
    int         *sp_order;
    float       *sp_dist;
    t_sprite    *ts;

    int    num_rays;
    t_rays  *rays;
    
    t_key   key;
}               t_cube3d;

void        check_save_option(int argc, char *argv, int *save);
void    init(t_cube3d   *s, char *argv, int save);
void    parse(t_cube3d *s, char *argv);
void    init_rgb_color(t_cube3d *s, char *path, char info_FC);
void    init_texture(t_cube3d *s, char *path, char direc);
void    store_width_height(t_cube3d  *s, char **split);
void    init_map(t_cube3d *s, int fd, char *line, int *check);
void    init_player(t_cube3d *s, t_vec point, int *flag);
void    init_sprite(t_cube3d *s);

t_ivec   new_ivec(int x, int y);
t_vec    new_vec(float x, float y);
t_vec   rot_vec(t_vec v, float angle);
void	normalise_pos(t_cube3d *s, t_vec *pos);
void	normalise_ipos(t_cube3d *s, t_ivec *pos);

int    handle_key_pressed(int  keycode, t_cube3d *s);
int     handle_key_released(int keycode, t_cube3d *s);
int		handle_exit_window(t_cube3d *s);
int		handle_loop(t_cube3d *s);

void    update(t_cube3d *s);
void    update_player(t_cube3d *s);
void    update_all_rays(t_cube3d *s);
void    update_sprite(t_cube3d *s);

void    rendering(t_cube3d *s);
void    render_floor(t_cube3d *s);
void    render_ceiling(t_cube3d *s);
void    render_wall(t_cube3d *s);
void    render_sprite(t_cube3d *s);
void    render_sprite_tex(t_cube3d *s, t_sprite *sp, t_ivec size, t_ivec move);

t_color	calc_rgba(t_color background, t_color color);
t_color	rgba(t_uc r, t_uc g, t_uc b, float a);
void	color_rgba(t_uc r, t_uc g, t_uc b, float a);

void		line(t_img *view, t_vec a, t_vec b);
void		rect(t_img *view, t_vec position, int width, int height);
void		mid_point_rect(t_img *view, t_vec position, int width, int height);
void		put_pixel(t_img *view, int x, int y);