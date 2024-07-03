/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguerra <mguerra@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 23:40:58 by ykeciri           #+#    #+#             */
/*   Updated: 2023/02/16 23:02:29 by mguerra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# include <stdio.h>
# include <unistd.h>
# include <stdbool.h>
# include <stdlib.h>
# include <math.h>
# include <fcntl.h>
# include "../lib/mlx/mlx.h"
# include "../lib/libft/includes/libft.h"
# include "../lib/libft/includes/ft_printf.h"

# define ERR_TOO_MUCH_ARGS "Too many arguments, only one map is allowed."
# define ERR_MISSING_ARGS "Map path is missing."
# define ERR_BAD_EXTENSION "The map extension is incorrect, it should be .cub."
# define ERR_BAD_FILE "The map file cannot be opened."
//# define ERR_MLX_INIT "Cannot init MLX, aborting."
//# define ERR_WIN_INIT "Cannot create a window, aborting."

# define TEXWIDTH 64
# define TEXHEIGHT 64
# define WIDTH 960
# define HEIGHT 720
# define WALLDIST 1.1

# define E 0
# define W 1
# define S 2
# define N 3

# define K_W 119
# define K_A 97
# define K_S 115
# define K_D 100
# define K_AR_L 65361
# define K_AR_R 65363
# define K_ESC 65307



typedef struct s_map
{
	int		floor;
	int		ceiling;
	char	*no;
	char	*so;
	char	*we;
	char	*ea;
	char	*map_str;
	char	**map;
	char	*paths[4];
	int		player_x;
	int		player_y;
	int		cols;
	int		rows;
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
	int			**a_img;
}				t_img;

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
	double		rot_s;
}				t_player;

typedef struct s_move
{
	int	key_w;
	int	key_s;
	int	key_a;
	int	key_d;
	int	arr_l;
	int	arr_r;
}			t_move;


typedef struct s_ray
{
	int		map_x;
	int		map_y;
	double	d_x;
	double	d_y;
	double	sidedist_x;
	double	sidedist_y;
	double	dd_x;
	double	dd_y;
	double	w_dist;
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

typedef struct s_data
{
	int			setup;
	t_map		*map;
	void		*mlx;
	void		*win;
	t_img		*img;
	t_player	*p;
	t_move		*move;
	t_ray		*ray;

}	t_data;

void	init_map(t_map *map);


void	init_img(t_img *img);
void	init_move();

void	init_player();
void	init_image();

void	load_image(void);

void	parse_map(char *path);

void	error(char *msg);


void check_player();

void	draw_floor_and_ceiling();

void	draw_frame();


void	debug_data(void);


int	key_press(int keycode);

int	key_release(int keycode);

void	key_arrow_left(void);

void	key_arrow_right(void);

int	end_game(int exit_code);
//typedef struct s_vect
//{
//	double	x;
//	double	y;
//}	t_vect;

//typedef struct s_rgb
//{
//}			t_rgb;


//typedef struct s_map
//{
//	char **map;
//	char **map_split;
//	t_vect pos;
//	t_vect dir;
//	int	rows;
//	int	cols;
//	int	is_valid;
//	int card;
//	int	player_posx;
//	int	player_posy;
//	char		**mapp;
//	char		*no_path;
//	char		*so_path;
//	char		*we_path;
//	char		*ea_path;
//	int			floor;
//	int			celling;
//	int			r;
//	int			g;
//	int			b;
//	int			width;
//	int			height;
//	int			mcount;
//	int			start;
//	// int			ret;
	
//}	t_map;





//t_data	*data(void);

///*parsing.c*/

//int	parsing_map(void);
//void  clo_ope();
///*parsing2.c*/

//int check_textures_order();
//int	check_tiles();

///*parsing3.c*/
//void	check_map_surrounded();

///*utils.c*/
//int	get_nb_row();
//// int	get_nb_col();
//int	get_nb_row_splitted();
//int	get_nb_col_splitted();

///*raycasting.c*/

t_data	*data(void);
void	dda_calc();
void	mapping_buff();
void	set_buff(int x);
void	raycasting();

///*raycasting2.c*/
void	sidedist_init();
void	ray_init(int x);



int ft_close();

int	key_press(int keycode);

int	key_release(int keycode);

int	key_hook();
///*game.c*/
//void	init_image();
//void	fill_a_img(int i);
//void	load_img();
//void	game_start();

///*init.c*/
//void	init_player();
//void	init_map();
//void	init_img();
//void	init_move();

///*hooks.c*/
//int	game_loop();
//int	key_press(int keycode);
//int	key_release(int keycode);
//int	ft_close();

///*keys.c*/
//void	key_arrow_left();
//void	key_arrow_right();
//void	key_w();
//void	key_s();
//void	key_a();
//void	key_d();
//int	key_hook();

///*render.c*/
//void	draw_floor_and_ceiling();
//void	draw_frame();


//void print_map(char **map);
//void error(char *msg);
//void free_map(char **map);

//int	end_game(int exit_code);

#endif
