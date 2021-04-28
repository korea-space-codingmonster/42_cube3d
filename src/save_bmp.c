/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_bmp.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: napark <napark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/25 02:57:15 by napark            #+#    #+#             */
/*   Updated: 2021/04/28 18:15:40 by napark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

static void	bmp_header(t_cube3d *s, int fd)
{
	int		tmp;
	char	header[BITMAPFILEHEADER];
	char	info[BITMAPINFOHEADER];

	ft_memset(&header, 0, BITMAPFILEHEADER);
	ft_memset(&info, 0, BITMAPINFOHEADER);
	ft_memmove(&header[0], "BM", 2);
	tmp = BITMAPFILEHEADER + BITMAPINFOHEADER +
		(s->v.bpp / 8) * s->v.width * s->v.height;
	ft_memmove(&header[2], &tmp, 4);
	tmp = BITMAPFILEHEADER + BITMAPINFOHEADER;
	ft_memmove(&header[10], &tmp, 4);
	write(fd, header, BITMAPFILEHEADER);
	tmp = BITMAPINFOHEADER;
	ft_memmove(&info[0], &tmp, 4);
	ft_memmove(&info[4], &s->v.width, 4);
	ft_memmove(&info[8], &s->v.height, 4);
	tmp = 1;
	ft_memmove(&info[12], &tmp, 2);
	ft_memmove(&info[14], &s->v.bpp, 2);
	write(fd, info, BITMAPINFOHEADER);
}

static void	bmp_data(t_cube3d *s, int fd)
{
	int		x;
	int		y;

	y = s->v.height;
	while (y-- > 0)
	{
		x = -1;
		while (++x < s->v.width)
			write(fd, &s->v.data[y * s->v.line + x].i, (s->v.bpp / 8));
	}
}

int			save_bmp(t_cube3d *s)
{
	int		fd;

	if ((fd = open("./image.bmp", O_CREAT | O_RDWR)) == -1)
		exit_cub3d_msg(s, "can't (create | open) image.bmp file");
	update(s);
	render(s);
	bmp_header(s, fd);
	bmp_data(s, fd);
	close(fd);
	return (SUCCES);
}
