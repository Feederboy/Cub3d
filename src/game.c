/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maquentr <maquentr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 11:20:17 by maquentr          #+#    #+#             */
/*   Updated: 2023/02/09 12:11:36 by maquentr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	fill_arr_img(int i)
{
	int	y;
	int	x;

	y = 0;
	while (y < data()->img->h)
	{
		x = 0;
		while (x < data()->img->w)
		{
			data()->img->arr_img[i][data()->img->w * y + x] = \
				data()->img->data[data()->img->h * y + x];
			x++;
		}
		y++;
	}
}

void	load_img()
{
	char	*path;
	int		i;

	i = 1;
	while (i < 5)
	{
		if (i == E)
			path = data()->map->ea_path;
		else if (i == W)
			path = data()->map->we_path;
		else if (i == S)
			path = data()->map->so_path;
		else
			path = data()->map->no_path;
		data()->img->img = \
			mlx_xpm_file_to_image(data()->mlx, path, &data()->img->w, &data()->img->h);
		if (data()->img->w != TEXWIDTH || data()->img->h != TEXHEIGHT
			|| data()->img->img == NULL)
			error("XPM images problem\n");
		data()->img->data = (int *)mlx_get_data_addr(data()->img->img, \
					&data()->img->bpp, &data()->img->line_size, &data()->img->endian);
		fill_arr_img(i);
		mlx_destroy_image(data()->mlx, data()->img->img);
		i++;
	}
}

void    game_start()
{
    data()->mlx = mlx_init();
	if (!data()->mlx)
		error("mlx error\n");
	data()->win = mlx_new_window(data()->mlx, WIDTH, HEIGHT, "cub3D");
	if (!data()->win)
		error("window error\n");
	init_img();
	load_img();
	init_player();
	init_move();
}