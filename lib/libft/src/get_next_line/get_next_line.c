/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maquentr <maquentr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 19:46:08 by mguerra           #+#    #+#             */
/*   Updated: 2023/02/06 13:55:24 by maquentr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*gnl_strjoin(char *s1, char *s2)
{
	char	*res;
	int		i;
	int		j;

	if (!s1)
	{
		s1 = (char *)malloc(sizeof(char) * 1);
		s1[0] = '\0';
	}
	if (!s1 || !s2)
		return (NULL);
	res = (char *)malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!res)
		return (free(s1), NULL);
	i = 0;
	j = 0;
	while (s1[j])
		res[i++] = s1[j++];
	j = 0;
	while (s2[j])
		res[i++] = s2[j++];
	res[ft_strlen(s1) + ft_strlen(s2)] = '\0';
	free(s1);
	return (res);
}

static char	*read_until_new_line(int fd, char *str)
{
	int		rb;
	char	*buffer;

	rb = 42;
	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (free(str), NULL);
	while (!ft_has_char(str, '\n') && rb != 0)
	{
		rb = read(fd, buffer, BUFFER_SIZE);
		if (rb == -1)
			return (free(buffer), NULL);
		buffer[rb] = '\0';
		if (buffer[0] == '\0')
			return (free(buffer), free(str), NULL);
		// if (ft_has_non_printable_char(buffer))
		// 	return (free(buffer), NULL);
		str = gnl_strjoin(str, buffer);
	}
	free(buffer);
	return (str);
}

static char	*dup_until_new_line(char *str)
{
	int		i;
	char	*line;

	i = 0;
	if (!str[i])
		return (NULL);
	while (str[i] && str[i] != '\n')
		i++;
	line = (char *)malloc(sizeof(char) * (i + 2));
	if (!line)
		return (free(str), NULL);
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

static char	*get_remaining(char *str)
{
	int		i;
	int		j;
	char	*line;

	i = 0;
	j = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (!str[i])
		return (free(str), NULL);
	line = (char *)malloc(sizeof(char) * (ft_strlen(str) - i + 1));
	if (!line)
		return (free(str), NULL);
	i++;
	while (str[i])
		line[j++] = str[i++];
	line[j] = '\0';
	free(str);
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*remaining[1024];
	char		*line;

	if (fd < 0 || fd > 1024 || BUFFER_SIZE <= 0)
		return (0);
	remaining[fd] = read_until_new_line(fd, remaining[fd]);
	if (!remaining[fd])
		return (NULL);
	line = dup_until_new_line(remaining[fd]);
	remaining[fd] = get_remaining(remaining[fd]);
	return (line);
}


// #include "get_next_line.h"

// static int		check_next_line(char *str)
// {
// 	int i;

// 	i = 0;
// 	if (!str)
// 		return (0);
// 	while (str[i])
// 	{
// 		if (str[i] == '\n')
// 			return (1);
// 		i++;
// 	}
// 	return (0);
// }

// static int		find_next_line(char *str)
// {
// 	int i;

// 	i = 0;
// 	if (!str)
// 		return (0);
// 	while (str[i])
// 	{
// 		if (str[i] == '\n')
// 			return (i);
// 		i++;
// 	}
// 	return (0);
// }

// static void	save(char **s, char **line)
// {
// 	if (check_next_line(*s) == 1)
// 	{
// 		*line = ft_substr(*s, 0, find_next_line(*s), 0);
// 		*s = ft_substr(*s, find_next_line(*s) + 1, ft_strlen(*s), 1);
// 	}
// 	else
// 	{
// 		*line = ft_substr((*s), 0, ft_strlen(*s), 1);
// 		*s = NULL;
// 	}
// }

// int		get_next_line(int fd, char **line)
// {
// 	static char	*s[65535];
// 	char		buffer[BUFFER_SIZE + 1];
// 	int			byte_read;

// 	byte_read = 1;
// 	if (fd < 0 || BUFFER_SIZE <= 0 || !line)
// 		return (-1);
// 	while (!check_next_line(s[fd]) && byte_read)
// 	{
// 		byte_read = read(fd, buffer, BUFFER_SIZE);
// 		if (byte_read == -1)
// 			return (-1);
// 		buffer[byte_read] = '\0';
// 		s[fd] = ft_strjoin(s[fd], buffer);
// 	}
// 	save(&s[fd], line);
// 	if (byte_read == 0 && s[fd] == NULL)
// 		return (0);
// 	else
// 		return (1);
// }

// #include "get_next_line.h"

// char	*ft_concat(char **dest, char *src, int srclen)
// {
// 	char	*tmp;

// 	tmp = *dest;
// 	*dest = malloc(sizeof(char) * (ft_strlen(tmp) + srclen + 1));
// 	if (!dest)
// 	{
// 		free(tmp);
// 		return (NULL);
// 	}
// 	(*dest)[0] = '\0';
// 	if (tmp)
// 		ft_strlcpy(*dest, tmp, ft_strlen(tmp) + 1);
// 	ft_strlcat(*dest, src, ft_strlen(*dest) + srclen + 1);
// 	free(tmp);
// 	return (*dest);
// }

// int		get_line(char **line, char *buffer)
// {
// 	int		line_length;
// 	char	*chr;
// 	int		result;

// 	if (!buffer)
// 		return (-1);
// 	chr = ft_strchr(buffer, '\n');
// 	line_length = ft_strlen(buffer) - ft_strlen(chr);
// 	ft_concat(line, buffer, line_length);
// 	if (!chr)
// 		result = -1;
// 	else
// 		result = line_length;
// 	return (result);
// }

// int		get_prev(char **previous_buffer, char *buffer, int index)
// {
// 	char	*tmp;

// 	tmp = ft_strdup(buffer);
// 	free(*previous_buffer);
// 	*previous_buffer = ft_strdup(tmp + index + 1);
// 	if (!(*previous_buffer))
// 		return (-1);
// 	free(tmp);
// 	return (1);
// }

// int		read_line(int fd, char **line, char **previous_buffer)
// {
// 	int		index;
// 	char	buffer[BUFFER_SIZE + 1];
// 	int		ret;

// 	index = -1;
// 	while (index < 0)
// 	{
// 		ret = read(fd, buffer, BUFFER_SIZE);
// 		if (ret == 0)
// 			return (0);
// 		if (ret < 0)
// 		{
// 			free(*line);
// 			*line = NULL;
// 			return (-1);
// 		}
// 		buffer[ret] = '\0';
// 		index = get_line(line, buffer);
// 	}
// 	ret = get_prev(previous_buffer, buffer, index);
// 	return (1);
// }

// int		get_next_line(int fd, char **line)
// {
// 	int			index;
// 	int			ret;
// 	static char	*previous_buffer = NULL;

// 	if (!line || BUFFER_SIZE <= 0 || fd < 0 || fd > 1024)
// 		return (-1);
// 	*line = malloc(sizeof(char) * 1);
// 	(*line)[0] = '\0';
// 	index = get_line(line, previous_buffer);
// 	if (index < 0)
// 	{
// 		ret = read_line(fd, line, &previous_buffer);
// 		if (ret <= 0)
// 		{
// 			free(previous_buffer);
// 			if (ret == 0)
// 				return (0);
// 			else if (ret < 0)
// 				return (-1);
// 		}
// 	}
// 	else
// 		ret = get_prev(&previous_buffer, previous_buffer, index);
// 	return (ret);
// }