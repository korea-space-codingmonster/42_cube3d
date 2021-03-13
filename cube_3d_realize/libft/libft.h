#ifndef LIBFT_H
# define LIBFT_H

#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>
#include <stddef.h>
#include <limits.h>

# ifndef BUFFER_SIZE
#   define BUFFER_SIZE 1
# endif

# define NL 1
# define _EOF 0
# define ERROR -1

typedef struct		s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

void				*ft_memset(void *b, int c, size_t len);//

#endif