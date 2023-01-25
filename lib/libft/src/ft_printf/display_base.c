/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguerra <mguerra@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 21:13:11 by mguerra           #+#    #+#             */
/*   Updated: 2022/05/06 19:25:24 by mguerra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_char(char c)
{
	write(*get_printf_fd(), &c, 1);
	return (1);
}

int	ft_print_str(char *str)
{
	if (!str)
		return (ft_print_str("(null)"));
	write(*get_printf_fd(), str, ft_strlen(str));
	return (ft_strlen(str));
}

int	ft_print_nbr(int n)
{
	unsigned int	nb;
	int				count;

	count = 0;
	nb = n;
	if (n < 0)
	{
		count += ft_print_char('-');
		nb = -n;
	}
	if (nb >= 10)
		count += ft_print_nbr(nb / 10);
	count += ft_print_char((nb % 10) + '0');
	return (count);
}

int	ft_print_unsigned_nbr(unsigned int n)
{
	int		count;

	count = 0;
	if (n >= 10)
		count += ft_print_unsigned_nbr(n / 10);
	count += ft_print_char((n % 10) + '0');
	return (count);
}
