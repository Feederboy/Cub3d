/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguerra <mguerra@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 15:29:27 by mguerra           #+#    #+#             */
/*   Updated: 2023/02/17 16:25:45 by mguerra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	end_game(int exit_code)
{
	if (data()->mlx)
	{
		if (data()->img && data()->img->img)
			mlx_destroy_image(data()->mlx, data()->img->img);
		if (data()->win)
			mlx_destroy_window(data()->mlx, data()->win);
		mlx_destroy_display(data()->mlx);
		free(data()->mlx);
	}
	gc_clear();
	exit(exit_code);
	return (0);
}

void	error(char *msg)
{
	ft_printf_fd(2, "Error\n%s\n", msg);
	end_game(1);
}

// void	debug_data(void)
// {
// 	printf("floor: %d - R %d G %d B %d\n",
// 		data()->map->floor,
// 		data()->map->floor >> 16,
// 		(data()->map->floor >> 8) & 0xFF,
// 		data()->map->floor & 0xFF);
// 	printf("ceiling: %d - R %d G %d B %d\n",
// 		data()->map->ceiling,
// 		data()->map->ceiling >> 16,
// 		(data()->map->ceiling >> 8) & 0xFF,
// 		data()->map->ceiling & 0xFF);
// 	printf("NO: %s\n", data()->map->paths[N]);
// 	printf("SO: %s\n", data()->map->paths[S]);
// 	printf("WE: %s\n", data()->map->paths[W]);
// 	printf("EA: %s\n", data()->map->paths[E]);
// 	while (*map->map)
// 	{
// 		printf("%s\n", *map->map++);
// 	}
// 	printf("map: \n%s\n", data()->map->map_str);

// 	printf("player X: %f\n", data()->p->pos_x);
// 	printf("player Y: %f\n", data()->p->pos_y);

// 	printf("cols: %d\n", data()->map->cols);
// 	printf("rows: %d\n", data()->map->rows);

// 	printf("status: %d\n", data()->p->status);
// 	printf("pos_x: %f\n", data()->p->pos_x);
// 	printf("pos_y: %f\n", data()->p->pos_y);
// 	printf("dir_x: %f\n", data()->p->dir_x);
// 	printf("dir_y: %f\n", data()->p->dir_y);
// 	printf("plane_x: %f\n", data()->p->plane_x);
// 	printf("plane_y: %f\n", data()->p->plane_y);
// 	printf("move_speed: %f\n", data()->p->move_speed);
// 	printf("rot_s: %f\n", data()->p->rot_s);

// 	printf("ray->map_x: %d\n", data()->ray->map_x);
// 	printf("ray->map_y: %d\n", data()->ray->map_y);
// 	printf("ray->step_x: %d\n", data()->ray->step_x);
// 	printf("ray->step_y: %d\n", data()->ray->step_y);
// 	printf("ray->side: %d\n", data()->ray->side);
// 	printf("ray->tex_x: %d\n", data()->ray->tex_x);
// 	printf("ray->tex_y: %d\n", data()->ray->tex_y);
// 	printf("ray->line_h: %d\n", data()->ray->line_h);
// 	printf("ray->start: %d\n", data()->ray->start);
// 	printf("ray->end: %d\n", data()->ray->end);
// 	printf("ray->ratio: %f\n", data()->ray->ratio);
// 	printf("ray->texpos: %f\n", data()->ray->texpos);
// 	printf("ray->d_x: %f\n", data()->ray->d_x);
// 	printf("ray->d_y: %f\n", data()->ray->d_y);
// 	printf("ray->sidedist_x: %f\n", data()->ray->sidedist_x);
// 	printf("ray->sidedist_y: %f\n", data()->ray->sidedist_y);
// 	printf("ray->dd_x: %f\n", data()->ray->dd_x);
// 	printf("ray->dd_y: %f\n", data()->ray->dd_y);
// 	printf("ray->w_dist: %f\n", data()->ray->w_dist);
// }
