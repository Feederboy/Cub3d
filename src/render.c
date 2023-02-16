#include "cub3d.h"

void	paint_floor()
{
	int	i;
	int	j;

	i = 0;
	while (i < HEIGHT / 2)
	{
		j = 0;
		while (j < WIDTH)
		{
			data()->img->buffer[i][j] = data()->map->celling;
			data()->img->buffer[HEIGHT - i - 1][j] = data()->map->floor;
			j++;
		}
		i++;
	}	
}

void	paint_img()
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