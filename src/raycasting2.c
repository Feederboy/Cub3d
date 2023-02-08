/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maquentr <maquentr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 10:32:33 by maquentr          #+#    #+#             */
/*   Updated: 2023/02/08 10:33:33 by maquentr         ###   ########.fr       */
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

void	sidedist_init(t_ray *ray, t_player *p)
{
	if (data()->ray->raydir_x < 0)
	{
		data()->ray->step_x = -1;
		data()->ray->sidedist_x = (p->pos_x - data()->ray->map_x) * data()->ray->deltadist_x;
	}
	else
	{
		data()->ray->step_x = 1;
		data()->ray->sidedist_x = (data()->ray->map_x + 1.0 - p->pos_x) * data()->ray->deltadist_x;
	}
	if (data()->ray->raydir_y < 0)
	{
		data()->ray->step_y = -1;
		data()->ray->sidedist_y = (p->pos_y - data()->ray->map_y) * data()->ray->deltadist_y;
	}
	else
	{
		data()->ray->step_y = 1;
		data()->ray->sidedist_y = (data()->ray->map_y + 1.0 - p->pos_y) * data()->ray->deltadist_y;
	}
}

void	ray_init(t_game *game, int x)
{
	double	camera;

	camera = 2 * x / (double)WIDTH - 1;
	if ((WIDTH - 1) == x)
		camera = 1.0;
	data()->ray->raydir_x = game->player.dir_x + game->player.plane_x * camera;
	data()->ray->raydir_y = game->player.dir_y + game->player.plane_y * camera;
	data()->ray->map_x = (int)game->player.pos_x;
	data()->ray->map_y = (int)game->player.pos_y;
	data()->ray->deltadist_x = fabs(1 / data()->ray->raydir_x);
	data()->ray->deltadist_y = fabs(1 / data()->ray->raydir_y);
	sidedist_init(&game->ray, &game->player);
}