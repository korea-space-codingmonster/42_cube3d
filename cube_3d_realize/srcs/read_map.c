/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: napark <napark@studenst.42seoul.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 12:35:01 by napark            #+#    #+#             */
/*   Updated: 2021/03/19 14:29:12 by napark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

void     read_map(t_all *s, char *line)
{
    //read_map = 맵을 읽고 유효성 검사까지
    // 읽을 때 연결리스트로?
        s->lst = ft_lstnew(ft_strdhup(line));//맵의 첫째줄을 연결리스트에 삽입
        free(line);
        while (get_next_line(s->fd, &line))
        {
            if (line[0] == NULL)
                break;
            ft_lstadd_back(&s->lst, ft_lstnew(line));//s->lst에 line노드를 줄줄이 추가
            free(line);
        }
        free(line);
        allocate_map(s, s->lst);
}

void    allocate_map(t_all *s, t_list *curr)//지도를 저장하기 위한 메모리 할당
{
    int i;
    int j;

    s->map_width = ft_longest_node_len(curr);//맵의 넓이(가로)
    s->map_height = ft_lstsize(curr);//맵의 세로(높이)

    if (!(s->map = malloc(sizeof(char *) * (s->map_height + 1))))//char형 메모리가 높이 만큼
        ft_strexit("ERROR : Not allocate Memory");
    //이제 넓이 개수만큼 각 메모리를 할당하면서
    s->map[s->map_height] = NULL;

    i = 0;
    j = 0;
    while (curr)
    {
        if (!(s->map[i] = malloc(sizeof(char *) * (s->map_width + 1))))
            ft_strexit("ERROR : Not allocate Memory");
        j = 0;
        while (j < s->map_width)
        {
            s->map[i][j] = ' ';
            j++;
        }
    }

    
    
}