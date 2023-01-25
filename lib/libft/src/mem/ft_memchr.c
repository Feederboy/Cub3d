/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguerra <mguerra@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 13:26:59 by mguerra           #+#    #+#             */
/*   Updated: 2021/11/30 16:43:04 by mguerra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* Search for a char in memory area up to n */
void	*ft_memchr(const void *s, int c, size_t n)
{
	while (n--)
	{
		if (*(char *)(s) == (char)c)
			return ((void *)(s));
		s++;
	}
	return (NULL);
}
