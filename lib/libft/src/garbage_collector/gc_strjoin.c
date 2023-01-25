/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gc_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguerra <mguerra@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 13:31:11 by mguerra           #+#    #+#             */
/*   Updated: 2022/05/03 18:06:59 by mguerra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* Concatenate two strings */

char	*gc_strjoin(const char *s1, const char *s2)
{
	char	*res;
	int		i;

	if (!s1 || !s2)
		return (NULL);
	res = gc_malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (res)
	{
		i = 0;
		while (*s1)
			res[i++] = *s1++;
		while (*s2)
			res[i++] = *s2++;
		res[i] = '\0';
	}
	return (res);
}
