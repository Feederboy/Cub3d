/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_max_divisor.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguerra <mguerra@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 08:42:18 by mguerra           #+#    #+#             */
/*   Updated: 2022/05/03 08:45:20 by mguerra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_max_factor(unsigned long long n, int divisor)
{
	int	count;

	count = 0;
	while (n)
		n /= (count++, divisor);
	return (count);
}
