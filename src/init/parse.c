/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: napark <napark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 17:11:11 by napark            #+#    #+#             */
/*   Updated: 2021/04/08 20:01:03 by napark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cube3d.h>

t_uc    s_parse_check = 0;

static  int     check_path(char *argv)
{
    int     len;
    
    len = ft_strlen(argv);
    if (len < 4)
        ft_strexit("ERROR : Invalide start syntext! rewrite start!");
    if (argv[len - 1] == 'b' && argv[len - 2] == 'u' && argv[len - 3] == 'c' && argv[len - 4] == '.')
            return (SUCCESS);
    return (ERROR);
}

static void     start_parse(t_cube3d *s, char **split_count, int word_count)
{
    if (!ft_strcmp(split_count[0], "R") && word_count == 3)
        printf("%s", split_count[0]);
       //store_information(s, split_count[1], split_count[2]);
}

static  void    check_parse_type(t_cube3d *s, char *line)
{
    char **split_count;
    int word_count;
    int len;

    len = ft_strlen(line);
    if (len)
    {
        split_count = ft_split_count(line, ' ', &word_count);
        if (!split_count)
            ft_strexit("ERROR : (.cub)file is invalid!");
        start_parse(s, split_count, word_count);
    }
}

void    parse(t_cube3d *s, char *argv)
{
    int     fd;
    int     check;
    char    *line;

    if (check_path(argv))
        ft_strexit("ERROR : Invalid file (.cub)");//아니면 exit처리
    if ((fd = open(argv, O_RDONLY)) == -1)
        ft_strexit("EEROR : we can't open .cub file");
    while((s_parse_check != 0xFF) && (check = get_next_line(fd, &line)) >= 0)
        check_parse_type(s, line);
}   