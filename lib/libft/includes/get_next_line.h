/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguerra <mguerra@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 10:43:17 by mguerra           #+#    #+#             */
/*   Updated: 2022/05/04 15:13:20 by mguerra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include "libft.h"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 4096
# endif

// char	*read_until_new_line(int fd, char *str);
// char	*dup_until_new_line(char *str);
// char	*get_remaining(char *str);
// char	*gnl_strjoin(char *s1, char *s2);
char	*gc_get_next_line(int fd);
char	*get_next_line(int fd);

#endif
