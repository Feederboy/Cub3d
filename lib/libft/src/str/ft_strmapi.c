/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguerra <mguerra@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 13:32:03 by mguerra           #+#    #+#             */
/*   Updated: 2022/05/03 18:09:03 by mguerra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(const char *s, char (*f)(unsigned int, char))
{
	unsigned long	str_len;
	unsigned long	i;
	char			*res;

	i = 0;
	str_len = ft_strlen(s);
	res = malloc((str_len + 1) * sizeof(char));
	if (!res || !s || !f)
		return (NULL);
	while (s[i] && i < str_len)
	{
		res[i] = f(i, s[i]);
		i++;
	}
	res[i] = '\0';
	return (res);
}
