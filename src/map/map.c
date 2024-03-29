/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddiniz-m <ddiniz-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 11:24:07 by ddiniz-m          #+#    #+#             */
/*   Updated: 2024/02/27 12:38:50 by ddiniz-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

int	readmap(char **map, char *file)
{
	int		fd;
	int		i;
	char	*line;

	i = 0;
	fd = open(file, O_RDONLY);
	if (fd < 0)
	{
		printf("Error\nMap not found\n");
		return (1);
	}
	line = gnl(fd);
	while (line)
	{
		map[i] = ft_strdup(line);
		free(line);
		i++;
		line = gnl(fd);
	}
	map[i] = NULL;
	close(fd);
	return (0);
}

int	numberoflines(char *file)
{
	int		fd;
	int		i;
	char	*line;

	i = 0;
	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (0);
	line = gnl(fd);
	while (line)
	{
		i++;
		free(line);
		line = gnl(fd);
	}
	free(line);
	close(fd);
	return (i);
}

int	tilemap(t_map *map, char *map_path)
{
	int		i;
	int		fd;
	char	*buf;

	i = 0;
	map->y = get_y(map_path);
	fd = open(map_path, O_RDONLY);
	if (fd == -1)
		return (printf("Error\nCould not open file\n"));
	map->tilemap = malloc(sizeof(char *) * (map->y + 1));
	while (i < map->y)
	{
		buf = gnl(fd);
		if (!first_str(buf, "1"))
			map->tilemap[i++] = ft_strdup(buf);
		free(buf);
	}
	map->tilemap[i] = 0;
	close(fd);
	return (0);
}

char	**map_init(char *file)
{
	char	**map;

	map = malloc(sizeof(char *) * (numberoflines(file) + 1));
	if (!map)
		return (NULL);
	if (readmap(map, file))
	{
		free(map);
		return (NULL);
	}
	return (map);
}
