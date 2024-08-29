/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zchagar <zchagar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 09:58:46 by zchagar           #+#    #+#             */
/*   Updated: 2024/08/29 12:41:59 by zchagar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "parsing.h"
int	ft_notchar (char c)
{
	if (c != '0' && c != '1' && c != 'C' && c != 'P' && c != 'E')
		return (-1);
	return (0);
}

char	*ft_count_elements(int index, char* elements, char c)
{
	if(index == 0)
	{
	elements[0] = '0';
	elements[1] = '0';
	elements[2] = '0';
	elements[3] = '\0';
	}
	if (c == 'P')
		elements[0]++;
	if (c == 'E')
		elements[1]++;
	if (c == 'C')
		elements[2]++;
	return (elements);
}
int	ft_check_elements(char *elements, int index, t_map *(map))
{
	//condition par rapport a ou l'on en est
	if (elements[0] > '1')
		return (6);
	if (elements[0] < '1' && (index == map -> height))
		return (7);
	if (elements[1] > '1')
		return (4);
	if (elements[1] < '1' && (index == map -> height))
		return (5);
	if (elements[2] < '1' && (index == map -> height))
		return (8);
	return (0);
}
int	ft_checkwall(int index, char *line, t_map *map)
{
	int	i;

	i = 0;
	if(index == 0 || index == map -> height)
	{
		while (i < map -> width)
		{
			if (ft_notchar(line[i]) == -1)
				return (8);
			if (line[i] != '1')
				return (2);
			i++;
		}
	}
	i = 0;
	while (i < map -> width)
	{
		if (ft_notchar(line[i]) == -1)
			return (8);
		if ((line[1] != 1 && line[map -> width] != 1))
			return (2);
		i++;
	}
	return (0);
}
void	ft_printerror(int error)
{
	if(error == 1)
		printf("%s", "Erreur : Map non rectangulaire");
	if(error == 2)
		printf("%s", "Erreur : Pas de mur tout autour\n");
	if(error == 3)
		printf("%s", "Erreur : Trop de sortie");
	if(error == 4)
		printf("%s", "Erreur : Pas de sortie");
	if(error == 5)
		printf("%s", "Erreur : Trop de position de depart");
	if(error == 6)
		printf("%s", "Erreur : Pas de position de depart");
	if(error == 7)
		printf("%s", "Erreur : Pas assez de collectibles");
	if(error == 8)
		printf("%s", "Erreur : Char illegal");
}

int	ft_coherence(char *line, int index, t_map *(map), char	*count_elements) //coherence sur la ligne
{
	int error;

	if (ft_check_elements(count_elements, index, map) != 0)
	{
		error = ft_checkwall(index , line, map);
		ft_printerror(error);
		return (error);
	}
	error = ft_check_elements(count_elements, index, map);
	ft_printerror(error);
	return (error);
}

int	ft_map_height(int fd)
{
	int		height;
	char	*line;

	line = get_next_line(fd);
	free(line);
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
	free(line);
	line = get_next_line(fd);
	while (line != NULL)
	{
		if (roof != ft_strlen(line))
		{
			free(line);
			return (-1);
		}
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
		map -> tab[i] = malloc(sizeof(char) * (map -> width + 1));
		i++;
	}
	return (map->tab);
}

int	ft_fill_map_tab(int fd, t_map *map)
{
	int		i;
	int		j;
	char	*line;
	char	*element_count;

	i = 0;
	j = 0;
	element_count = malloc(sizeof(char) * 4);
	while (i < (map -> height))
	{
		line = get_next_line(fd);
		if (ft_coherence(line, i, map, element_count) != 0)
				return (0);
		while (j < (map -> width))
		{
			ft_count_elements(i, element_count, line[j]);
			map->tab[i][j] = line[j];
			j++;
		}
		map -> tab[i][j] = '\0';
		j = 0;
		i++;
		free(line);
	}
	return (0);
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
	int		state;
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
	state = ft_fill_map_tab(fd, map); //remplie le tableau

	// ft_print_tab(map); //affiche le tableau
	close(fd);
	return (map);
}


int main()
{
	int		i;
	t_map	*map;

	i = 0;
	map = ft_return_map();
	ft_print_tab(map);
	while (i < (map -> height))
	{
		free(map -> tab[i]);
		i++;
	}
	get_next_line(10000);
	free(map -> tab);
	free(map);
}


