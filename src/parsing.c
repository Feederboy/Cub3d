/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maquentr <maquentr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 22:36:13 by matt              #+#    #+#             */
/*   Updated: 2023/01/26 15:50:28 by maquentr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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
	printf("MAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAP ADDREEEEEEEEEEEEEEEEEEESS %p\n", data()->map);
	data()->map->rows = get_nb_row() + 2;
	printf("GETNBROW = %d\n", data()->map->rows);
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


static char	**split_map()
{
	char *tmp;
	char **res;
	int l;
	int i;
	
	l = 1;
	i = 0;
	tmp = get_next_line(data()->fd);
	while (tmp && (*tmp != '1' && *tmp != ' ' && *tmp != '0'))
	{
		printf("TMPPPP = %c   TMPPPP+1 = %c\n", *tmp, *(tmp + 1));
		tmp = get_next_line(data()->fd);
	}
	while (tmp && *(tmp + 1) && (tmp[0]!= '1' && tmp[0] != '0' && tmp[0] != ' '))
	{
		printf("TMP = %c   TMP+1 = %c\n", *tmp, *(tmp + 1));
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

int parsing_map(void)
{
	data()->fd = open(data()->filename, O_RDONLY);

	data()->map->map = fill_map();
	printf("\n\n\nFILL MAP PRINT\n");
	print_map(data()->map->map);

	clo_ope();
	if (check_textures_order())
		error("Textures given not good\n");
	data()->map->map_split = split_map();
	printf("\n\n\nSPLIT MAP PRINT\n");
	print_map(data()->map->map_split);

	check_tiles();
	printf("**************** START FLOODFILL **********\n");
	print_map(data()->map->map_split);
	// floodfill(0, 0);
	loop_open_walls(data()->map->map_split);
	printf("**************** END FLOODFILL **********\n");
	print_map(data()->map->map_split);
	close(data()->fd);
	free_map(data()->map->map);
	return (0);
}