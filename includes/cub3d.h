/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maquentr <maquentr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 23:40:58 by ykeciri           #+#    #+#             */
/*   Updated: 2023/02/08 13:05:55 by maquentr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# include <stdio.h>
# include <unistd.h>
# include <stdbool.h>
# include <stdlib.h>
# include <math.h>
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

# define TEXWIDTH 64
# define TEXHEIGHT 64
# define WIDTH 960
# define HEIGHT 720
# define WALLDIST 1.1

# define E 1
# define W 2
# define S 3
# define N 4

# define K_W 119
# define K_A 97
# define K_S 115
# define K_D 100
# define K_AR_L 65361
# define K_AR_R 65363
# define K_ESC 65307

typedef struct s_vect
{
	double	x;
	double	y;
}	t_vect;

typedef struct s_rgb
{
	int		r;
	int		g;
	int		b;
}			t_rgb;

typedef struct s_move
{
	int	key_w;
	int	key_s;
	int	key_a;
	int	key_d;
	int	arr_l;
	int	arr_r;
}			t_move;

typedef struct s_map
{
	char **map;
	char **map_split;
	t_vect pos;
	t_vect dir;
	int	rows;
	int	cols;
	int	is_valid;
	int card;
	int	player_posx;
	int	player_posy;
	char		**map;
	char		*no_path;
	char		*so_path;
	char		*we_path;
	char		*ea_path;
	int			floor;
	int			celling;
	int			width;
	int			height;
	int			mcount;
	int			start;
	int			ret;
	
}	t_map;

typedef struct s_img
{
	void		*img;
	int			*data;
	int			bpp;
	int			line_size;
	int			endian;
	int			w;
	int			h;
	int			buffer[HEIGHT][WIDTH];
	int			**arr_img;
}				t_img;

typedef struct s_ray
{
	int		map_x;
	int		map_y;
	double	raydir_x;
	double	raydir_y;
	double	sidedist_x;
	double	sidedist_y;
	double	deltadist_x;
	double	deltadist_y;
	double	perpwalldist;
	int		step_x;
	int		step_y;
	int		side;
	int		tex_x;
	int		tex_y;
	int		line_h;
	int		start;
	int		end;
	double	ratio;
	double	texpos;
}			t_ray;

typedef struct s_player
{
	int			status;
	double		pos_x;
	double		pos_y;
	double		dir_x;
	double		dir_y;
	double		plane_x;
	double		plane_y;
	double		move_speed;
	double		rot_speed;
}				t_player;

typedef struct s_data
{
	int setup;
	int init;
	char *filename;
	int	fd;
	t_map *map;
	t_ray *ray;
	t_player *p;
	t_img *img;
	t_move *move;

	void		*mlx;
	void		*win;
	int			max_w;
	int			max_h;

}	t_data;

t_data	*data(void);

/*parsing.c*/

int	parsing_map(void);
void  clo_ope();
/*parsing2.c*/

int check_textures_order();
int	check_tiles();

/*parsing3.c*/
int	check_map_surrounded();

/*utils.c*/
int	get_nb_row();
// int	get_nb_col();
int	get_nb_row_splitted();
int	get_nb_col_splitted();

/*raycasting.c*/
void	dda_calc();
void	mapping_buff();
void	set_buff(int x);
void	raycasting();

/*raycasting2.c*/
void	sidedist_init();
void	ray_init(int x);


void	init_map(void);

void print_map(char **map);
void error(char *msg);
void free_map(char **map);

int	end_game(int exit_code);

#endif
