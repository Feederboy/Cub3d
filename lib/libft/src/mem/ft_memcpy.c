/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguerra <mguerra@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 13:06:49 by mguerra           #+#    #+#             */
/*   Updated: 2021/11/30 16:47:44 by mguerra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>

/* Copy memory area up to n bytes */
void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char	*tsrc;
	char	*tdest;

	if (!dest && !src)
		return (NULL);
	tsrc = (char *)src;
	tdest = (char *)dest;
	while (n--)
		tdest[n] = tsrc[n];
	return (dest);
}
