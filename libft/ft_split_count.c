/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_count.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: napark <napark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 17:34:48 by napark            #+#    #+#             */
/*   Updated: 2021/04/01 17:35:29 by napark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char     **ft_split_count(char *line, char sp, int *word_cnt)
{
    char **result;
    size_t word_count;
    size_t word_len;
    size_t i;

    word_count = ft_word_count(line, sp);
    if (!(result = (char **)malloc(sizeof(char *) * (word_count + 1))))
        return (ERROR);
    i = 0;
    while (i < word_count)
    {
        while (*line && *line == sp)//space가 아니면
            line ++;
        word_len = ft_word_len(line, sp);
        if (!(result[i] = ft_strndup(line, word_len)))
        {
            ft_free_memory(result, i - 1);
            return (0);
        }
        line += word_len;
        i++;
    }
    result[word_count] = NULL;
    (*word_cnt) = word_count;
    return (result);
}

void    ft_free_memory(char **result, int size)
{
    while (size--)
        free(result[size]);
    free(result);//질문 free해줄때 마지막 result까지 free를 해주는 이유
}