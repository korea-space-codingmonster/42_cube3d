/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: napark <napark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 15:59:00 by napark            #+#    #+#             */
/*   Updated: 2021/04/24 01:25:19 by napark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cube3d.h>

static void make_map_set(t_cube3d *s, int width, int hight, t_list *lst)
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

    width = ft_strlen(line);//가로 길이
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
    make_map_set(s, width, hight, curr);
}

static void     check_map_validate(t_cube3d *s, t_ivec point)
{
    t_map   *map;

    map = &s->map;
    if (!ft_strchr(" 012NSWE", map->data[point.y][point.x]) ||
            ((point.y == 0 || point.x == 0 || point.y == map->hight - 1 || point.x == map->width - 1) &&
            !ft_strchr(" 1", map->data[point.y][point.x])))
            ft_strexit("Invalid map file(check_map_validate)");
    if (map->data[point.y][point.x] == ' ')
    {
        if ((point.y != 0 && !ft_strchr(" 1", map->data[point.y - 1][point.x])) ||
                (point.x != 0 && !ft_strchr(" 1", map->data[point.y][point.x - 1])) ||
                (point.y < map->hight - 1 && !ft_strchr(" 1", map->data[point.y + 1][point.x])) ||
                (point.x < map->width - 1 && !ft_strchr(" 1", map->data[point.y][point.x + 1])))
                ft_strexit("ERROR : Invalid map format(check_map_validate)");
    }
}

void    init_map(t_cube3d *s, int fd, char *line, int *check)
{
    // 1. 맵 파싱 및 삽입
    // 2. 맵 유효성 검사
    int     check_point;
    int     flag;

    init_map_parsing(s, fd, line, check);
    check_point = 0;
    while (check_point < s->map.width * s->map.hight)
    {
        check_map_validate(s, new_ivec(check_point % s->map.width, check_point / s->map.width));
        if (ft_strchr("NSWE", s->map.data[check_point / s->map.width][check_point % s->map.width]))
            init_player(s, new_vec(check_point % s->map.width + 0.5, check_point / s->map.width + 0.5), &flag);
        check_point++;
    }
    if (!flag)
        ft_strexit("ERROR : Pasing player position error(init_map)");
}
