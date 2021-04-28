/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: napark <napark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/24 15:07:11 by napark            #+#    #+#             */
/*   Updated: 2021/04/28 18:11:29 by napark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <mlx.h>
# include <stdlib.h>
# include <unistd.h>
# include <math.h>
# include <fcntl.h>
# include "../lib/libft/libft.h"

# define CUBE3D_TITLE "napark's cube3D"
# define WALL_STRIP_WIDTH 1
# define TILE 64
# define FOV 66
# define WALK_S 0.08
# define TURN_S 3

# define U_DIV 1
# define V_DIV 1
# define V_MOVE 0.0

# define ERROR 1
# define SUCCES 0

# define M_2PI	6.28318530717958647692528676655900576
# define M_PI	3.14159265358979323846264338327950288
# define M_PI_2	1.57079632679489661923132169163975144
# define M_PI_4	0.785398163397448309615660845819875721
# define M_PI_180	0.017453292519943295769236907684886

# define BITMAPFILEHEADER 14
# define BITMAPINFOHEADER 40

# define NO 0
# define SO 1
# define WE 2
# define EA 3
# define S 4
# define F 5
# define C 6
# define R 7

# define KEY_W		13
# define KEY_A		0
# define KEY_S		1
# define KEY_D		2
# define KEY_ESC	53
# define KEY_UP		126
# define KEY_DOWN	125
# define KEY_LEFT	123
# define KEY_RIGHT	124

# define X_EVENT_H

# define X_KEY_PRESS 2
# define X_KEY_RELEASE 3
# define X_DESTROY_NOTIFY 17

# ifdef __APPLE__
#  define X_KEY_PRESS_MASK 0
#  define X_KEY_RELEASE_MASK 0
#  define X_SUB_STRUCTURE_NOTIFY_MASK 0
# else
#  define X_KEY_PRESS_MASK 1
#  define X_KEY_RELEASE_MASK 2
#  define X_SUB_STRUCTURE_NOTIFY_MASK 524288
# endif

typedef unsigned char		t_uc;
typedef unsigned int		t_ui;

typedef struct				s_vec
{
	float					x;
	float					y;
}							t_vec;

typedef struct				s_ivec
{
	int						x;
	int						y;
}							t_ivec;

typedef union				u_color
{
	struct
	{
		t_ui				b	:8;
		t_ui				g	:8;
		t_ui				r	:8;
		t_ui				t	:8;
	}						bit;
	int						i;
}							t_color;

extern	t_color		g_color;
extern	t_uc		g_parse_check;

typedef struct				s_key
{
	char					w		:1;
	char					a		:1;
	char					s		:1;
	char					d		:1;
	char					up		:1;
	char					down	:1;
	char					left	:1;
	char					right	:1;
	char					esc		:1;
}							t_key;

typedef struct				s_map
{
	char					**data;
	int						w;
	int						h;
}							t_map;

typedef struct				s_img
{
	void					*ptr;
	t_color					*data;
	int						width;
	int						height;
	int						size_l;
	int						line;
	int						bpp;
	int						endian;
}							t_img;

typedef struct				s_sprite
{
	t_vec					pos;
	t_vec					trans;
	t_img					*tex;
}							t_sprite;

typedef struct				s_ray
{
	t_vec					dir;
	t_ivec					map;
	float					dist;
	char					side;
	t_img					*tex;
}							t_ray;

typedef struct				s_cube3d
{
	void					*mlx;
	void					*win;
	t_img					v;
	t_key					key;
	t_img					tex[7];
	int						num_rays;
	t_ray					*rays;
	int						num_sp;
	t_sprite				*sp;
	int						*sp_order;
	float					*sp_dist;
	t_map					map;
	t_color					bg_color[2];
	float					fov;
	float					fov_h;
	t_vec					dir;
	t_vec					plane;
	t_vec					pos;
}							t_cube3d;
void						init(t_cube3d *s, char *path, int flag);
void						init_map(t_cube3d *s,
							int fd, char *line,
							int *check);
void						init_parse(t_cube3d *s, char *path);
void						init_sprite(t_cube3d *s);
void						init_player(t_cube3d *s, t_vec pos, int *flag);
void						init_bg_color(t_cube3d *s, char *line, int bg_i);
void						init_resolution(t_cube3d *s, char **split);
void						init_texture(t_cube3d *s, char *path, int tex_i);

t_ivec						new_ivec(int x, int y);
t_vec						new_vec(float x, float y);
t_vec						rot_vec(t_vec v, float angle);
void						normalise_pos(t_cube3d *s, t_vec *pos);
void						normalise_ipos(t_cube3d *s, t_ivec *pos);

void						exit_cub3d_msg(t_cube3d *s, char *msg);
void						exit_cub3d(t_cube3d *s, int code);

int							handle_exit_window(t_cube3d *s);
int							handle_key_released(int keycode, t_cube3d *s);
int							handle_key_pressed(int keycode, t_cube3d *s);
int							handle_loop(t_cube3d *s);

void						render(t_cube3d *s);
void						render_floor(t_cube3d *s);
void						render_ceiling(t_cube3d *s);
void						render_wall(t_cube3d *s);
void						render_sprite(t_cube3d *s);
void						render_sprite_tex(t_cube3d *s,
							t_sprite *sp,
							t_ivec size,
							t_ivec move);

void						update(t_cube3d *s);
void						update_player(t_cube3d *s);
void						update_all_rays(t_cube3d *s);
void						update_sprite(t_cube3d *s);

void						put_pixel(t_img *view, int x, int y);
void						mid_point_rect(t_img *view,
							t_vec position, int width,
							int height);
void						rect(t_img *view,
							t_vec position,
							int width,
							int height);
void						line(t_img *view, t_vec a, t_vec b);

void						color_rgba(t_uc r, t_uc g, t_uc b, float a);
t_color						rgba(t_uc r, t_uc g, t_uc b, float a);
t_color						calc_rgba(t_color background, t_color color);

int							save_bmp(t_cube3d *s);
void						exit_cub3d(t_cube3d *s, int code);
void						exit_cub3d_msg(t_cube3d *s, char *msg);

int							mlx_destroy_display(void *mlx_ptr);

#endif
