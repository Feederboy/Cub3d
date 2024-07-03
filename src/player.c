/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maquentr <maquentr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 20:42:37 by mguerra           #+#    #+#             */
/*   Updated: 2023/02/17 16:15:52 by mguerra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static bool	floodfill(bool **filled_map, int i, int j)
{
	bool	is_surrounded;

	if (i < 0 || i >= data()->map->rows || j < 0 || j >= data()->map->cols)
		return (false);
	if (data()->map->map[i][j] == '1' || filled_map[i][j] == true)
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

static void	check_map_surrounded(void)
{
	int		i;
	bool	**filled_map;
	bool	is_surrounded;

	filled_map = gc_calloc(data()->map->rows + 1, sizeof(bool *));
	i = 0;
	while (i < data()->map->rows)
	{
		filled_map[i] = gc_calloc(data()->map->cols, sizeof(bool));
		if (!filled_map[i])
			error("fill_map calloc failed\n");
		i++;
	}
	is_surrounded = floodfill(filled_map, data()->p->pos_y, data()->p->pos_x);
	if (!is_surrounded)
		error("Map not surrounded\n");
}

static int	get_player_dir(char c)
{
	if (c == 'W')
		return (W);
	else if (c == 'N')
		return (N);
	else if (c == 'S')
		return (S);
	else if (c == 'E')
		return (E);
	return (-1);
}

static void	check_player_dir(char c, int x, int y)
{
	if (ft_strchr("NSWE", c))
	{
		if (data()->p->status != -1)
			error("Multiple starting position");
		else
		{
			data()->p->pos_x = x + 0.5;
			data()->p->pos_y = y + 0.5;
			data()->p->status = get_player_dir(c);
			data()->map->map[y][x] = '0';
		}
	}
}

void	check_player(void)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (data()->map->map[i])
	{
		j = 0;
		while (data()->map->map[i][j])
		{
			check_player_dir(data()->map->map[i][j], j, i);
			if (!ft_strchr("NSWE01 ", data()->map->map[i][j]))
				error("Invalid map character");
			j++;
		}
		if (j > data()->map->cols)
			data()->map->cols = j + 1;
		i++;
	}
	if (data()->p->status == -1)
		error("No starting position");
	data()->map->rows = i;
	check_map_surrounded();
}
