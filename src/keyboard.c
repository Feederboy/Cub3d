/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguerra <mguerra@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 15:29:27 by mguerra           #+#    #+#             */
/*   Updated: 2023/02/16 22:05:08 by mguerra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	key_w(void)
{
	double		x_vec;
	double		y_vec;
	t_player	*p;
	t_map		*map;

	p = data()->p;
	map = data()->map;
	x_vec = p->dir_x * p->move_speed;
	y_vec = p->dir_y * p->move_speed;
	if (map->map[(int)(p->pos_y)][(int)(p->pos_x + x_vec * WALLDIST)] == '0')
		p->pos_x += x_vec;
	if (map->map[(int)(p->pos_y + y_vec * WALLDIST)][(int)(p->pos_x)] == '0')
		p->pos_y += y_vec;
}

/*
**	move backwards if no wall behind you
*/
void	key_s(void)
{
	double		x_vec;
	double		y_vec;
	t_player	*p;
	t_map		*map;

	p = data()->p;
	map = data()->map;
	x_vec = data()->p->dir_x * data()->p->move_speed;
	y_vec = data()->p->dir_y * data()->p->move_speed;
	if (map->map[(int)(p->pos_y)][(int)(p->pos_x - x_vec * WALLDIST)] == '0')
		p->pos_x -= x_vec;
	if (map->map[(int)(p->pos_y - y_vec * WALLDIST)][(int)(p->pos_x)] == '0')
		data()->p->pos_y -= y_vec;
}

/*
**	move left if no wall to your left
*/
void	key_a(void)
{
	double		x_vec;
	double		y_vec;
	t_player	*p;
	t_map		*map;

	p = data()->p;
	map = data()->map;
	x_vec = data()->p->dir_x * data()->p->move_speed;
	y_vec = data()->p->dir_y * data()->p->move_speed;
	if (map->map[(int)(p->pos_y)][(int)(p->pos_x + y_vec * WALLDIST)] == '0')
		p->pos_x += y_vec;
	if (map->map[(int)(p->pos_y - x_vec * WALLDIST)][(int)(p->pos_x)] == '0')
		p->pos_y -= x_vec;
}

/*
**	move right if no wall to your right
*/
void	key_d(void)
{
	double		x_vec;
	double		y_vec;
	t_player	*p;
	t_map		*map;

	p = data()->p;
	map = data()->map;
	x_vec = data()->p->dir_x * data()->p->move_speed;
	y_vec = data()->p->dir_y * data()->p->move_speed;
	if (map->map[(int)(p->pos_y)][(int)(p->pos_x - y_vec * WALLDIST)] == '0')
		p->pos_x -= y_vec;
	if (map->map[(int)(p->pos_y + x_vec * WALLDIST)][(int)(p->pos_x)] == '0')
		data()->p->pos_y += x_vec;
}

int	key_hook(void)
{
	if (data()->move->key_w && !data()->move->key_s)
		key_w();
	if (data()->move->key_s && !data()->move->key_w)
		key_s();
	if (data()->move->key_a && !data()->move->key_d)
		key_a();
	if (data()->move->key_d && !data()->move->key_a)
		key_d();
	if (data()->move->arr_l && !data()->move->arr_r)
		key_arrow_left();
	if (data()->move->arr_r && !data()->move->arr_l)
		key_arrow_right();
	return (1);
}
