/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguerra <mguerra@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 15:29:27 by mguerra           #+#    #+#             */
/*   Updated: 2023/02/16 22:13:02 by mguerra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_map(t_map *map)
{
	map->no = NULL;
	map->so = NULL;
	map->we = NULL;
	map->ea = NULL;
	map->map_str = NULL;
	map->map = NULL;
	map->floor = -1;
	map->ceiling = -1;
	map->cols = 0;
	map->rows = 0;
}

void	init_img(t_img *img)
{
	img->img = NULL;
	img->data = NULL;
	img->bpp = 0;
	img->line_size = 0;
	img->endian = 0;
	img->a_img = NULL;
}

void	init_move(void)
{
	data()->move->key_w = 0;
	data()->move->key_a = 0;
	data()->move->key_s = 0;
	data()->move->key_d = 0;
	data()->move->arr_l = 0;
	data()->move->arr_r = 0;
}

void	init_player(void)
{
	data()->p->dir_x = 0;
	data()->p->dir_y = 0;
	if (data()->p->status == N)
	{
		data()->p->dir_y = -1;
		data()->p->plane_x = 0.66;
	}
	else if (data()->p->status == S)
	{
		data()->p->dir_y = 1;
		data()->p->plane_x = -0.66;
	}
	else if (data()->p->status == W)
	{
		data()->p->dir_x = -1;
		data()->p->plane_y = -0.66;
	}
	else
	{
		data()->p->dir_x = 1;
		data()->p->plane_y = 0.66;
	}
	data()->p->move_speed = 0.05;
	data()->p->rot_s = 0.05;
}
