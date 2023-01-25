/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   garbage_collector.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguerra <mguerra@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 13:15:56 by mguerra           #+#    #+#             */
/*   Updated: 2022/06/28 22:56:23 by mguerra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_gc	*get_gc(void)
{
	static t_gc	gc;

	if (gc.setup != 1)
	{
		gc.head = NULL;
		gc.setup = 1;
	}
	return (&gc);
}

void	gc_clear(void)
{
	t_gc		*gc;
	t_gc_list	*tmp;
	t_gc_list	*next;

	gc = get_gc();
	tmp = gc->head;
	while (tmp)
	{
		next = tmp->next;
		free(tmp->content);
		free(tmp);
		tmp = next;
	}
	gc->head = NULL;
}

void	gc_clear_group(int group)
{
	t_gc		*gc;
	t_gc_list	*tmp;
	t_gc_list	*prev;
	t_gc_list	*next;

	gc = get_gc();
	tmp = gc->head;
	prev = NULL;
	while (tmp)
	{
		next = tmp->next;
		if (group == tmp->group)
		{
			if (prev)
				prev->next = next;
			free(tmp->content);
			free(tmp);
		}
		else
			prev = tmp;
		tmp = next;
	}
}

void	*gc_malloc(size_t size)
{
	t_gc		*gc;
	t_gc_list	*new;

	gc = get_gc();
	new = malloc(sizeof(t_gc_list));
	if (!new)
		return (NULL);
	new->content = (void *)malloc(size);
	ft_memset((char *)new->content, 0, size);
	new->group = 0;
	new->next = NULL;
	gc_lstadd_back(&gc->head, new);
	return (new->content);
}

void	*gc_malloc_group(size_t size, int group)
{
	t_gc		*gc;
	t_gc_list	*new;

	gc = get_gc();
	new = malloc(sizeof(t_gc_list));
	if (!new)
		return (NULL);
	new->content = (void *)malloc(size);
	new->group = group;
	new->next = NULL;
	gc_lstadd_back(&gc->head, new);
	return (new->content);
}
