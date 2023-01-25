/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gc_strreplace.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguerra <mguerra@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/07 06:16:39 by mguerra           #+#    #+#             */
/*   Updated: 2022/06/28 22:56:38 by mguerra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_size(const char *search, const char *replace, const char *str)
{
	int	count;
	int	i;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (ft_strstr(&str[i], search))
		{
			count++;
			i += ft_strlen(search) - 1;
		}
		else
			i++;
	}
	return (i + (count * ft_strlen(replace) - ft_strlen(search)) + 1);
}

char	*gc_strreplace(char *search, char *replace, char *str)
{
	char	*result;
	int		i;

	if (ft_strstr(str, search) == NULL)
		return (str);
	result = (char *)gc_malloc(get_size(search, replace, str));
	i = 0;
	while (*str)
	{
		if (ft_strstr(str, search) == str)
		{
			ft_strlcpy(&result[i], replace, (ft_strlen(&result[i]) \
				+ ft_strlen(replace) + 2));
			i += ft_strlen(replace);
			str += ft_strlen(search);
		}
		else
			result[i++] = *str++;
	}
	result[i] = '\0';
	return (result);
}
