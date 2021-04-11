/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: napark <napark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 17:11:11 by napark            #+#    #+#             */
/*   Updated: 2021/04/11 15:25:00 by napark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cube3d.h>

t_uc    s_parse_check = 0;

static  int     check_path(char *argv)
{
    int     len;
    
    len = ft_strlen(argv);
    if (len < 4)
        ft_strexit("ERROR : Invalide start syntext! rewrite start!(check_path)");
    if (argv[len - 1] == 'b' && argv[len - 2] == 'u' && argv[len - 3] == 'c' && argv[len - 4] == '.')
            return (SUCCESS);
    else
        ft_strexit("ERROR : Invalid file(.cub)(check_path)");
}

static void    store_information(t_cube3d  *s, char **width, char **height)
{
    t_ivec  ti;

    if (((s_parse_check >> R) & 1) == 1)
        ft_strexit("ERROR : Already stock information(store_information)");
    s_parse_check |= 1 << R;

    ti.data_height = ft_atoi(width);
    ti.data_width = ft_atoi(height);

    if (ti.data_height < s->tw.height)
        s->tw.height = ti.data_height;
    if (ti.data_width < s->tw.width)
        s->tw.width = ti.data_width;
    printf("%d\n", ti.data_height);
    printf("%d\n", ti.data_width);
}

static void     start_parse(t_cube3d *s, char **split, int word_count)
{
    if (!ft_strcmp(split[0], "R") && word_count == 3)
        store_information(s, split[1], split[2]);
}

static  void    check_parse_type(t_cube3d *s, char *line)
{
    char **split;
    int word_count;
    int len;

    len = ft_strlen(line);
    if (len)
    {
        split = ft_split_count(line, ' ', &word_count);
        printf("%s", **split);
        if (!split)
            ft_strexit("ERROR : Invalid file(.cub)(check_parse_type)");
        start_parse(s, split, word_count);
    }
}

void    parse(t_cube3d *s, char *argv)
{
    int     fd;
    int     check;
    char    *line;

    if (!check_path(argv))
        ft_strexit("ERROR : Invalid file (.cub)(parse)");//아니면 exit처리
    printf("%s\n", argv);
    if ((fd = open(argv, O_RDONLY)) == -1)
        ft_strexit("EEROR : we can't open .cub file(parse)");
    printf("파일열기 완료\n");
    if((s_parse_check != 0xFF) && (check = get_next_line(fd, &line)) >= 0)
        //printf("%s", line);
        check_parse_type(s, line);
}