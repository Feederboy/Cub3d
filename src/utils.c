/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maquentr <maquentr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 22:27:38 by mguerra           #+#    #+#             */
/*   Updated: 2023/01/26 14:47:16 by maquentr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_data	*data(void)
{
	static t_data	data;

	if (data.setup != 1)
	{
		data.setup = 1;
		data.init = 0;
		data.filename = NULL;
		data.map = (t_map *)gc_malloc(sizeof(t_map));
	}
	return (&data);
}