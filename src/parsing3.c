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


int	check_open_wall(char **array, int y, int x)
{
	if (y < 0 || x < 0 || !array[y] || (array[y] && !array[y][x]))
		return (1);
	else if (array[y][x] == '1')
		return (0);
	array[y][x] = '1';
	return (check_open_wall(array, y - 1, x)
		+ check_open_wall(array, y + 1, x)
		+ check_open_wall(array, y, x - 1)
		+ check_open_wall(array, y, x + 1));
}


int	loop_open_walls(char **dup)
{
	int	i;
	int	j;

	i = 0;
	while (dup[i])
	{
		j = 0;
		while (dup[i][j] != '\n')
		{
			if (dup[i][j] == '0' && check_open_wall(dup, i, j))
			{
				return (-1);
			}
			j++;
		}
		i++;
	}
	return (0);
}
