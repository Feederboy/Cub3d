/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maquentr <maquentr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 07:50:37 by maquentr          #+#    #+#             */
/*   Updated: 2023/02/08 12:52:39 by maquentr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
**	DDA is a loop who increments with 1 square every time
**	Until a wall is hit either it jump a square in x direction(stepX)
**	Or a square in y direction (stepY)
**	When the ray has hit a wall,the loop end
*/
void	dda_calc()
{
	int	hit;

	hit = 0;
	while (!hit)
	{
		if (data()->ray->sidedist_x < data()->ray->sidedist_y)
		{
			data()->ray->sidedist_x += data()->ray->deltadist_x;
			data()->ray->map_x += data()->ray->step_x;
			data()->ray->side = 0;
		}
		else
		{
			data()->ray->sidedist_y += data()->ray->deltadist_y;
			data()->ray->map_y += data()->ray->step_y;
			data()->ray->side = 1;
		}
		if (data()->map->map_split[data()->ray->map_y][data()->ray->map_x] == '1')
			hit = 1;
	}
	if (data()->ray->side == 0)
		data()->ray->perpwalldist = data()->ray->sidedist_x - data()->ray->deltadist_x;
	else
		data()->ray->perpwalldist = data()->ray->sidedist_y - data()->ray->deltadist_y;
}

void	mapping_buff()
{
	double	wall;

	if (data()->ray->side == 0)
		wall = data()->p->pos_y + (data()->ray->perpwalldist * data()->ray->raydir_y);
	else
		wall = data()->p->pos_x + (data()->ray->perpwalldist * data()->ray->raydir_x);
	wall = wall - floor(wall);
	data()->ray->tex_x = (int)(wall * (double)TEXWIDTH);
	if (data()->ray->side == 0 && data()->ray->raydir_x < 0)
		data()->ray->tex_x = TEXWIDTH - data()->ray->tex_x - 1;
	if (data()->ray->side == 1 && data()->ray->raydir_y > 0)
		data()->ray->tex_x = TEXWIDTH - data()->ray->tex_x - 1;
	data()->ray->line_h = (int)(HEIGHT / data()->ray->perpwalldist);
	data()->ray->start = HEIGHT / 2 - data()->ray->line_h / 2;
	data()->ray->end = HEIGHT / 2 + data()->ray->line_h / 2;
	if (data()->ray->start < 0)
		data()->ray->start = 0;
	if (data()->ray->end >= HEIGHT)
		data()->ray->end = HEIGHT;
	data()->ray->ratio = 1.0 * TEXHEIGHT / data()->ray->line_h;
	data()->ray->texpos = (data()->ray->start - HEIGHT / 2 + data()->ray->line_h / 2) * data()->ray->ratio;
}

void	set_buff(int x)
{
	int		color;
	int		y;

	y = data()->ray->start;
	while (y < data()->ray->end)
	{
		data()->ray->tex_y = (int)data()->ray->texpos & (TEXHEIGHT - 1);
		if (data()->ray->side == 0)
		{
			if (data()->ray->raydir_x >= 0)
				color = data()->img->arr_img[E][TEXHEIGHT * data()->ray->tex_y + data()->ray->tex_x];
			else
				color = data()->img->arr_img[W][TEXHEIGHT * data()->ray->tex_y + data()->ray->tex_x];
		}
		else if (data()->ray->side == 1)
		{
			if (data()->ray->raydir_y >= 0)
				color = data()->img->arr_img[S][TEXHEIGHT * data()->ray->tex_y + data()->ray->tex_x];
			else
				color = data()->img->arr_img[N][TEXHEIGHT * data()->ray->tex_y + data()->ray->tex_x];
		}
		data()->img->buffer[y][x] = color;
		data()->ray->texpos += data()->ray->ratio;
		y++;
	}
}

void	raycasting()
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