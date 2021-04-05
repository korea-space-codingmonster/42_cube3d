/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_option.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: napark <napark@studenst.42seoul.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 18:32:42 by napark            #+#    #+#             */
/*   Updated: 2021/03/31 22:41:05 by napark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

void        check_save_option(int argc, char *argv, int *save)
{
	if (argc > 3)
		ft_strexit("ERROR : So many arguments exist");
	if (argc < 2)
		ft_strexit("ERROR : So few arguments exist");
	if (argc == 2)
	{
		save = OFF;
	}
	else if (ft_strcmp(argv, "--save") == 0)
	{
		save = ON;
	}
	else
		ft_strexit("ERROR");
}