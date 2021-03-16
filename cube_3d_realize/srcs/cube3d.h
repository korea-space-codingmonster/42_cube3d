# ifndef CUBE3D_H
# define CUBE3D_H

# include "../mlx/mlx.h"
# include "../libft/libft.h"
# include <math.h>
# include <fcntl.h>
# include <stdlib.h>
# include <signal.h>


typedef struct	s_all
{
	void		*mlx;
	void		*win;
	t_img		img;
	t_tex		tex;
	t_player	player;
	t_ray		ray;
	t_spr_ray	s_ray;
	t_spr		*sprite;
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

# endif