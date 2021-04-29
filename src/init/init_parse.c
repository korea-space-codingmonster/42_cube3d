/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_parse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: napark <napark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/24 15:34:55 by napark            #+#    #+#             */
/*   Updated: 2021/04/29 12:55:56 by napark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

t_uc	g_parse_check = 0;

static void		ft_free_arr(char **s, int i)
{
	while (i--)
		free(s[i]);
	free(s);
}

static void		switch_parse(t_cube3d *s, char **split, int word_cnt)
{
	if (!ft_strcmp(split[0], "R") && word_cnt == 3)
		init_resolution(s, &split[1]);
	else if (!ft_strcmp(split[0], "NO") && word_cnt == 2)
		init_texture(s, split[1], NO);
	else if (!ft_strcmp(split[0], "SO") && word_cnt == 2)
		init_texture(s, split[1], SO);
	else if (!ft_strcmp(split[0], "EA") && word_cnt == 2)
		init_texture(s, split[1], EA);
	else if (!ft_strcmp(split[0], "WE") && word_cnt == 2)
		init_texture(s, split[1], WE);
	else if (!ft_strcmp(split[0], "S") && word_cnt == 2)
		init_texture(s, split[1], S);
	else if (!ft_strcmp(split[0], "F") && word_cnt == 2)
		init_bg_color(s, split[1], F);
	else if (!ft_strcmp(split[0], "C") && word_cnt == 2)
		init_bg_color(s, split[1], C);
	else
		exit_cub3d_msg(s, "ERROR : invalide map format(switch_parse)");
}

static void		check_parse_type(t_cube3d *s, char *line)
{
	int		word_cnt;
	char	**split;

	if (ft_strlen(line))
	{
		if (!(split = ft_split_cnt(line, ' ', &word_cnt)))
			exit_cub3d_msg(s, "ERROR : parse error(check_parse_type)");
		switch_parse(s, split, word_cnt);
		ft_free_arr(split, word_cnt);
	}
	free(line);
}

static int		extention_check(char *path)
{
	int		len;

	if ((len = ft_strlen(path)) < 4)
		return (ERROR);
	if (path[len - 1] == 'b' && path[len - 2] == 'u' \
		&& path[len - 3] == 'c' && path[len - 4] == '.')
		return (SUCCES);
	return (ERROR);
}

void			init_parse(t_cube3d *s, char *path)
{
	int		fd;
	int		check;
	char	*line;

	if (extention_check(path))
		exit_cub3d_msg(s, "ERROR : path error(init_parse)(.cub)");
	if ((fd = open(path, O_RDONLY)) == -1)
		exit_cub3d_msg(s, "file open fail...(init_parse)");
	while ((g_parse_check != 0xFF) && (check = get_next_line(fd, &line)) >= 0)
		check_parse_type(s, line);
	if (check < 0)
		exit_cub3d_msg(s, !check ? "invaild map file" : "file read error");
	while ((check = get_next_line(fd, &line)) > 0 && !ft_strlen(line))
		free(line);
	init_map(s, fd, line, &check);
	init_sprite(s);
	close(fd);
}
