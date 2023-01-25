/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maquentr <maquentr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 23:40:58 by ykeciri           #+#    #+#             */
/*   Updated: 2023/01/25 16:50:01 by maquentr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include "../lib/mlx/mlx.h"
# include "../lib/libft/includes/libft.h"
# include "../lib/libft/includes/ft_printf.h"
# include "../lib/libft/includes/get_next_line.h"

# define ERR_TOO_MUCH_ARGS "Too many arguments, only one map is allowed."
# define ERR_MISSING_ARGS "The path to the map is missing."
# define ERR_BAD_EXTENSION "The map extension is incorrect, go rename to .cub."
# define ERR_MLX_INIT "Cannot init MLX, aborting."
# define ERR_WIN_INIT "Cannot create a window, aborting."
# define ESCAPE 65307

typedef struct s_vect
{
	double	x;
	double	y;
}	t_vect;

typedef struct s_map
{
	char **map;
	char **map_split;
	t_vect pos;
	t_vect dir;
	int	rows;
	int	cols;
	int	is_valid;
	int n;
	int s;
	int e;
	int w;
	int card;
	
}	t_map;

typedef struct s_data
{
	int setup;
	int init;
	char *filename;
	int	fd;
	t_map *map;

	void		*mlx;
	void		*win;
	int			max_w;
	int			max_h;

}	t_data;


t_data	*data(void);

/*parsing*/
int	parsing_map(void);
int	check_tiles();
void print_map(char **map);



void	init_map(void);

void error(char *msg);

int	end_game(int exit_code);

#endif
