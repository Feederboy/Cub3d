/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maquentr <maquentr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 23:40:58 by ykeciri           #+#    #+#             */
/*   Updated: 2023/02/15 12:04:27 by maquentr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	end_game(int exit_code)
{
	//if (data()->map_str != NULL)
	//	(free(data()->map_str), ft_freematrix(g->matrix));
	//free_images(g);
	if (data()->mlx)
	{
		mlx_clear_window(data()->mlx, data()->win);
		mlx_destroy_window(data()->mlx, data()->win);
		mlx_destroy_display(data()->mlx);
		free(data()->mlx);
	}
	exit(exit_code);
	return (0);
}

void error(char *msg)
{
	ft_printf_fd(2, "Error\n%s\n", msg);
	end_game(1);
}

void check_arguments(int ac, char **av)
{
	int file_len;

	if (ac > 2)
		error(ERR_TOO_MUCH_ARGS);
	if (ac < 2)
		error(ERR_MISSING_ARGS);
	file_len = ft_strlen(av[1]);
	if (!ft_strnstr(&av[1][file_len - 4], ".cub", 4))
		error(ERR_BAD_EXTENSION);
}

int main(int ac, char **av)
{
	// t_data dat;
	check_arguments(ac, av);
	data()->filename = av[1];
	data()->fd = open(data()->filename, O_RDONLY);
	char *tmp;
	tmp = get_next_line(data()->fd);
	printf("MAIN TMP = %s", tmp);
	while (tmp)
	{
		tmp = get_next_line(data()->fd);
		printf("MAIN TMP = %s", tmp);
	}
	printf("MAIN TMP = %s", tmp);
	if (parsing_map())
		error("something went wrong with the map\n");
	else
	{
		game_start();
		data()->img->img = mlx_new_image(data()->mlx, WIDTH, HEIGHT);
		data()->img->data = (int *)mlx_get_data_addr(data()->img->img, &data()->img->bpp,
				&data()->img->line_size, &data()->img->endian);
		mlx_hook(data()->win, 17, 0, &ft_close, &data);
		mlx_hook(data()->win, 2, 1L << 0, &key_press, &data);
		mlx_hook(data()->win, 2, 1L << 0, &key_release, &data);
		mlx_loop_hook(data()->mlx, &game_loop, &data);
		mlx_loop(data()->mlx);
		// ft_close(game.mlx);
	}
	return (0);
}
