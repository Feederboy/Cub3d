#include "cub3d.h"

// int    floodfill(int x, int y)
// {
//     	if (y < 0 || x < 0 || !data()->map->map_split[y] || (data()->map->map_split[y] && !data()->map->map_split[y][x]))
// 		return (1);

//     if (data()->map->map_split[x][y] && data()->map->map_split[x][y] == '1')
//     {
//         if (data()->map->map_split[x-1][y])
//             floodfill(x - 1, y);
//         if (data()->map->map_split[x][y + 1])
//             floodfill(x, y + 1);
//         if (data()->map->map_split[x][y - 1])
//             floodfill(x, y - 1);
//         if (data()->map->map_split[x + 1][y])
//             floodfill(x + 1, y);
//         data()->map->map_split[x][y] = 'F';
//     }
//     return (0);

// }

// void floodFill(int x,int y,int oldcolor,int newcolor)
// {
// if(getpixel(x,y) == oldcolor)
// {
// putpixel(x,y,newcolor);
// floodFill(x+1,y,oldcolor,newcolor);
// floodFill(x,y+1,oldcolor,newcolor);
// floodFill(x-1,y,oldcolor,newcolor);
// floodFill(x,y-1,oldcolor,newcolor);
// }
// }

// void floodfill(int x,int y,char c, char n)
// {
//     data()->map->map_split[x][y] = 'X';
//     printf("COORD X = %d   Y = %d === %c\n", x, y, c);
//     if(data()->map->map_split[x][y] && data()->map->map_split[x][y] != c &&)
//     {

        
//         data()->map->map_split[x][y] = n;
//         if (x < data()->map->cols)
//             floodfill(x+1,y,c ,n);
//         if (y < data()->map->rows)
//             floodfill(x,y+1,c,n);
//         if (x > 0)
//             floodfill(x-1,y,c,n);
//         if (y > 0)
//             floodfill(x,y-1,c,n);
//     }
// }
// #include <stdio.h>

// int	check_open_wall(char **array, int x, int y)
// {
// 	FILE *fp = fopen("res.txt", "a");
// 	fprintf(fp, "[x = %d, y = %d]", x , y);
	
// 	if (y < 0 || x < 0 || !array[x] || (array[x] && !array[x][y]))
// 		return (1);
// 	else if (array[x][y] == '1')
// 		return (0);
// 	array[x][y] = '1';
// 	// fprintf(fp, print_map(array));
// 	return (check_open_wall(array, x - 1, y)
// 		+ check_open_wall(array, x + 1, y)
// 		+ check_open_wall(array, x, y - 1)
// 		+ check_open_wall(array, x, y + 1));
// }


// int	loop_open_walls(char **dup)
// {
// 	int	i;
// 	int	j;

// 	i = 0;
// 	while (dup[i])
// 	{
// 		j = 0;
// 		while (dup[i][j])
// 		{
// 			// printf("i = %d    j = %d\n",i, j);
// 			printf("+++++++++  x = %d, y = %d +++++\n", i, j);
// 			if (dup[i][j] == '0' && check_open_wall(dup, i, j))
// 			{
// 				return (-1);
// 			}
// 			j++;
// 		}
// 		i++;
// 	}
// 	return (0);
// }


// static bool	floodfill(t_game *game, bool **filled_map, int i, int j)
// {
// 	bool	is_surrounded;

// 	if (i < 0 || i >= game->map_row || j < 0 || j >= game->map_col)
// 		return (false);
// 	if (game->map[i][j] == '1' || filled_map[i][j] == true)
// 		return (true);
// 	else
// 		filled_map[i][j] = true;
// 	is_surrounded = true;
// 	is_surrounded &= floodfill(game, filled_map, i - 1, j);
// 	is_surrounded &= floodfill(game, filled_map, i + 1, j);
// 	is_surrounded &= floodfill(game, filled_map, i, j - 1);
// 	is_surrounded &= floodfill(game, filled_map, i, j + 1);
// 	return (is_surrounded);
// }

// int			check_map_surrounded(t_game *game)
// {
// 	int		x;
// 	int		y;
// 	int		i;
// 	bool	**filled_map;
// 	bool	is_surrounded;

// 	x = game->player.pos.x;
// 	y = game->player.pos.y;
// 	filled_map = ft_calloc(game->map_row + 1, sizeof(bool*));
// 	i = 0;
// 	while (i < game->map_row)
// 	{
// 		filled_map[i] = ft_calloc(game->map_col, sizeof(bool));
// 		if (!filled_map[i])
// 		{
// 			free_ptrarr((void**)filled_map);
// 			return (put_and_return_err("Malloc is failed"));
// 		}
// 		i++;
// 	}
// 	is_surrounded = floodfill(game, filled_map, y, x);
// 	free_ptrarr((void**)filled_map);
// 	if (!is_surrounded)
// 		return (put_and_return_err("Map isn't surrounded by wall"));
// 	return (0);
// }


// char	*check_direction_deep(char *line)
// {
// 	int		fd;
// 	char	*rt;

// 	rt = NULL;
// 	line += 2;
// 	while (ft_isspace(*line))
// 		line++;
// 	fd = open(line, O_RDONLY);
// 	if (fd == -1)
// 		return (NULL);
// 	close(fd);
// 	rt = ft_strdup(line);
// 	return (rt);
// }

// int	check_direction(t_map *map, char *line, char c)
// {
// 	char	*tmp;

// 	tmp = check_direction_deep(line);
// 	if (!tmp)
// 		return (0);
// 	if (c == 'N' && map->no_path == NULL)
// 		map->no_path = tmp;
// 	else if (c == 'S' && map->so_path == NULL)
// 		map->so_path = tmp;
// 	else if (c == 'W' && map->we_path == NULL)
// 		map->we_path = tmp;
// 	else if (c == 'E' && map->ea_path == NULL)
// 		map->ea_path = tmp;
// 	else
// 		ft_exit("Problemes NWSE \n", map, line);
// 	return (1);
// }


static bool	floodfill(bool **filled_map, int i, int j)
{
	bool	is_surrounded;

	if (i < 0 || i >= data()->map->rows || j < 0 || j >= data()->map->cols)
		return (false);
	if (data()->map->map_split[i][j] == '1' || filled_map[i][j] == true)
		return (true);
	else
		filled_map[i][j] = true;
	is_surrounded = true;
	is_surrounded &= floodfill(filled_map, i + 1, j);
	is_surrounded &= floodfill(filled_map, i, j - 1);
	is_surrounded &= floodfill(filled_map, i, j + 1);
	is_surrounded &= floodfill(filled_map, i - 1, j);
	return (is_surrounded);
}

void		check_map_surrounded()
{
	int		i;
	bool	**filled_map;
	bool	is_surrounded;

	filled_map = ft_calloc(data()->map->rows + 1, sizeof(bool*));
	i = 0;
	while (i < data()->map->rows)
	{
		filled_map[i] = ft_calloc(data()->map->cols, sizeof(bool));
		if (!filled_map[i])
		{
			error("fill_map calloc failed\n");
		}
		i++;
	}
	is_surrounded = floodfill(filled_map, data()->map->player_posx, data()->map->player_posy);
	if (!is_surrounded)
		error("Map not surrounded\n");
	else
		printf("MAP IS SURROUNDED\n");

}