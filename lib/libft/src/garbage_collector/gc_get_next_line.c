/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gc_get_next_line.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguerra <mguerra@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 19:46:08 by mguerra           #+#    #+#             */
/*   Updated: 2023/02/17 16:27:02 by mguerra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* Adds the content of our buffer to the end of our stash */

void	gc_add_to_stash(t_clist **stash, char *buf, int readed)
{
	int		i;
	t_clist	*last;
	t_clist	*new_node;

	new_node = gc_malloc(sizeof(t_clist));
	if (new_node == NULL)
		return ;
	new_node->next = NULL;
	new_node->content = gc_malloc(sizeof(char) * (readed + 1));
	if (new_node->content == NULL)
		return ;
	i = 0;
	while (buf[i] && i < readed)
	{
		new_node->content[i] = buf[i];
		i++;
	}
	new_node->content[i] = '\0';
	if (*stash == NULL)
	{
		*stash = new_node;
		return ;
	}
	last = gc_ft_lst_get_last(*stash);
	last->next = new_node;
}

/* Uses read() to add characters to the stash */

void	gc_read_and_stash(int fd, t_clist **stash)
{
	char	*buf;
	int		readed;

	readed = 1;
	while (!gc_found_newline(*stash) && readed != 0)
	{
		buf = gc_malloc(sizeof(char) * (BUFFER_SIZE + 1));
		if (buf == NULL)
			return ;
		readed = (int)read(fd, buf, BUFFER_SIZE);
		if ((*stash == NULL && readed == 0) || readed == -1)
		{
			return ;
		}
		buf[readed] = '\0';
		gc_add_to_stash(stash, buf, readed);
	}
}

/* Extracts all characters from our stash and stores them in out line.
 * stopping after the first \n it encounters */

void	gc_extract_line(t_clist *stash, char **line)
{
	int	i;
	int	j;

	if (stash == NULL)
		return ;
	gc_generate_line(line, stash);
	if (*line == NULL)
		return ;
	j = 0;
	while (stash)
	{
		i = 0;
		while (stash->content[i])
		{
			if (stash->content[i] == '\n')
			{
				(*line)[j++] = stash->content[i];
				break ;
			}
			(*line)[j++] = stash->content[i++];
		}
		stash = stash->next;
	}
	(*line)[j] = '\0';
}

/* After extracting the line that was read, we don't need those characters
 * anymore. This function clears the stash so only the characters that have
 * not been returned at the end of get_next_line remain in our static stash. */

void	gc_clean_stash(t_clist **stash)
{
	t_clist	*last;
	t_clist	*clean_node;
	int		i;
	int		j;

	clean_node = gc_malloc(sizeof(t_clist));
	if (stash == NULL || clean_node == NULL)
		return ;
	clean_node->next = NULL;
	last = gc_ft_lst_get_last(*stash);
	i = 0;
	while (last->content[i] && last->content[i] != '\n')
		i++;
	if (last->content && last->content[i] == '\n')
		i++;
	clean_node->content = gc_malloc(sizeof(char) * \
		((ft_strlen(last->content) - i) + 1));
	if (clean_node->content == NULL)
		return ;
	j = 0;
	while (last->content[i])
		clean_node->content[j++] = last->content[i++];
	clean_node->content[j] = '\0';
	*stash = clean_node;
}

char	*gc_get_next_line(int fd)
{
	static t_clist	*stash = NULL;
	char			*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, &line, 0) < 0)
		return (NULL);
	line = NULL;
	gc_read_and_stash(fd, &stash);
	if (stash == NULL)
		return (NULL);
	gc_extract_line(stash, &line);
	gc_clean_stash(&stash);
	if (line[0] == '\0')
	{
		stash = NULL;
		return (NULL);
	}
	return (line);
}
