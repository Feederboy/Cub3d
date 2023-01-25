/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maquentr <maquentr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 00:57:09 by maquentr          #+#    #+#             */
/*   Updated: 2023/01/25 16:54:16 by maquentr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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

int	check_tiles()
{
	int	i;
	int	j;
    char **map;

    map = data()->map->map_split;
    printf("\n\n\nCHECK TILES PRINT\n");
    print_map(data()->map->map_split);

	data()->map->n = 0;
	data()->map->s = 0;
	data()->map->e = 0;
	data()->map->w = 0;
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
                    data()->map->card = 1;
                else
                    error("WRONG MAP CHECK DOUBLONS NSEW\n");
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