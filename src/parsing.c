/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maquentr <maquentr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 22:36:13 by matt              #+#    #+#             */
/*   Updated: 2023/02/08 08:20:31 by maquentr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	clo_ope()
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
	data()->map->rows = get_nb_row() + 2;
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
		tmp = get_next_line(data()->fd); // FREEE TMPPPPPPPPP ????????????
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

static void	get_sizes()
{
	clo_ope();
	data()->map->rows = get_nb_row_splitted();
	data()->map->cols = get_nb_col_splitted();
	printf("MAIN ROWS = %d   MAIN COLS = %d\n", data()->map->rows, data()->map->cols);
}

//LA MAP PEUT COMMENCER PAR DU VIDE ET AVOIR LES MURS DECALES VERS LA DROITE, PARSER EN ACCORD. VOIR MAP DU SUJET (osef ? car on commence a partir du cardinal)

//FREE LES TMP DE GNL ??????????????????

//Mis à part la description de la map, chaque type d’élément peut être séparée
//par une ou plusieurs lignes vides.

//Sauf pour la map elle-même, les informations de chaque élément peuvent être
//séparées par un ou plusieurs espace(s).

//La description de la carte sera toujours en dernier dans le fichier, le reste des
//éléments peut être dans n’importe quel ordre.

//MAX MAP WIDTH ?

//GNL NE PREND PAS LA DERNIERE LIGNE DU FICHIER, OBLIGE DE METTRE UN \n A LA FIN POUR AVOIR LA MAP ENTIERE

//checker si les paths des images existent

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
	get_sizes();
	check_map_surrounded();
	printf("**************** END FLOODFILL **********\n");
	print_map(data()->map->map_split);
	close(data()->fd);
	free_map(data()->map->map);
	free_map(data()->map->map_split);
	return (0);
}