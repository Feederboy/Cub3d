/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguerra <mguerra@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 23:40:58 by ykeciri           #+#    #+#             */
/*   Updated: 2022/07/16 23:12:46 by mguerra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	handle_key(int keycode, void *param)
{
	(void)param;
	printf("key : %d\n", keycode);
	if (keycode == ESCAPE)
		end_game(0);
	//if (keycode == RESTART)
	//	restart_game();
	//if (game()->final_state == 1)
	//	return (0);
	//if (keycode == TOP || keycode == TOP_A)
	//	go_top();
	//if (keycode == BOTTOM || keycode == BOTTOM_A)
	//	go_bottom();
	//if (keycode == LEFT || keycode == LEFT_A)
	//	go_left();
	//if (keycode == RIGHT || keycode == RIGHT_A)
	//	go_right();
	return (0);
}

void init_map(void)
{
	data()->mlx = mlx_init();
	if (!data()->mlx)
		error(ERR_MLX_INIT);
	mlx_get_screen_size(data()->mlx, &data()->max_w, &data()->max_h);

	data()->win = mlx_new_window(data()->mlx, 1000, 800, "cub3D");
	if (!data()->win)
		error(ERR_WIN_INIT);
	// Handle Escape
	mlx_hook(data()->win, 17, 0L, end_game, 0);
	// Handle Keypress not KeyRelease
	
	mlx_hook(data()->win, 2, 1L << 0, handle_key, 0);
	data()->init = 1;
	//render(game());
	//mlx_loop_hook(data()->mlx, animate, game());
	mlx_loop(data()->mlx);
}