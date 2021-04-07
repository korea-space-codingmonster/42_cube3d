/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: napark <napark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/01 13:57:25 by mihykim           #+#    #+#             */
/*   Updated: 2021/04/07 17:16:37 by napark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** - Allocates (with malloc) and returns a new element
** - The variable 'content' is initialized with the value of 'content'
** - The variable 'next' is initialized to NULL
*/

t_list	*ft_lstnew(void *content)
{
	t_list	*new;

	new = malloc(sizeof(t_list));
	if (new == 0)
		return (0);
	new->content = content;
	new->next = 0;
	return (new);
}
