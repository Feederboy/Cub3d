#include"cub3d.h"


void	key_arrow_left()
{
	double	olddir;
	double	oldplane;

	olddir = data()->p->dir_y;
	oldplane = data()->p->plane_y;
	data()->p->dir_y = data()->p->dir_x * sin(-(data()->p->rot_speed)) + data()->p->dir_y * cos(-(data()->p->rot_speed));
	data()->p->dir_x = data()->p->dir_x * cos(-(data()->p->rot_speed)) - olddir * sin(-(data()->p->rot_speed));
	data()->p->plane_y = data()->p->plane_x * sin(-(data()->p->rot_speed))
		+ data()->p->plane_y * cos(-(data()->p->rot_speed));
	data()->p->plane_x = data()->p->plane_x * cos(-(data()->p->rot_speed))
		- oldplane * sin(-(data()->p->rot_speed));
}
/*
**	We use vector rotation formula
**	Difference between two functions it for the left we put rotspeed to negative
*/

/*
**	rotate to the right
*/
void	key_arrow_right()
{
	double	olddir;
	double	oldplane;

	olddir = data()->p->dir_y;
	oldplane = data()->p->plane_y;
	data()->p->dir_y = data()->p->dir_x * sin(data()->p->rot_speed) + data()->p->dir_y * cos(data()->p->rot_speed);
	data()->p->dir_x = data()->p->dir_x * cos(data()->p->rot_speed) - olddir * sin(data()->p->rot_speed);
	data()->p->plane_y = data()->p->plane_x * sin(data()->p->rot_speed)
		+ data()->p->plane_y * cos(data()->p->rot_speed);
	data()->p->plane_x = data()->p->plane_x * cos(data()->p->rot_speed)
		- oldplane * sin(data()->p->rot_speed);
}

void	key_w()
{
	double	x_vec;
	double	y_vec;

	x_vec = data()->p->dir_x * data()->p->move_speed;
	y_vec = data()->p->dir_y * data()->p->move_speed;
	if (data()->map->map_split[(int)(data()->p->pos_y)][(int)(data()->p->pos_x + x_vec * WALLDIST)] == '0') //MAP SPLIT ?????
		data()->p->pos_x += x_vec;
	if (data()->map->map_split[(int)(data()->p->pos_y + y_vec * WALLDIST)][(int)(data()->p->pos_x)] == '0')
		data()->p->pos_y += y_vec;
}

/*
**	move backwards if no wall behind you
*/
void	key_s()
{
	double	x_vec;
	double	y_vec;

	x_vec = data()->p->dir_x * data()->p->move_speed;
	y_vec = data()->p->dir_y * data()->p->move_speed;
	if (data()->map->map_split[(int)(data()->p->pos_y)][(int)(data()->p->pos_x - x_vec * WALLDIST)] == '0')
		data()->p->pos_x -= x_vec;
	if (data()->map->map[(int)(data()->p->pos_y - y_vec * WALLDIST)][(int)(data()->p->pos_x)] == '0')
		data()->p->pos_y -= y_vec;
}

/*
**	move left if no wall to your left
*/
void	key_a()
{
	double	x_vec;
	double	y_vec;

	x_vec = data()->p->dir_x * data()->p->move_speed;
	y_vec = data()->p->dir_y * data()->p->move_speed;
	if (data()->map->map_split[(int)(data()->p->pos_y)][(int)(data()->p->pos_x + y_vec * WALLDIST)] == '0')
		data()->p->pos_x += y_vec;
	if (data()->map->map[(int)(data()->p->pos_y - x_vec * WALLDIST)][(int)(data()->p->pos_x)] == '0')
		data()->p->pos_y -= x_vec;
}

/*
**	move right if no wall to your right
*/
void	key_d()
{
	double	x_vec;
	double	y_vec;

	x_vec = data()->p->dir_x * data()->p->move_speed;
	y_vec = data()->p->dir_y * data()->p->move_speed;
	if (data()->map->map[(int)(data()->p->pos_y)][(int)(data()->p->pos_x - y_vec * WALLDIST)] == '0')
		data()->p->pos_x -= y_vec;
	if (data()->map->map[(int)(data()->p->pos_y + x_vec * WALLDIST)][(int)(data()->p->pos_x)] == '0')
		data()->p->pos_y += x_vec;
}

/*
**	manage key hook
*/
int	key_hook()
{
	if (data()->move->key_w && !data()->move->key_s)
		key_w();
	if (data()->move->key_s && !data()->move->key_w)
		key_s();
	if (data()->move->key_a && !data()->move->key_d)
		key_a();
	if (data()->move->key_d && !data()->move->key_a)
		key_d();
	if (data()->move->arr_l && !data()->move->arr_r)
		key_arrow_left();
	if (data()->move->arr_r && !data()->move->arr_l)
		key_arrow_right();
	return (1);
}
