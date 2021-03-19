/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: napark <napark@studenst.42seoul.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 12:35:01 by napark            #+#    #+#             */
/*   Updated: 2021/03/19 17:20:22 by napark           ###   ########.fr       */
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
        store_as_map_array(s, s->lst);
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
        s->map[i][s->map_width] = '\0';
        i++;
        curr = curr->next;
    }
}

void    store_as_map_array(t_all *s, t_list *curr)//메모리 할당 후 할당된 메모리에 map을 넣는 함수
{
    char *content;
    int i;
    int j;

    i = 0;
    while (i < s->map_height)
    {
        j = 0;
        content = (char *)curr->content;//line에서 연결리스트로 저장한 겂들을 가지고 있음
        while (j < s->map_height)
        {
            if (!ft_isset(content[j], "NSWE012 \n") && content[j] != '\0')//맵이 뚤려있거나, NSWE012가 있으면 EEOR
                ft_strexit("ERROR : ERROR: Invalid Map Element Contained!");
            s->map[i][j] = content[j];//맵의 정보를 저장
            if (ft_isset(content[j], "NSWE"))//player가 바라보고 있는 방향, 플레이어 위치반환
                create_playrer(s, i, j);
        }
    }
}

void    create_player(t_all *s, int i, int j)
{
    if (s->player.dir)//player.dir가 이미 설정 되어있다면 플레이어가 두명이 되버림
        ft_strexit("ERROR : Multiple Player Potion Given");
    s->player.dir = s->map[i][j];//플레이어 위치 저장
    s->player.x = 2;
	s->player.y = 5;
	s->player.dir_x = -1.0;
	s->player.dir_y = 0.0;
	s->player.plane_x = 0.0;
	s->player.plane_y = 0.66;
	s->player.move_speed = 0.07;
	s->player.rot_speed = 0.08;
	s->player.x = 0.5f + j;
	s->player.y = 0.5f + i;
}