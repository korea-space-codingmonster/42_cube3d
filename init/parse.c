/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: napark <napark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 17:42:37 by napark            #+#    #+#             */
/*   Updated: 2021/04/01 21:04:58 by napark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

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
        check_parse_type(s, line);
}

static int     check_path(char *argv)
{
    int     len;

    if (ft_strlen(argv) < 4)
            ft_strexit("ERROR : unavailable .cub file");
            return(ERROR);
    if (argv[len - 1] == 'b' && argv[len - 2] == 'u' && argv[len - 3] == 'c' && argv[len - 4] == '.')
            return (SUCCESS);
    return (ERROR);
}

static void     check_parse_type(t_cube3d *s, char *line)
{
    char **split_count;
    int word_count;

    if (ft_strlen(line))
    {
        if (!(split_count = ft_split_count(line, ' ', &word_count)))//' '로 분리된 부분이 몇개인지 카운트
            ft_strexit("ERROR : (.cub) file is invalid!");
        start_parse(s, split_count, word_count);
        
    }
}

static  void    start_parse(t_cube3d *s, char **split_count, int word_count)
{
    if (!ft_strcmp(split_count[0], "R") && word_count == 3)
        init_information(s, split_count);
}

void    init_information(t_cube3d *s, char **split_count)
{
    t_window_size tws;

    if (((s_parse_check >> R) & 1) == 1)
        ft_strexit("ERROR : Invalid code(R)");
}