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

void free_map(char **map)
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