/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: napark <napark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 17:42:37 by napark            #+#    #+#             */
/*   Updated: 2021/04/07 14:02:43 by napark           ###   ########.fr       */
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
        store_information(s, split_count[1], split_count[2]);
    else if (!ft_strcmp(split_count[0], "NO" && word_count == 2))
        init_texture(s, split_count[1], NO);
    else if (!ft_strcmp(split_count[0], "SO" && word_count == 2))
        init_texture(s, )
}

void    init_texture(t_cube3d *s, char *path, char text_direc)
{
    t_img   *img;

    if (((s_parse_check >> text_direc) & 1) == 1)
        ft_strexit("EEROR : Invalid map file or already reload path");
    s_parse_check |= 1 << text_direc;
    img = &s->path[text_direc];

    if (!(img->ptr = mlx_xpm_file_to_image(s->mlx, path, &img->width, &img->height)))
        ft_strexit("ERROR : fail to img load!");
    if (!(img->data = (t_color *)mlx_get_data_addr(img->ptr, &img->bpp, &img->size_l, &img->endian)))
        ft_strexit("ERROR : texture data load error!");
    img->line = img->size_l / (img->bpp / 8);
}