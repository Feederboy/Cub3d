/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maquentr <maquentr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 00:57:09 by maquentr          #+#    #+#             */
/*   Updated: 2023/02/09 16:38:41 by maquentr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int check_RGB_range(char **tmp)
{
    int i;
    int t;

    i = 0;
    t = 0;
    while (i < 3)
    {
        t = ft_atoi(tmp[i]);
        printf("check rgb range i = %d\n", t);
        if (t < 0 || t > 255)
            return (1);
        i++;
    }
    return (0);
}

static int check_RGB_vals(char *f, char *c)
{
    char **tmp;

    tmp = gc_split(f, ',');
    if (!tmp)
        error("couldn't split F or C line\n");
    if (check_RGB_range(tmp))
        return (1);
    tmp = gc_split(c, ',');
    if (check_RGB_range(tmp))
        return (1);
    if (c == 'F' && map->floor == -1)
	{
		map->floor = (rgb.r << 16 | rgb.g << 8 | rgb.b);
	}
	else if (c == 'C' && map->celling == -1)
	{
		map->celling = (rgb.r << 16 | rgb.g << 8 | rgb.b);
	}
    return (0);
}


static int check_FC()
{
    char *fvals;
    char *cvals;

    fvals = NULL;
    cvals = NULL;
    if (data()->map->map[5][0] != 'F' || data()->map->map[6][0] != 'C')
        error("F or C missing\n");
    fvals = gc_strdup(data()->map->map[5] + 2);
    cvals = gc_strdup(data()->map->map[6] + 2);
    if (check_RGB_vals(fvals, cvals))
        error("BAD RGB RANGE\n");
    return (0);
}

char    *trim_newline(char *str)
{
    int     i;
    
    i = 0;
    while (str[i + 1])
        i++;
    if (str[i] == '\n' && str[i + 1] == '\0')
        str[i] = '\0';
    return str;
}

static int check_textures_path()
{
    data()->map->no_path = gc_strdup(&data()->map->map[0][3]);
    if (!data()->map->no_path)
        error("couldn't strdup no\n");
    data()->map->no_path = trim_newline(data()->map->no_path);
    data()->map->ea_path = gc_strdup(&data()->map->map[0][3]);
    if (!data()->map->ea_path)
        error("couldn't strdup no\n");
    data()->map->ea_path = trim_newline(data()->map->ea_path);
    data()->map->so_path = gc_strdup(&data()->map->map[0][3]);
    if (!data()->map->so_path)
        error("couldn't strdup no\n");
    data()->map->so_path = trim_newline(data()->map->so_path);
    data()->map->we_path = gc_strdup(&data()->map->map[0][3]);
    if (!data()->map->we_path)
        error("couldn't strdup no\n");
    data()->map->we_path = trim_newline(data()->map->we_path);
 

    printf("NO = %s SE = %s WE = %s EA = %s\n", data()->map->no_path, data()->map->so_path, data()->map->we_path, data()->map->ea_path);
    return (0);
}

int check_textures_order()
{
    printf("\n***********************************CHECK TEXTURES ORDER**********************************\n");
    print_map(data()->map->map);

    // int i;
    // int j;

    // i = 0;
    // j = 0;

    // while (data()->map->map[0][0])
    if (data()->map->map[0][0] != 'N' || data()->map->map[0][1] != 'O')
        error("FIRST LINE MUST BE N FOLLOWED BY O THEN PATH\n");
    if (data()->map->map[1][0] != 'S' || data()->map->map[1][1] != 'O')
        error("SECOND LINE MUST BE S FOLLOWED BY O THEN PATH\n");
    if (data()->map->map[2][0] != 'W' || data()->map->map[2][1] != 'E')
        error("THIRD LINE MUST BE W FOLLOWED BY E THEN PATH\n");
    if (data()->map->map[3][0] != 'E' || data()->map->map[3][1] != 'A')
        error("FOURTH LINE MUST BE E FOLLOWED BY A THEN PATH\n");
    if (check_textures_path())
        error("path to textures are wrong\n");
    if (check_FC())
       printf("\n***********************************CHECK TEXTURES ORDER END**********************************\n\n\n");
    return (0);
}

int	check_tiles()
{
	int	i;
	int	j;
    char **map;

    map = data()->map->map_split;
    printf("\n\n\nCHECK TILES PRINT\n");
    print_map(data()->map->map_split);
	i = 0;
	while (map[i])
	{
		j = 0;
        printf("[");
		while (map[i][j])
		{

            printf("%c", map[i][j]);
			if (ft_strchr("NSEW", map[i][j]))
            {
                if (data()->map->card == 0)
                {
                    data()->map->card = 1;
                    data()->map->player_posx = i;
                    data()->map->player_posy = j;
                }
                else
                {
                    printf("map[%d][%d] == %c\n", i, j, map[i][j]);
                    error("WRONG MAP CHECK DOUBLONS NSEW\n");

                }
            }
            if (!ft_strchr("NSEW01 \n", map[i][j]))
                error("TILE MISSING\n");
			j++;
		}
		i++;
    }
    if (!data()->map->card)
        error("CARD MISSING\n");
    printf("MAP OK\n");
    return (0);
}



























// void	get_char_tile(char m)
// {
// 	if (m == 'N')
// 		data()->map->n += 1;
// 	else if (m == 'S')
// 		data()->map->s += 1;
// 	else if (m == 'E')
// 		data()->map->e += 1;
// 	else if (m == 'W')
// 		data()->map->w += 1;
// }

// int check_multiples()
// {
//     if (data()->map->n == 0 && data()->map->s == 0 && data()->map->e ==0 &&
//         data()->map->w == 0)
//         return (1);
//     if (data()->map->n > 1 || data()->map->s > 1 || data()->map->e > 1 ||
//         data()->map->w > 1)
//         return (1);
//     if (data()->map->n == 1 && (data()->map->s >= 1 || data()->map->e >= 1 ||
//         data()->map->w >= 1))
//         return (1);
//     if (data()->map->s == 1 && (data()->map->n >= 1 || data()->map->e >= 1 ||
//         data()->map->w >= 1))
//         return (1);    
//     if (data()->map->e == 1 && (data()->map->s >= 1 || data()->map->n >= 1 ||
//         data()->map->w >= 1))
//         return (1);
//     if (data()->map->w == 1 && (data()->map->s >= 1 || data()->map->e >= 1 ||
//         data()->map->n >= 1))
//         return (1);
//     return (0);
// }
