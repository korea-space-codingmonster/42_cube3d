/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: napark <napark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 17:42:37 by napark            #+#    #+#             */
/*   Updated: 2021/04/08 14:14:11 by napark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

static int     check_path(char *argv)
{
    int     len;

    if (ft_strlen(argv) < 4)
            ft_strexit("ERROR : Invalide start syntext! rewrite start!");
            return(ERROR);
    if (argv[len - 1] == 'b' && argv[len - 2] == 'u' && argv[len - 3] == 'c' && argv[len - 4] == '.')
            return (SUCCESS);
    return (ERROR);
}

static void     check_parse_type(t_cube3d *s, char *line)//parse시작
{
    char **split_count;
    int word_count;

    if (ft_strlen(line))
    {
        if (!(split_count = ft_split_count(line, ' ', &word_count)))//' '로 분리된 부분이 몇개인지 카운트
            ft_strexit("ERROR : (.cub) file is invalid!");
        start_parse(s, split_count, word_count);
        ft_free_arr(split_count, word_count);
    }
    free(line);
}

static  void    ft_free_arr(char **split_count, int word_count)
{
    while (word_count--)
        free(split_count[word_count]);
    free(split_count);
}

static  void    start_parse(t_cube3d *s, char **split_count, int word_count)
{
    if (!ft_strcmp(split_count[0], "R") && word_count == 3)
        store_information(s, split_count[1], split_count[2]);
    else if (!ft_strcmp(split_count[0], "NO" && word_count == 2))
        init_texture(s, split_count[1], NO);
    else if (!ft_strcmp(split_count[0], "SO" && word_count == 2))
        init_texture(s, split_count[1], SO);
    else if (!ft_strcmp(split_count[0], "WE" && word_count == 2))
        init_texture(s, split_count[1], WE);
    else if (!ft_strcmp(split_count[0], "EA" && word_count == 2))
        init_texture(s, split_count[1], EA);
    else if (!ft_strcmp(split_count[0], "S" && word_count == 2))
        init_texture(s, split_count[1], S);
    else if (!ft_strcmp(split_count[0], "F" && word_count == 2))
        init_RGB_color(s, split_count[1], F);
    else if (!ft_strcmp(split_count[0], "C" && word_count == 2))
        init_RGB_color(s, split_count[1], C);
    else
        ft_strexit("ERROR : Invalid map format, please check your (.cub) file");
}

void    parse(t_cube3d *s, char *argv)
{
    int fd;
    int check;
    char *line;

    if (check_path(argv))//.cub파일 유효성 검사
        ft_strexit("ERROR : Invalid file (.cub)");//아니면 exit처리
    if ((fd = open(argv, O_RDONLY)) == -1)//.cub파일 오픈
        ft_strexit("ERROR : we can't open .cub file");//열지 못하면 프로그램 exit
    while ((s_parse_check != 0xFF) && (check = get_next_line(fd, &line)) >= 0)
        check_parse_type(s, line);// type별 파싱 진행
    if (check < 0)
        ft_strexit("ERROR : get_next_line can't read line");
    while ((check = get_next_line(fd, &line) >= 0) && ft_strlen(line))//위에서 읽은 check라인 다음부터 line을 읽어내려가기
        free(line);
    store_map_information(s, fd, line, &check);
}