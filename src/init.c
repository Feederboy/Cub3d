/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maquentr <maquentr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 13:00:39 by maquentr          #+#    #+#             */
/*   Updated: 2023/02/08 13:05:17 by maquentr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_map()
{
	data()->map->no_path = NULL;
	data()->map->so_path = NULL;
	data()->map->we_path = NULL;
	data()->map->ea_path = NULL;
	data()->map->floor = -1;
	data()->map->celling = -1;
	data()->map->map = NULL;
	data()->map->height = 0;
	data()->map->width = 0;
	data()->map->mcount = 0;
	data()->map->start = 0;
	data()->map->ret = 1;
}

void	init_img()
{
	data()->img->img = NULL;
	data()->img->data = NULL;
	data()->img->bpp = 0;
	data()->img->line_size = 0;
	data()->img->endian = 0;
	data()->img->arr_img = NULL;
}

void	init_move()
{
	data()->move->key_w = 0;
	data()->move->key_a = 0;
	data()->move->key_s = 0;
	data()->move->key_d = 0;
	data()->move->arr_l = 0;
	data()->move->arr_r = 0;
}