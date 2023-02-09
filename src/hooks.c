#include "cub3d.h"


int	game_loop()
{
	paint_floor();
	raycasting();
	paint_img();
	key_hook();
	return (0);
}

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
	if (keycode == K_ESC || keycode == 65307)
		ft_close();
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
	return (0);
}

int ft_close()
{
    mlx_destroy_image(data()->mlx, data()->img->img);
	mlx_destroy_window(data()->mlx, data()->win);
	mlx_destroy_display(data()->mlx);
    error("closing\n");
    return (1);
}