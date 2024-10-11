/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_fix.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zchagar <zchagar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 12:44:09 by zchagar           #+#    #+#             */
/*   Updated: 2024/08/27 10:19:10 by zchagar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

typedef struct map
{
	char	**map;
	int		height;
	int		width;
} t_map;

int	ft_map_height(int fd)
{
	int		height;
	char	*line;

	line = get_next_line(fd);
	height = 0;
	while (line != NULL)
	{
		line = get_next_line(fd);
		height++;
	}
	return (height);
}

int	ft_map_width(int fd)
{
	int	width;
	char	*line;
	size_t		roof;

	line = get_next_line(fd);
	width = 0;
	roof = ft_strlen(line);
	while (line != NULL)
	{
		line = get_next_line(fd);
		if (roof != ft_strlen(line))
			return (-1);
		width++;
	}
	return (width);
}
char	**ft_map_to_tab_empty(t_map *map)
{
	int		i;

	i = 0;
	if ((map -> width) == -1)
		return (NULL);
	map = malloc(sizeof(char*) * (map -> width));
	if(!map)
		return NULL;
	while (i < (map -> width))
	{
		map -> map[i] = malloc(sizeof(char) * (map -> height));
		if(!(map -> map[i]))
			return NULL;
		i++;
	}
	return (map -> tab);
}


char	**ft_map(char *file)
{
	int		fd;
	t_map	*map;

	map = malloc(sizeof(t_map));
	fd = open(file, O_RDONLY);
	map -> height = ft_map_height(fd);
	map -> width = ft_map_width(fd);
	map -> map = ft_map_to_tab_empty(map);
}
