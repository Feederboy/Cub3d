/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gc_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguerra <mguerra@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 13:32:43 by mguerra           #+#    #+#             */
/*   Updated: 2022/05/03 18:25:59 by mguerra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*gc_substr(const char *s, unsigned int start, size_t len)
{
	char			*res;
	unsigned int	i;

	if (!s)
		return (NULL);
	if (start > ft_strlen((char *)s))
		return (gc_strdup(""));
	if (len > (ft_strlen(s) - start))
		len = ft_strlen(s) - start;
	res = gc_malloc((len + 1) * sizeof(char));
	if (!res)
		return (NULL);
	i = 0;
	while (len--)
		res[i++] = s[start++];
	res[i] = '\0';
	return (res);
}
