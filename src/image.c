/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguerra <mguerra@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 20:42:37 by mguerra           #+#    #+#             */
/*   Updated: 2023/02/17 16:16:19 by mguerra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	fill_a_img(int i)
{
	int	y;
	int	x;

	y = 0;
	while (y < data()->img->h)
	{
		x = 0;
		while (x < data()->img->w)
		{
			data()->img->a_img[i][data()->img->w * y + x] = \
				data()->img->data[data()->img->h * y + x];
			x++;
		}
		y++;
	}
}

void	load_image(void)
{
	char	*path;
	int		i;
	t_img	*img;
	void	*tmp;

	i = 0;
	img = data()->img;
	while (i < 4)
	{
		path = data()->map->paths[i];
		if (open(path, O_RDONLY) == -1)
			error("Cannot read XPM image");
		tmp = mlx_xpm_file_to_image(data()->mlx, path, &img->w, &img->h);
		if (data()->img->w != TEXWIDTH || data()->img->h != TEXHEIGHT
			|| tmp == NULL)
			error("mlx XPM to image problem");
		img->data = (int *)mlx_get_data_addr(tmp, &img->bpp, \
			&img->line_size, &img->endian);
		fill_a_img(i);
		mlx_destroy_image(data()->mlx, tmp);
		i++;
	}
}

void	init_image(void)
{
	int		i;
	int		j;
	t_img	*img;

	i = 0;
	img = data()->img;
	while (i < HEIGHT)
	{
		j = 0;
		while (j < WIDTH)
			img->buffer[i][j++] = 0;
		i++;
	}
	img->a_img = (int **)gc_malloc(5 * sizeof(int *));
	if (!img->a_img)
		error("erreur de malloc");
	i = 0;
	while (i < 5)
	{
		img->a_img[i] = (int *)gc_malloc(sizeof(int) * TEXWIDTH * TEXHEIGHT);
		if (!img->a_img[i])
			error("erreur de malloc");
		ft_memset(img->a_img[i], 0, (sizeof(int) * TEXWIDTH * TEXHEIGHT));
		i++;
	}
}

void	draw_floor_and_ceiling(void)
{
	int	i;
	int	j;

	i = 0;
	while (i < HEIGHT / 2)
	{
		j = 0;
		while (j < WIDTH)
		{
			data()->img->buffer[i][j] = data()->map->ceiling;
			data()->img->buffer[HEIGHT - i - 1][j] = data()->map->floor;
			j++;
		}
		i++;
	}	
}

void	draw_frame(void)
{
	int	y;
	int	x;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			data()->img->data[y * WIDTH + x] = data()->img->buffer[y][x];
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(data()->mlx, data()->win, data()->img->img, 0, 0);
}
