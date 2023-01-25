/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguerra <mguerra@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 12:47:05 by mguerra           #+#    #+#             */
/*   Updated: 2022/05/03 21:06:07 by mguerra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* Convert an int into a digits string */

char	*ft_itoa(int i)
{
	char			*s;
	int				len;
	unsigned int	ui;

	ui = i;
	if (i == 0)
		return (ft_strdup("0"));
	if (i < 0)
		ui = -i;
	len = ft_max_factor(ui, 10) + (i < 0);
	s = malloc(sizeof(char) * (len + 1));
	if (!s)
		return (NULL);
	s[len] = '\0';
	if (i < 0)
		s[0] = '-';
	while ((i < 0) < len)
	{
		s[len - 1] = (ui % 10) + '0';
		len--;
		ui /= 10;
	}
	return (s);
}
