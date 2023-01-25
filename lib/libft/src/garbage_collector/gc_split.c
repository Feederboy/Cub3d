/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gc_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguerra <mguerra@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 13:29:55 by mguerra           #+#    #+#             */
/*   Updated: 2022/05/03 21:17:53 by mguerra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_strings(const char *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i] && s[i] != c)
			count++;
		while (s[i] && s[i] != c)
			i++;
	}
	return (count);
}

static int	check_len(int i, char *s)
{
	if (i < 0)
		i = ft_strlen(s);
	return (i);
}

char	**gc_split(const char *s, char c)
{
	char	**res;
	int		i;
	int		len;

	if (!s)
		return (NULL);
	res = gc_malloc((count_strings(s, c) + 1) * sizeof(char *));
	if (!res)
		return (NULL);
	i = 0;
	res[count_strings(s, c)] = NULL;
	while (*s)
	{
		while (*s == c)
			s++;
		len = check_len(ft_indexof((char *)s, c), (char *)s);
		if (len == 0)
			return (res);
		res[i] = gc_strndup(s, len);
		if (res[i] == NULL)
			return (NULL);
		s += (i++, len);
	}
	return (res);
}
