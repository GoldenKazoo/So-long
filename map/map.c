/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zchagar <zchagar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 09:58:46 by zchagar           #+#    #+#             */
/*   Updated: 2024/08/27 15:44:12 by zchagar          ###   ########.fr       */
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
		free(line);
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
		free(line);
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

t_map	*ft_return_map ()
{
	int		fd;
	t_map	*map;

	map = malloc(1 * sizeof(t_map)); //malloc la map
	fd = open("valide_map.ber", O_RDONLY);
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
	// ft_print_tab(map); //affiche le tableau
	close(fd);
	return (map);
}

int	ft_check_wall(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	// printf("%i\n", map -> height);
	// printf("%i\n", map -> width);
	while (j < map -> width)
	{
		if (map-> tab[map -> height - 1][j] != '1' || map -> tab[0][j] != '1')
		{
			// c = map -> tab[map -> height - 1][j];
			// d = map -> tab[0][j];
			// printf("Longueur : %i\n", map -> height);
			// printf("Coordonnee kc : %i\n", j);
			// printf("Condition1 : %c\n", map -> tab[map -> height - 1][j]);
			// printf("Condition2 : %c\n", map -> tab[0][j]);
			return (-1);
		}
		j++;
	}
	while (i < map -> height)
	{
		if (map-> tab[i][map->width - 1] != '1' || map-> tab[i][0] != '1')
		{
			printf("Longueur : %i\n", map -> height);
			printf("Coordonnee kc : %i\n", j);
			printf("Condition1 : %c\n", map -> tab[map -> height - 1][j]);
			printf("Condition2 : %c\n", map -> tab[0][j]);
			printf("La\n");
			return (-1);
		}
		i++;
	}
	return (0);
}
int	ft_count_components(t_map *map, char c)
{
	int	i;
	int	j;
	int element;

	i = 0;
	j = 0;
	element = 0;
	if (map -> width == -1)
		return (-1);
	while (i < map -> height)
	{
		while (j < map -> width)
		{
			if (map -> tab[i][j] == c)
				element++;
			j++;
		}
		j = 0;
		i++;
	}
	return (element);
}

int	ft_map_check(t_map *map)
{

	if (map -> height == -1 || map -> width == -1) //Map non rectangulaire
		return (1);
	if (ft_check_wall(map) == -1) //Pas de mur tout autour
		return (2);
	if (ft_count_components(map, 'E') > 1) //Trop de sortie
		return (3);
	if (ft_count_components(map, 'E') < 1) //Pas de sortie
		return (4);
	if (ft_count_components(map, 'P') > 1) //Trop de position de depart
		return (5);
	if (ft_count_components(map, 'P') < 1) //Pas de position de depart
		return (6);
	if (ft_count_components(map, 'C') < 1) //Pas assez de collectibles
		return (7);
	return (0);
}
void	ft_errors(t_map *map)
{
	if(ft_map_check(map) == 1)
		printf("%s", "Erreur : Map non rectangulaire");
	if(ft_map_check(map) == 2)
		printf("%s", "Erreur : Pas de mur tout autour\n");
	if(ft_map_check(map) == 3)
		printf("%s", "Erreur : Trop de sortie");
	if(ft_map_check(map) == 4)
		printf("%s", "Erreur : Pas de sortie");
	if(ft_map_check(map) == 5)
		printf("%s", "Erreur : Trop de position de depart");
	if(ft_map_check(map) == 6)
		printf("%s", "Erreur : Pas de position de depart");
	if(ft_map_check(map) == 7)
		printf("%s", "Erreur : Pas assez de collectibles");
}

int main()
{
	t_map	*map;

	map = ft_return_map();
	ft_errors(map);
}


