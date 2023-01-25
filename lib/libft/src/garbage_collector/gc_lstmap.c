/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gc_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguerra <mguerra@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 04:40:54 by mguerra           #+#    #+#             */
/*   Updated: 2022/05/03 07:36:49 by mguerra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*gc_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*item;
	t_list	*new_lst;

	if (!lst || !f)
		return (NULL);
	new_lst = NULL;
	while (lst)
	{
		item = gc_lstnew(f(lst->content));
		if (!item)
		{
			ft_lstclear(&new_lst, del);
			return (NULL);
		}
		ft_lstadd_back(&new_lst, item);
		item = item->next;
		lst = lst->next;
	}
	return (new_lst);
}
