/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gc_get_next_line.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguerra <mguerra@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 19:46:08 by mguerra           #+#    #+#             */
/*   Updated: 2022/05/21 01:50:34 by mguerra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*gc_gnl_strjoin(char *s1, char *s2)
{
	char	*res;
	int		i;
	int		j;

	if (!s1)
	{
		s1 = (char *)gc_malloc(sizeof(char) * 1);
		s1[0] = '\0';
	}
	if (!s1 || !s2)
		return (NULL);
	res = (char *)gc_malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!res)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[j])
		res[i++] = s1[j++];
	j = 0;
	while (s2[j])
		res[i++] = s2[j++];
	res[ft_strlen(s1) + ft_strlen(s2)] = '\0';
	return (res);
}

static char	*gc_read_until_new_line(int fd, char *str)
{
	int		rb;
	char	*buffer;

	rb = 42;
	buffer = gc_malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	while (!ft_has_char(str, '\n') && rb != 0)
	{
		rb = read(fd, buffer, BUFFER_SIZE);
		if (rb == -1)
			return (NULL);
		buffer[rb] = '\0';
		if (buffer[0] == '\0')
			return (NULL);
		str = gc_gnl_strjoin(str, buffer);
	}
	return (str);
}

static char	*gc_dup_until_new_line(char *str)
{
	int		i;
	char	*line;

	i = 0;
	if (!str[i])
		return (NULL);
	while (str[i] && str[i] != '\n')
		i++;
	line = (char *)gc_malloc(sizeof(char) * (i + 2));
	if (!line)
		return (NULL);
	i = 0;
	while (str[i] && str[i] != '\n')
	{
		line[i] = str[i];
		i++;
	}
	if (str[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

static char	*gc_get_remaining(char *str)
{
	int		i;
	int		j;
	char	*line;

	i = 0;
	j = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (!str[i])
		return (NULL);
	line = (char *)gc_malloc(sizeof(char) * (ft_strlen(str) - i + 1));
	if (!line)
		return (NULL);
	i++;
	while (str[i])
		line[j++] = str[i++];
	line[j] = '\0';
	return (line);
}

char	*gc_get_next_line(int fd)
{
	static char	*remaining[1024];
	char		*line;

	if (fd < 0 || fd > 1024 || BUFFER_SIZE <= 0)
		return (0);
	remaining[fd] = gc_read_until_new_line(fd, remaining[fd]);
	if (!remaining[fd])
		return (NULL);
	line = gc_dup_until_new_line(remaining[fd]);
	remaining[fd] = gc_get_remaining(remaining[fd]);
	return (line);
}
