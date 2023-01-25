/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_to_matrix.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguerra <mguerra@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 08:43:50 by mguerra           #+#    #+#             */
/*   Updated: 2022/06/28 22:56:46 by mguerra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_lst_to_matrix(t_list *lst)
{
	char	**res;
	t_list	*tmp;
	int		i;

	tmp = lst;
	res = (char **)malloc(sizeof(char *) * (ft_lstsize(lst) + 1));
	res[ft_lstsize(lst)] = NULL;
	i = 0;
	while (tmp)
	{
		res[i++] = ft_strdup(tmp->content);
		tmp = tmp->next;
	}
	return (res);
}
