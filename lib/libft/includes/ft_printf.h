/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguerra <mguerra@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 11:43:46 by mguerra           #+#    #+#             */
/*   Updated: 2022/05/03 18:42:16 by mguerra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdint.h>
# include <stdarg.h>
# include "libft.h"

// ft_printf.c
int	*get_printf_fd(void);
int	ft_printf(const char *str, ...);
int	ft_printf_fd(int fd, const char *str, ...);

// display_base.c
int	ft_print_char(char c);
int	ft_print_str(char *str);
int	ft_print_nbr(int n);
int	ft_print_unsigned_nbr(unsigned int n);

// display_hex.c
int	ft_print_hex(unsigned long long n, char type);
int	ft_print_ptr(unsigned long long ptr);
#endif
