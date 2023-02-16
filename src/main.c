/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maquentr <maquentr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 23:40:58 by ykeciri           #+#    #+#             */
/*   Updated: 2023/02/16 15:34:51 by maquentr         ###   ########.fr       */
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
		printf("MAIN MLX ELSE1\n");
		game_start();
		printf("MAIN MLX ELSE2\n");
		data()->img->img = mlx_new_image(data()->mlx, WIDTH, HEIGHT);
		printf("MAIN MLX ELSE3\n");
		data()->img->data = (int *)mlx_get_data_addr(data()->img->img, &data()->img->bpp,
				&data()->img->line_size, &data()->img->endian);
		printf("MAIN MLX ELSE4\n");
		mlx_hook(data()->win, 17, 0, &ft_close, &data);
		printf("MAIN MLX ELSE5\n");
		mlx_hook(data()->win, 2, 1L << 0, &key_press, &data);
		printf("MAIN MLX ELSE6\n");
		mlx_hook(data()->win, 2, 1L << 0, &key_release, &data);
		printf("MAIN MLX ELSE7\n");
		mlx_loop_hook(data()->mlx, &game_loop, &data);
		printf("MAIN MLX ELSE8\n");
		mlx_loop(data()->mlx);
		printf("MAIN MLX ELSE9\n");
		ft_close();
	}
	return (0);
}
