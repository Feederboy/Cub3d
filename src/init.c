/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maquentr <maquentr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 13:00:39 by maquentr          #+#    #+#             */
/*   Updated: 2023/02/09 14:19:23 by maquentr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_player()
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
	data()->p->rot_speed = 0.05;
}


void	init_map()
{
	data()->map->no_path = NULL;
	data()->map->so_path = NULL;
	data()->map->we_path = NULL;
	data()->map->ea_path = NULL;
	data()->map->floor = -1;
	data()->map->celling = -1;
	data()->map->mapp = NULL;
	data()->map->height = HEIGHT;
	data()->map->width = WIDTH;
	data()->map->mcount = 0;
	data()->map->start = 0;
	// data()->map->ret = 1;
}

void	init_img()
{
	printf("INIT IMG\n");
	data()->img->img = NULL;
	data()->img->data = NULL;
	data()->img->bpp = 0;
	data()->img->line_size = 0;
	data()->img->endian = 0;
	// data()->img->h = 64;
	// data()->img->w = 64;
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