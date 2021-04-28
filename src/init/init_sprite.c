/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_sprite.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: napark <napark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/24 16:04:29 by napark            #+#    #+#             */
/*   Updated: 2021/04/28 17:15:25 by napark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void	parsing_sprite(t_cube3d *s, t_list **lst, t_list **curr)
{
	int			i;
	t_sprite	*tmp;

	*lst = 0;
	i = -1;
	while (++i < s->map.w * s->map.h)
	{
		if (s->map.data[i / s->map.w][i % s->map.w] == '2')
		{
			if (!(tmp = malloc(sizeof(t_sprite))))
				exit_cub3d_msg(s, "ERROR : memory fail(parsing_sprite)");
			tmp->pos = new_vec(i % s->map.w + 0.5, i / s->map.w + 0.5);
			tmp->tex = &s->tex[S];
			if (!*lst)
				(!(*lst = ft_lstnew(tmp)) ?
					exit_cub3d_msg(s, "ERROR : ft_lstnew(parsing_sprite)") : 0);
			else if (!(*curr = ft_lstnew(tmp)))
				exit_cub3d_msg(s, "ERROR : ft_lstnew(parsing_sprite)");
			else
				ft_lstadd_back(lst, *curr);
		}
	}
}

void	init_sprite(t_cube3d *s)
{
	int			i;
	t_list		*lst;
	t_list		*curr;

	parsing_sprite(s, &lst, &curr);
	s->num_sp = ft_lstsize(lst);
	if (!(s->sp = malloc(sizeof(t_sprite) * s->num_sp)) ||
		!(s->sp_order = malloc(sizeof(int) * s->num_sp)) ||
		!(s->sp_dist = malloc(sizeof(float) * s->num_sp)))
		exit_cub3d_msg(s, "ERROR : allocate memory fail(init_sprite)");
	curr = lst;
	i = -1;
	while (++i < s->num_sp)
	{
		s->sp[i] = *(t_sprite *)curr->content;
		curr = curr->next;
	}
	ft_lstclear(&lst, free);
}
