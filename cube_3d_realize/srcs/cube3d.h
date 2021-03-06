# ifndef CUB3D_H
# define CUB3D_H

#include "../mlx/mlx.h"
#include "../libft/libft.h"
#include "../get_next_line/get_next_line.h"

#include <math.h>
#include <stdlib.h>
#include <stdio.h>

# define O_RDONLY 'r'
# define OFF 0
# define ERROR 0
# define ON  1


typedef struct s_all{
    int render_size_x;
    int render_size_y;
    
    int save;
    int     *fd;
}               t_all;


# endif