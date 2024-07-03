/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maquentr <maquentr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 15:29:27 by mguerra           #+#    #+#             */
/*   Updated: 2023/02/21 19:57:29 by maquentr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	parse_rgb(char *line)
{
	char	**tmp;
	char	*t;
	int		i;
	int		rgb[3];

	tmp = gc_split(line, ',');
	i = 0;
	while (tmp[i])
	{
		t = gc_strtrim(tmp[i], " \n\t\v\f\r");
		if (!is_numeric(t)
			|| ft_atoi(t) < 0
			|| ft_atoi(t) > 255)
			error("Invalid RGB value");
		rgb[i] = ft_atoi(tmp[i]);
		i++;
	}
	return (rgb[0] << 16 | rgb[1] << 8 | rgb[2]);
}

static void	check_settings(char *line)
{
	t_map		*map;

	map = data()->map;
	if (map->paths[N] == NULL
		|| map->paths[S] == NULL
		|| map->paths[W] == NULL
		|| map->paths[E] == NULL
		|| data()->map->floor == -1
		|| data()->map->ceiling == -1)
		error("Missing settings before map declaration");
	if (data()->map->map_str == NULL)
		map->map_str = gc_strdup("");
	map->map_str = gc_strjoin(map->map_str, line);
}

static void	fill_map(char *line)
{
	char		*tmp;
	const char	*sep;
	t_map		*map;

	map = data()->map;
	sep = " \n\t\v\f\r";
	tmp = gc_strtrim(line, sep);
	if (tmp[0] == 'F')
		map->floor = parse_rgb(gc_strtrim(&tmp[1], sep));
	else if (tmp[0] == 'C')
		map->ceiling = parse_rgb(gc_strtrim(&tmp[1], sep));
	else if (ft_strncmp(tmp, "NO", 2) == 0)
		map->paths[N] = gc_strtrim(&tmp[2], sep);
	else if (ft_strncmp(tmp, "SO", 2) == 0)
		map->paths[S] = gc_strtrim(&tmp[2], sep);
	else if (ft_strncmp(tmp, "WE", 2) == 0)
		map->paths[W] = gc_strtrim(&tmp[2], sep);
	else if (ft_strncmp(tmp, "EA", 2) == 0)
		map->paths[E] = gc_strtrim(&tmp[2], sep);
	else if (*tmp == '1' || *tmp == '0')
		check_settings(gc_strdup(line));
	else
		error("Invalid map line");
}

void	parse_map(char *path)
{
	int		fd;
	char	*line;
	int		i;
	t_map	*map;

	i = 0;
	map = data()->map;
	fd = open(path, O_RDONLY);
	if (fd < 0)
		error(ERR_BAD_FILE);
	while (1)
	{
		line = gc_get_next_line(fd);
		if (!line)
			break ;
		if (line && ft_strlen(gc_strtrim(line, " \n\t\v\f\r")))
			fill_map(line);
	}
	map->map = gc_split(map->map_str, '\n');
}
