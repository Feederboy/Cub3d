/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gc_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguerra <mguerra@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 13:32:37 by mguerra           #+#    #+#             */
/*   Updated: 2022/05/03 18:44:42 by mguerra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*gc_strtrim(const char *s1, const char *set)
{
	char	*res;
	int		i;
	size_t	start;
	size_t	end;

	start = 0;
	if (!s1)
		return (NULL);
	while (ft_has_char((char *)set, s1[start]))
		start++;
	if (!s1 || start == ft_strlen(s1))
		return (gc_strdup(""));
	else if (!set)
		return (gc_strdup((char *)s1));
	end = ft_strlen(s1) - 1;
	while (ft_has_char((char *)set, s1[end]))
		end--;
	res = gc_malloc(sizeof(char) * (end - start + 2));
	if (!res)
		return (NULL);
	i = 0;
	while (s1[i] && start <= end)
		res[i++] = s1[start++];
	res[i] = '\0';
	return (res);
}
