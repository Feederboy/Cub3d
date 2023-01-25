/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_hex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguerra <mguerra@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 06:26:42 by mguerra           #+#    #+#             */
/*   Updated: 2022/05/03 08:46:03 by mguerra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_hex(unsigned long long n, char type)
{
	if (n == 0)
		return (ft_print_char(n + '0'));
	else if (n >= 16)
		(ft_print_hex(n / 16, type), ft_print_hex(n % 16, type));
	else if (n < 10)
		ft_print_char(n + '0');
	else
		ft_print_char(n + type - '!');
	return (ft_max_factor(n, 16));
}

int	ft_print_ptr(unsigned long long ptr)
{
	if (ptr == 0)
		return (ft_print_str("(nil)"));
	ft_print_str("0x");
	return (2 + ft_print_hex(ptr, 'x'));
}
