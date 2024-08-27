/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zchagar <zchagar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 09:58:46 by zchagar           #+#    #+#             */
/*   Updated: 2024/08/27 13:56:33 by zchagar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>
# include <limits.h>
#include "get_next_line.h"

typedef struct Map
{
	int	height;
	int	width;
	char	**tab;
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
	line = get_next_line(fd);
	while (line != NULL)
	{
		if (roof != ft_strlen(line))
			return (-1);
		width++;
		line = get_next_line(fd);
	}
	return (roof - 1);
}

char	**ft_map_to_tab (t_map *map)
{
	int	i;

	i = 0;
	map -> tab = malloc (sizeof(char *) * ((map -> height)));
	while (i < (map -> height))
	{
		map -> tab[i] = calloc(sizeof(char), (map -> width + 1));
		i++;
	}
	return (map->tab);
}

char	**ft_fill_map_tab(int fd, t_map *map)//, int h, int w)
{
	int		i;
	int		j;
	char	*line;

	i = 0;
	j = 0;
	while (i < (map -> height))
	{
		line = get_next_line(fd);
		while (j < (map -> width))
		{
			map->tab[i][j] = line[j];
			j++;
		}
		map -> tab[i][j] = '\0';
		j = 0;
		i++;
		free(line);
	}
	return (map->tab);
}

void	ft_print_tab(t_map *map)
{
	char	s;
	printf("--------------\n");
	for(int i = 0; i < map -> height; i++)
	{
		for(int j = 0; j < map -> width; j++)
		{
			s = (map -> tab[i][j]);
			printf("%c", s);
		}
		printf("%c", '\n');
	}
	printf("--------------\n");
	printf(" Longueur : %i\n", map -> height);
	printf(" Largeur : %i\n", map -> width);
	printf("--------------\n");
}

int main ()
{
	int		fd;
	t_map 	*map;

	fd = open("valide_map.ber", O_RDONLY);
	map = malloc(1 * sizeof(t_map)); //malloc la map
	map->height = ft_map_height(fd); //attribue la valeur de la longueur
	close(fd);
	fd = open("valide_map.ber", O_RDONLY);
	map -> width = ft_map_width(fd); //attribue la valeur de la largeur
	close(fd);
	fd = open("valide_map.ber", O_RDONLY);
	ft_map_to_tab(map); //malloc le tableau
	if (!(map -> tab))
		return 0;
	ft_fill_map_tab(fd, map); //remplie le tableau
	ft_print_tab(map); //affiche le tableau
	free(map -> tab);
	free(map);
	close(fd);
}


