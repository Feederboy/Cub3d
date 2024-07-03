/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maquentr <maquentr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 15:29:27 by mguerra           #+#    #+#             */
/*   Updated: 2023/02/21 19:43:36 by maquentr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_data	*data(void)
{
	static t_data	data;

	if (data.setup != 1)
	{
		data.setup = 1;
		data.img = (t_img *)gc_malloc(sizeof(t_img));
		data.map = (t_map *)gc_malloc(sizeof(t_map));
		data.p = (t_player *)gc_malloc(sizeof(t_player));
		data.move = (t_move *)gc_malloc(sizeof(t_move));
		data.ray = (t_ray *)gc_malloc(sizeof(t_ray));
		data.p->status = -1;
		init_map(data.map);
		init_img(data.img);
	}
	return (&data);
}

void	check_arguments(int ac, char **av)
{
	if (ac > 2)
		error(ERR_TOO_MUCH_ARGS);
	if (ac < 2)
		error(ERR_MISSING_ARGS);
	if (!ft_strnstr(&av[1][ft_strlen(av[1]) - 4], ".cub", 4))
		error(ERR_BAD_EXTENSION);
}

// debug_data();
int	game_loop(void)
{
	draw_floor_and_ceiling();
	raycasting();
	draw_frame();
	key_hook();
	return (0);
}

void	init_game(void)
{
	t_data	*d;

	d = data();
	d->mlx = mlx_init();
	if (!data()->mlx)
		error("mlx error\n");
	d->win = mlx_new_window(data()->mlx, WIDTH, HEIGHT, "cub3D");
	if (!data()->win)
		error("window error\n");
	init_image();
	load_image();
	init_player();
	init_move();
	d->img->img = mlx_new_image(d->mlx, WIDTH, HEIGHT);
	d->img->data = (int *)mlx_get_data_addr(d->img->img, &d->img->bpp, \
		&d->img->line_size, &d->img->endian);
	mlx_hook(data()->win, 17, 0, &end_game, &data);
	mlx_hook(data()->win, 2, 1L << 0, &key_press, &data);
	mlx_hook(data()->win, 3, 1L << 1, &key_release, &data);
	mlx_loop_hook(data()->mlx, &game_loop, &data);
	mlx_loop(data()->mlx);
}

int	main(int ac, char **av)
{
	check_arguments(ac, av);
	parse_map(av[1]);
	check_player();
	init_game();
	return (0);
}
