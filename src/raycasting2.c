/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguerra <mguerra@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 10:32:33 by maquentr          #+#    #+#             */
/*   Updated: 2023/02/16 22:12:23 by mguerra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
**	calculate step and initial distance of sides
**	if raydir is negative  sidedist_x is the distance from the
**	ray starting position to the first side to the left
**	else raydir is positive sidedist_x is the distance from the
**	ray starting position to the first side to the right
**	if x is negative we step to the left,positive to te right
**	if y is negative we step behind,positive we step forward
*/

void	sidedist_init(void)
{
	t_ray	*r;

	r = data()->ray;
	if (r->d_x < 0)
	{
		r->step_x = -1;
		r->sidedist_x = (data()->p->pos_x - r->map_x) * r->dd_x;
	}
	else
	{
		r->step_x = 1;
		r->sidedist_x = (r->map_x + 1.0 - data()->p->pos_x) * r->dd_x;
	}
	if (r->d_y < 0)
	{
		r->step_y = -1;
		r->sidedist_y = (data()->p->pos_y - r->map_y) * r->dd_y;
	}
	else
	{
		r->step_y = 1;
		r->sidedist_y = (r->map_y + 1.0 - data()->p->pos_y) * r->dd_y;
	}
}

void	ray_init(int x)
{
	double	camera;

	camera = 2 * x / (double)WIDTH - 1;
	if ((WIDTH - 1) == x)
		camera = 1.0;
	data()->ray->d_x = data()->p->dir_x + data()->p->plane_x * camera;
	data()->ray->d_y = data()->p->dir_y + data()->p->plane_y * camera;
	data()->ray->map_x = (int)data()->p->pos_x;
	data()->ray->map_y = (int)data()->p->pos_y;
	data()->ray->dd_x = fabs(1 / data()->ray->d_x);
	data()->ray->dd_y = fabs(1 / data()->ray->d_y);
	sidedist_init();
}
