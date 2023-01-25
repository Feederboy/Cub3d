/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gc_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguerra <mguerra@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 18:41:10 by mguerra           #+#    #+#             */
/*   Updated: 2022/06/28 22:56:41 by mguerra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_gc_list	*gc_lstlast(t_gc_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

void	gc_lstadd_back(t_gc_list **alst, t_gc_list *lst)
{
	t_gc_list	*last;

	if (!lst)
		return ;
	if (!*alst)
	{
		*alst = lst;
		return ;
	}
	last = gc_lstlast(*alst);
	last->next = lst;
}
