/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: napark <napark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 15:59:00 by napark            #+#    #+#             */
/*   Updated: 2021/04/19 18:01:36 by napark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cube3d.h>

static void make_map_setup(t_cube3d *s, int hight, int width, t_list *lst)
{
    t_list *curr;
    int i;

    curr = lst;
    if (!(s->map.data = malloc(sizeof(char **) * hight)))
        ft_strexit("ERROR : allocation memory for setup memory error(make_map_setup)");
    s->map.width = width;
    s->map.hight = hight;
    
    i = -1;
    while (++i < hight)
    {
        if (!(s->map.data[i] = malloc(width + 1)))
            ft_strexit("ERROR : allocation memry for setup map error(make_map_setup)");
        ft_memset(s->map.data[i], ' ', width);
        ft_memmove(s->map.data[i], curr->content, ft_strlen(curr->content));
        s->map.data[i][width] = 0;
        curr = curr->next;
    }
    ft_lstclear(&lst, free);
}

static void init_map_parsing(t_cube3d *s, int fd, char *line, int *check)
{
    int hight;
    int width;
    t_list  *curr;
    t_list  *temp;

    width = ft_strlen(line);
    if (!(curr = ft_lstnew(line)))
        ft_strexit("ERROR : we can't create new_list(init_map_parsing-curr)");
    while ((*check = get_next_line(fd, &line)) >= 0 && ft_strlen(line))
    {
        if (!(temp = ft_lstnew(line)))
            ft_strexit("ERROR : we can't create new_list(init_map_parsing-temp)");
        ft_lstadd_back(&curr, temp);
        width = width > (int)ft_strlen(line) ? width : ft_strlen(line); 
    }
    if (*check == -1)
        ft_strexit("ERROR : read map and parsing error(init_map_parsing)");
    free(line);
    hight = ft_lstsize(curr);
    make_map_setup(s, hight, width, curr);//가로, 세로
}

void    init_map(t_cube3d *s, int fd, char *line, int *check)
{
    init_map_parsing(s, fd, line, check);
}