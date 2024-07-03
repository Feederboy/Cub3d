/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguerra <mguerra@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 15:29:27 by mguerra           #+#    #+#             */
/*   Updated: 2023/02/16 23:04:14 by mguerra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	key_press(int keycode)
{
	if (keycode == 119)
		data()->move->key_w = 1;
	if (keycode == 115)
		data()->move->key_s = 1;
	if (keycode == 97)
		data()->move->key_a = 1;
	if (keycode == 100)
		data()->move->key_d = 1;
	if (keycode == 65363)
		data()->move->arr_r = 1;
	if (keycode == 65361)
		data()->move->arr_l = 1;
	return (0);
}

int	key_release(int keycode)
{
	if (keycode == 119)
		data()->move->key_w = 0;
	if (keycode == 115)
		data()->move->key_s = 0;
	if (keycode == 97)
		data()->move->key_a = 0;
	if (keycode == 100)
		data()->move->key_d = 0;
	if (keycode == 65363)
		data()->move->arr_r = 0;
	if (keycode == 65361)
		data()->move->arr_l = 0;
	if (keycode == K_ESC || keycode == 65307)
		end_game(0);
	return (0);
}

void	key_arrow_left(void)
{
	double		olddir;
	double		oldplane;
	t_player	*p;

	p = data()->p;
	olddir = p->dir_y;
	oldplane = p->plane_y;
	p->dir_y = p->dir_x * sin(-(p->rot_s)) + p->dir_y * cos(-(p->rot_s));
	p->dir_x = p->dir_x * cos(-(p->rot_s)) - olddir * sin(-(p->rot_s));
	p->plane_y = p->plane_x * sin(-(p->rot_s))
		+ p->plane_y * cos(-(p->rot_s));
	p->plane_x = p->plane_x * cos(-(p->rot_s))
		- oldplane * sin(-(p->rot_s));
}

void	key_arrow_right(void)
{
	double		olddir;
	double		oldplane;
	t_player	*p;

	p = data()->p;
	olddir = p->dir_y;
	oldplane = p->plane_y;
	p->dir_y = p->dir_x * sin(p->rot_s) + p->dir_y * cos(p->rot_s);
	p->dir_x = p->dir_x * cos(p->rot_s) - olddir * sin(p->rot_s);
	p->plane_y = p->plane_x * sin(p->rot_s)
		+ p->plane_y * cos(p->rot_s);
	p->plane_x = p->plane_x * cos(p->rot_s)
		- oldplane * sin(p->rot_s);
}
