/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: napark <napark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 17:11:11 by napark            #+#    #+#             */
/*   Updated: 2021/04/19 15:43:06 by napark           ###   ########.fr       */
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

static void     start_parse(t_cube3d *s, char **split, int word_count)
{
    printf("start parse");
    if (!ft_strcmp(split[0], "R") && word_count == 3)
    {
        printf("%s %s\n",split[1], split[2]);
        store_width_height(s, &split[1]);
    }
    else if (!ft_strcmp(split[0], "NO") && word_count == 2)
    {
        printf("%s\n",split[1]);
        init_texture(s, split[1], NO);
    }
    else if (!ft_strcmp(split[0], "SO") && word_count == 2)
    {
        printf("%s\n",split[1]);
        init_texture(s, split[1], SO);
    }
    else if (!ft_strcmp(split[0], "WE") && word_count == 2)
    {
        printf("%s\n",split[1]);
        init_texture(s, split[1], WE);
    }
    else if (!ft_strcmp(split[0], "EA") && word_count == 2)
    {
        printf("%s\n",split[1]);
        init_texture(s, split[1], EA);
    }
    else if (!ft_strcmp(split[0], "S") && word_count == 2)
    {
        printf("%s\n",split[1]);
        init_texture(s, split[1], S);
    }
    else if (!ft_strcmp(split[0], "F") && word_count == 2)
    {
        printf("%s\n",split[1]);
        init_rgb_color(s, split[1], F);
    }
    else if (!ft_strcmp(split[0], "C") && word_count == 2)
    {
        printf("%s\n",split[1]);
        init_rgb_color(s, split[1], C);
    }
}

static  void    check_parse_type(t_cube3d *s, char *line)
{
    char **split;
    int word_count;
    int len;

    len = ft_strlen(line);

    if (len)
    {
        
        split = ft_split_cnt(line, ' ', &word_count);
        
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
    if ((fd = open(argv, O_RDONLY)) == -1)
        ft_strexit("ERROR : we can't open .cub file(parse)");
    while((s_parse_check != 0xFF) && (check = get_next_line(fd, &line)) >= 0)
        check_parse_type(s, line);
}