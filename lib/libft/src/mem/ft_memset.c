/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguerra <mguerra@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 13:06:49 by mguerra           #+#    #+#             */
/*   Updated: 2021/12/02 22:03:54 by mguerra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* Fill memory with same char up to n bytes */
void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*ss;

	ss = s;
	while (n--)
		*(unsigned char *)ss++ = (unsigned char)c;
	return (s);
}
