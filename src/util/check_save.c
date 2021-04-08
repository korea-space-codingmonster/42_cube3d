/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_save.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: napark <napark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 14:38:57 by napark            #+#    #+#             */
/*   Updated: 2021/04/08 16:32:57 by napark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cube3d.h>

void        check_save_option(int argc, char *argv, int *save)
{
	if (argc > 3)
		ft_strexit("ERROR : So many arguments exist");
	if (argc < 2)
		ft_strexit("ERROR : So few arguments exist");
	if (argc == 1)
	{
		*save = OFF;//save 0
	}
	else if (ft_strcmp(argv, "--save") == 0)
	{
		*save = ON;//save 1
	}
	else
		ft_strexit("ERROR");
}