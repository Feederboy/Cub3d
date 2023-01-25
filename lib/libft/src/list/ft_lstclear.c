/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguerra <mguerra@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 04:40:54 by mguerra           #+#    #+#             */
/*   Updated: 2021/12/03 05:28:56 by mguerra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*item;
	t_list	*next_item;

	item = *lst;
	while (item)
	{
		next_item = item->next;
		ft_lstdelone(item, del);
		item = next_item;
	}
	*lst = NULL;
}
