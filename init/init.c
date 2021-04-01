/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: napark <napark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 22:49:17 by napark            #+#    #+#             */
/*   Updated: 2021/04/01 16:31:24 by napark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

t_uc    s_parse_check = 0;//1바이트 공간 확보

void    init(t_cube3d *s, char *argv, int save)
{
    s->mlx = mlx_init();
    mlx_get_screen_size(s->mlx, &s->tw.width, &s->tw.height);//스크린 사이즈 가져오기
    parse(s, argv);
}

void    parse(t_cube3d *s, char *argv)
{
    int fd;
    int check;
    char *line;

    if (check_path(argv))
        ft_strexit("ERROR : Invalid file (.cub)");
    if ((fd = open(argv, O_RDONLY)) == -1)
        ft_strexit("ERROR : we can't open .cub file");
    while ((s_parse_check != 0xFF) && (check = get_next_line(fd, &line)) >= 0)
        check_parse_type(s, line);
}

static void     check_parse_type(t_cube3d *s, char *line)
{
    int **split_count;
    int word_count;

    if (ft_strlen(line))//line의 줄을 센다
    {
        if (!(split_count = ft_split_count(line, ' ', word_count)))
            ft_strexit("ERROR : (.cub) file is invalid!");
    }
}

int     ft_split_count(char *line, char sp, int word_count)
{
    int word_count;

    word_count = ft_word_count(line, sp);
}

static size_t   ft_word_count(char const *line, char sp)//space전까지 word의 수를 세주는 함수
{
    size_t count;

    count = 0;
    while (*line && *line == sp)//space가 나올때까지 전진
        line++;
    while (*line)
    {
        //이 부분 질문
        count++;
        while (*line && *line != sp)
        {
            line++;
        }
        while (*line && *line == sp)
        {
            line++;
        }
        return (count);
    }

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