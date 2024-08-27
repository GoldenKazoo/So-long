/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zchagar <zchagar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 09:23:56 by zchagar           #+#    #+#             */
/*   Updated: 2024/08/26 19:04:06 by zchagar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

// Fonction qui recupere la taille du futur tableau
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

// Fonction qui transforme une map en tableau
char	**ft_map_tab(int fd)//, char **map)
{
	char	**map;
	int		height;
	int		width;
	int		i;

	i = 0;
	width = ft_map_width(fd);
	if (width == -1)
		map = NULL;
	height = ft_map_height(fd);
	map = malloc(sizeof(char*) * width);
	if(!map)
		map = NULL;
	while (i <= width)
	{
		map[i] = malloc(sizeof(char) * height);
		if(!map[i])
			map = NULL;
		i++;
	}
	return (map);
}
char	**ft_fill_map_tab(int fd, char **map)
{
	int		height;
	int		width;
	int		i;
	int		j;
	char	*line;

	i = 0;
	j = 0;
	width = ft_map_width(fd);
	if (width == -1)
		return (NULL);
	height = ft_map_height(fd);
	line = get_next_line(fd);
	while (i <= height)
	{
		while (j <= width)
		{
			map[i][j] = line[j];
			j++;
		}
		i++;
	}
	return (map);
}
int	ft_check_wall(char **map, int width, int height)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (j <= width)
	{
		if (map[height][j] != 1 || map[0][j] != 1)
			return (-1);
		j++;
	}
	while (i <= height)
	{
		if (map[i][width] != 1 || map[i][0] != 1)
			return (-1);
		i++;
	}
	return (0);
}
int	ft_count_components(char **map, char c, int fd)
{
	int	i;
	int	j;
	int element;
	int		height;
	int		width;

	i = 0;
	j = 0;
	width = ft_map_width(fd);
	element = 0;
	if (width == -1)
		return (-1);
	height = ft_map_height(fd);
	while (i <= height)
	{
		while (j <= width)
		{
			if (map[i][j] == c)
				element++;
			j++;
		}
		i++;
	}
	return (element);
}

int	ft_map_check(int fd)
{
	char	**map;

	//map = NULL;
	map = ft_map_tab(fd);//, &map);
	if (ft_map_height(fd) == -1 || ft_map_width(fd) == -1) //Map non rectangulaire
		return (1);
	// if (ft_check_wall(map, ft_map_width(fd), ft_map_height(fd)) == -1) //Pas de mur tout autour
	// 	return (2);
	if (ft_count_components(map, 'E', fd) >= 1) //Trop de sortie
		return (3);
	if (ft_count_components(map, 'E', fd) < 1) //Pas de sortie
		return (4);
	if (ft_count_components(map, 'P', fd) >= 1) //Trop de position de depart
		return (5);
	if (ft_count_components(map, 'P', fd) < 1) //Pas de position de depart
		return (6);
	if (ft_count_components(map, 'C', fd) < 1) //Pas assez de collectibles
		return (7);
	return (0);
}
void	ft_errors(int fd)
{
	if(ft_map_check(fd) == 1)
		printf("%s", "Erreur : Map non rectangulaire");
	if(ft_map_check(fd) == 2)
		printf("%s", "Erreur : Pas de mur tout autour");
	if(ft_map_check(fd) == 3)
		printf("%s", "Erreur : Trop de sortie");
	if(ft_map_check(fd) == 4)
		printf("%s", "Erreur : Pas de sortie");
	if(ft_map_check(fd) == 5)
		printf("%s", "Erreur : Trop de position de depart");
	if(ft_map_check(fd) == 6)
		printf("%s", "Erreur : Pas de position de depart");
	if(ft_map_check(fd) == 7)
		printf("%s", "Erreur : Pas assez de collectibles");
}


int main()
{
	int fd;

	fd = open("valide_map.ber", O_RDONLY);
	ft_errors(fd);

}
