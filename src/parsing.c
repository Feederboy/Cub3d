/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maquentr <maquentr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 22:36:13 by matt              #+#    #+#             */
/*   Updated: 2023/01/25 16:52:31 by maquentr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void print_map(char **map)
{
	int i = 0;

	printf("\n_____________PRINT MAP____________\n\n");
	while (map[i])
	{
		printf("[%s", map[i]);
		i++;
	}
	printf("\n--------------END PRINT MAP------------\n\n");
}

static void free_map(char **map)
{
	int i;

	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}

static int get_nb_row()
{
	int len;
	char *tmp;
	int fd;

	fd = data()->fd;
	len = 0;
	tmp = "";
	while (tmp != NULL)
	{
		tmp = get_next_line(fd);
		if (tmp == NULL)
			break;
		len++;
		free(tmp);
	}
	return (len);
}

static void	clo_ope()
{
	close(data()->fd);
	data()->fd = open(data()->filename, O_RDONLY);
}

static char	**fill_map()
{
	char **res;
	int i;
	int fd;
	char *tmp;

	fd = data()->fd;
	data()->map->rows = get_nb_row() + 1;
	clo_ope();
	tmp = "";
	i = 0;
	res = gc_malloc(sizeof(char *) * (data()->map->rows));
	if (!res)
		return (NULL);
	while (tmp)
	{
		tmp = get_next_line(data()->fd);
		res[i] = gc_strdup(tmp);
		i++;
	}
	return (res);
}

static int	check_next_char(char *tmp)
{
	if (*tmp == 'N' && *(tmp + 1) != 'O')
		return (1);
	if (*tmp == 'S' && *(tmp + 1) != 'O')
		return (1);
	if (*tmp == 'W' && *(tmp + 1) != 'E')
		return (1);
	if (*tmp == 'E' && *(tmp + 1) != 'A')
		return (1);
	return (0);
}

static char	**split_map()
{
	char *tmp;
	char **res;
	int l;
	int i;
	
	l = 1;
	i = 0;
	tmp = get_next_line(data()->fd);
	while (tmp && *(tmp + 1) && (tmp[0]!= '1' && tmp[0] != '0' && tmp[0] != ' '))
	{
		printf("TMP = %c   TMP+1 = %c\n", *tmp, *(tmp + 1));
		if (check_next_char(tmp))
			error("Wrong texture given\n");
		if (check_FC_vals(tmp))
			error("wrong FC\n");
		tmp = get_next_line(data()->fd);
		l++;
	}
	
	res = malloc(sizeof(char *) * (data()->map->rows - l - 1));
	if (!res)
		return (NULL);
	res[i] = gc_strdup(tmp);
	i++;
	while (tmp)
	{	
		tmp = get_next_line(data()->fd);
		res[i] = gc_strdup(tmp);

		i++;
	}
	tmp = get_next_line(data()->fd);
	res[i] = gc_strdup(tmp);
	return (res);
}



/* CHECK ORDRE STRICT DES PARAM PRE MAP 
	CHECK RANGE RGB [0, 255]
	CHECK SI MAP EXISTE */

int parsing_map(void)
{
	data()->fd = open(data()->filename, O_RDONLY);

	data()->map->map = fill_map();
	printf("\n\n\nFILL MAP PRINT\n");
	print_map(data()->map->map);

	clo_ope();
	if (order_of_textures())
		return (1);
	data()->map->map_split = split_map();
	printf("\n\n\nSPLIT MAP PRINT\n");
	print_map(data()->map->map_split);

	check_tiles();

	close(data()->fd);
	free_map(data()->map->map);
	return (0);
}