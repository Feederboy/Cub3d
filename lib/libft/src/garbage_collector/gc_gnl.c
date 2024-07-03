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

int	gc_found_newline(t_clist *stash)
{
	int		i;
	t_clist	*current;

	if (stash == NULL)
		return (0);
	current = gc_ft_lst_get_last(stash);
	i = 0;
	while (current->content[i])
	{
		if (current->content[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

/* Returns a pointer to the last node in our stash */

t_clist	*gc_ft_lst_get_last(t_clist *stash)
{
	t_clist	*current;

	current = stash;
	while (current && current->next)
		current = current->next;
	return (current);
}

/* Calculates the number of chars in the current line, including the trailing
 * \n if there is one, and allocates memory accordingly. */

void	gc_generate_line(char **line, t_clist *stash)
{
	int	i;
	int	len;

	len = 0;
	while (stash)
	{
		i = 0;
		while (stash->content[i])
		{
			if (stash->content[i] == '\n')
			{
				len++;
				break ;
			}
			len++;
			i++;
		}
		stash = stash->next;
	}
	*line = gc_malloc(sizeof(char) * (len + 1));
}

/* Frees the entire stash. */

void	gc_free_stash(t_clist *stash)
{
	t_clist	*current;
	t_clist	*next;

	current = stash;
	while (current)
	{
		next = current->next;
		current = next;
	}
}
