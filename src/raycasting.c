/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguerra <mguerra@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 07:50:37 by maquentr          #+#    #+#             */
/*   Updated: 2023/02/16 22:11:37 by mguerra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
**	DDA is a loop who increments with 1 square every time
**	Until a wall is hit either it jump a square in x direction(stepX)
**	Or a square in y direction (stepY)
**	When the ray has hit a wall,the loop end
*/
void	dda_calc(void)
{
	int	hit;

	hit = 0;
	while (!hit)
	{
		if (data()->ray->sidedist_x < data()->ray->sidedist_y)
		{
			data()->ray->sidedist_x += data()->ray->dd_x;
			data()->ray->map_x += data()->ray->step_x;
			data()->ray->side = 0;
		}
		else
		{
			data()->ray->sidedist_y += data()->ray->dd_y;
			data()->ray->map_y += data()->ray->step_y;
			data()->ray->side = 1;
		}
		if (data()->map->map[data()->ray->map_y][data()->ray->map_x] == '1')
			hit = 1;
	}
	if (data()->ray->side == 0)
		data()->ray->w_dist = data()->ray->sidedist_x - data()->ray->dd_x;
	else
		data()->ray->w_dist = data()->ray->sidedist_y - data()->ray->dd_y;
}

void	mapping_buff(void)
{
	double	wall;
	t_ray	*r;

	r = data()->ray;
	if (r->side == 0)
		wall = data()->p->pos_y + (r->w_dist * r->d_y);
	else
		wall = data()->p->pos_x + (r->w_dist * r->d_x);
	wall = wall - floor(wall);
	r->tex_x = (int)(wall * (double)TEXWIDTH);
	if (r->side == 0 && r->d_x < 0)
		r->tex_x = TEXWIDTH - r->tex_x - 1;
	if (r->side == 1 && r->d_y > 0)
		r->tex_x = TEXWIDTH - r->tex_x - 1;
	r->line_h = (int)(HEIGHT / r->w_dist);
	r->start = HEIGHT / 2 - r->line_h / 2;
	r->end = HEIGHT / 2 + r->line_h / 2;
	if (r->start < 0)
		r->start = 0;
	if (r->end >= HEIGHT)
		r->end = HEIGHT;
	r->ratio = 1.0 * TEXHEIGHT / r->line_h;
	r->texpos = (r->start - HEIGHT / 2 + r->line_h / 2) * r->ratio;
}

void	set_buff(int x)
{
	int		color;
	t_ray	*r;

	r = data()->ray;
	while (r->start < r->end)
	{
		r->tex_y = (int)r->texpos & (TEXHEIGHT - 1);
		if (r->side == 0)
		{
			if (r->d_x >= 0)
				color = data()->img->a_img[E][TEXHEIGHT * r->tex_y + r->tex_x];
			else
				color = data()->img->a_img[W][TEXHEIGHT * r->tex_y + r->tex_x];
		}
		else if (r->side == 1)
		{
			if (r->d_y >= 0)
				color = data()->img->a_img[S][TEXHEIGHT * r->tex_y + r->tex_x];
			else
				color = data()->img->a_img[N][TEXHEIGHT * r->tex_y + r->tex_x];
		}
		data()->img->buffer[r->start][x] = color;
		r->texpos += r->ratio;
		r->start++;
	}
}

void	raycasting(void)
{
	int	x;

	x = 0;
	while (x < WIDTH)
	{
		ray_init(x);
		dda_calc();
		mapping_buff();
		set_buff(x);
		x++;
	}
}
