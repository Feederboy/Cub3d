/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_has_non_printable_char.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguerra <mguerra@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 10:52:38 by mguerra           #+#    #+#             */
/*   Updated: 2022/04/22 21:11:09 by mguerra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_has_non_printable_char(char *s)
{
	if (!s)
		return (0);
	while (*s)
	{
		if (*s == '\0' || *s == '\n')
		{
			s++;
			continue ;
		}
		if (!ft_isprint(*s))
			return (1);
		s++;
	}
	return (0);
}
