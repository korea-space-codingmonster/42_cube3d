# ifndef CUBE3D_H
# define CUBE3D_H

# include "../mlx/mlx.h"
# include "../libft/libft.h"
# include <math.h>
# include <fcntl.h>
# include <stdlib.h>
# include <signal.h>

#define OFF 0
#define ON 1
#define EMPTY_LINE '\0'

# define NORTH 0
# define SOUTH 1
# define EAST 2
# define WEST 3
# define SPRITE 4
# define FLOOR 5
# define CEILING 6

# define MAP_COMPLETE -1

# define TEX_HEIGHT 256
# define TEX_WIDTH	256

typedef struct	a_tex
{
	char		*path[6];
	int			tile[6][TEX_HEIGHT * TEX_WIDTH];
	int			floor;
	int			ceiling;
}				t_tex;

typedef struct	a_player
{
	double	x;
	double	y;
	double	dir_x;
	double	dir_y;
	double	plane_x;
	double	plane_y;
	double	move_speed;
	double	rot_speed;
	char	dir;
}				t_player;

typedef struct	s_all
{
	void		*mlx;
	void		*win;
	// t_img		img;
	t_tex		tex;
	t_player	player;
	// t_ray		ray;
	// t_spr_ray	s_ray;
	// t_spr		*sprite;
	int			num_sprite;
	int			**buf;
	double		*z_buffer;
	int			fd;
	int			width;
	int			height;
	char		**map;//map을 저장하기 위한 메모리
	int			map_width;//map의 길이
	int			map_height;//map의 높이
	char		*line;//.cub파일을 한줄한줄 가리키는 포인터
	t_list		*lst;//맵 한줄 한줄을 연결리스트에 초기화
}			    t_all;

#endif