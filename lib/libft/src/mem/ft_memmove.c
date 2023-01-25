/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguerra <mguerra@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 13:06:49 by mguerra           #+#    #+#             */
/*   Updated: 2021/12/03 09:06:04 by mguerra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* Copy memory area up to n bytes without overlapping */
void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned long	i;

	if (!dest && !src)
		return (NULL);
	i = 0;
	while (src > dest && i < n)
	{
		*(char *)(dest + i) = *(char *)(src + i);
		i++;
	}
	while (dest > src && n--)
		*(char *)(dest + n) = *(char *)(src + n);
	return (dest);
}
