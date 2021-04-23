/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_sprite.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: napark <napark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/23 18:27:56 by napark            #+#    #+#             */
/*   Updated: 2021/04/23 19:18:44 by napark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cube3d.h>

static void sprite_parsing(t_cube3d *s, t_list **lst, t_list **curr)
{
    t_sprite    *temp;
    int i;

    i = 0;
    while (i < s->map.width * s->map.hight)
    {
        if (s->map.data[i / s->map.width][i % s->map.width] == '2')
        {
            if (!(temp = malloc(sizeof(t_sprite))))
                ft_strexit("ERROR : sprite memory allocate error(sprite parsing)");
            temp->position = new_vec(i % s->map.width + 0.5, i / s->map.width + 0.5);
            temp->tex = &s->path[S];
            if (!*lst)
                (!(*lst = ft_lstnew(temp)) ? ft_strexit("ERROR : linked list error") : 0);
            else if (!(*curr = ft_lstnew(temp)))
                ft_strexit("ERROR : linked list error");
            else
                ft_lstadd_back(lst, *curr);
        }
    }
}

void    init_sprite(t_cube3d *s)
{
    int i;
    t_list  *lst;
    t_list  *curr;

    sprite_parsing(s, &lst, &curr);
    s->num_sp = ft_lstsize(lst);
    if (!(s->ts = malloc(sizeof(t_sprite) * s->num_sp)) ||
            !(s->sp_order = malloc(sizeof(int) * s->num_sp)) ||
            !(s->sp_dist = malloc(sizeof(int) * s->num_sp)))
            ft_strexit("ERROR : malloc error(init_sprite)");
    curr = lst;
    i = 0;
    while (i < s->num_sp)
    {
        s->ts[i] = *(t_sprite *)curr->content;
        curr = curr->next;
        i ++;
    }
    ft_lstclear(&lst, free);
}