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
# define SPR 4
# define FLOOR 5
# define CEILING 6

# define TEX_HEIGHT 256
# define TEX_WIDTH	256

typedef struct	a_tex
{
	char		*path[6];
	int			tile[6][TEX_HEIGHT * TEX_WIDTH];
	int			floor;
	int			ceiling;
}				t_tex;


typedef struct	s_all
{
	void		*mlx;
	void		*win;
	// t_img		img;
	t_tex		tex;
	// t_player	player;
	// t_ray		ray;
	// t_spr_ray	s_ray;
	// t_spr		*sprite;
	int			num_sprite;
	int			**buf;
	double		*z_buffer;
	int			fd;
	int			width;
	int			height;
	char		**map;
	int			map_width;
	int			map_height;
	char		*line;
	t_list		*lst;
}			    t_all;

#endif