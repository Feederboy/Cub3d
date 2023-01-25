/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguerra <mguerra@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 18:07:04 by mguerra           #+#    #+#             */
/*   Updated: 2022/05/03 18:27:15 by mguerra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	format(va_list args, char type)
{
	int	count;

	count = 0;
	if (type == 'c')
		count += ft_print_char(va_arg(args, int));
	else if (type == 's')
		count += ft_print_str(va_arg(args, char *));
	else if (type == 'p')
		count += ft_print_ptr(va_arg(args, unsigned long long));
	else if (type == 'd' || type == 'i')
		count += ft_print_nbr(va_arg(args, int));
	else if (type == 'u')
		count += ft_print_unsigned_nbr(va_arg(args, unsigned int));
	else if (type == 'x' || type == 'X')
		count += ft_print_hex(va_arg(args, unsigned int), type);
	else if (type == '%')
		count += ft_print_char('%');
	return (count);
}

int	*get_printf_fd(void)
{
	static int	fd;

	if (!fd)
		fd = 1;
	return (&fd);
}

static void	set_printf_fd(int fd)
{
	int	*i;

	i = get_printf_fd();
	*i = fd;
}

int	ft_printf(const char *str, ...)
{
	int		count;
	va_list	args;

	count = 0;
	va_start(args, str);
	while (*str)
	{
		if (*str != '%')
		{
			count += ft_print_char(*str++);
			continue ;
		}
		count += format(args, *++str);
		str++;
	}
	va_end(args);
	return (count);
}

int	ft_printf_fd(int fd, const char *str, ...)
{
	int		count;
	va_list	args;

	set_printf_fd(fd);
	count = 0;
	va_start(args, str);
	while (*str)
	{
		if (*str != '%')
		{
			count += ft_print_char(*str++);
			continue ;
		}
		count += format(args, *++str);
		str++;
	}
	va_end(args);
	return (count);
}
