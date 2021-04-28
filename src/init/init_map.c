/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: napark <napark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/24 15:50:23 by napark            #+#    #+#             */
/*   Updated: 2021/04/28 17:15:27 by napark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

static void	init_map_setup(t_cube3d *s, int size, int max, t_list *lst)
{
	t_list	*curr;
	int		i;

	curr = lst;
	if (!(s->map.data = malloc(sizeof(char **) * size)))
		exit_cub3d_msg(s, "ERROR : allocate memory fail(init_map_setup)");
	s->map.w = max;
	s->map.h = size;
	i = -1;
	while (++i < size)
	{
		if (!(s->map.data[i] = malloc(max + 1)))
			exit_cub3d_msg(s, "ERROR : allocate memory fail(init_map_setup)");
		ft_memset(s->map.data[i], ' ', max);
		ft_memmove(s->map.data[i], curr->content, ft_strlen(curr->content));
		s->map.data[i][max] = 0;
		curr = curr->next;
	}
	ft_lstclear(&lst, free);
}

static void	init_map_parsing(t_cube3d *s, int fd, char *line, int *check)
{
	int		max;
	t_list	*curr;
	t_list	*tmp;

	if (!(curr = ft_lstnew(line)))
		exit_cub3d_msg(s, "ERROR : linked list fail(init_map_parsing)");
	max = ft_strlen(line);
	while ((*check = get_next_line(fd, &line)) >= 0 && ft_strlen(line))
	{
		if (!(tmp = ft_lstnew(line)))
			exit_cub3d_msg(s, "ERROR : linked list fail(init_map_parsing)");
		ft_lstadd_back(&curr, tmp);
		max = max > (int)ft_strlen(line) ? max : ft_strlen(line);
	}
	if (*check == -1)
		exit_cub3d_msg(s, "ERROR : exit_cube3d_msg(init_map_parsing)");
	free(line);
	init_map_setup(s, ft_lstsize(curr), max, curr);
}

static void	check_map(t_cube3d *s, t_ivec p)
{
	t_map	*m;

	m = &s->map;
	if (!ft_strchr(" 012NSWE", m->data[p.y][p.x]) ||
		((p.y == 0 || p.x == 0 || p.y == m->h - 1 || p.x == m->w - 1) &&
		!ft_strchr(" 1", m->data[p.y][p.x])))
		exit_cub3d_msg(s, "invaild map file");
	if (m->data[p.y][p.x] == ' ')
	{
		if ((p.y != 0 && !ft_strchr(" 1", m->data[p.y - 1][p.x])) ||
			(p.x != 0 && !ft_strchr(" 1", m->data[p.y][p.x - 1])) ||
			(p.y < m->h - 1 && !ft_strchr(" 1", m->data[p.y + 1][p.x])) ||
			(p.x < m->w - 1 && !ft_strchr(" 1", m->data[p.y][p.x + 1])))
			exit_cub3d_msg(s, "invaild map file");
	}
}

void		init_map(t_cube3d *s, int fd, char *line, int *check)
{
	int		i;
	int		flag;

	init_map_parsing(s, fd, line, check);
	flag = 0;
	i = -1;
	while (++i < s->map.w * s->map.h)
	{
		check_map(s, new_ivec(i % s->map.w, i / s->map.w));
		if (ft_strchr("NSWE", s->map.data[i / s->map.w][i % s->map.w]))
			init_player(s,
				new_vec(i % s->map.w + 0.5, i / s->map.w + 0.5), &flag);
	}
	if (!flag)
		exit_cub3d_msg(s, "parsing player postion error");
}
