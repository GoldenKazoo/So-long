/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zchagar <zchagar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 09:58:46 by zchagar           #+#    #+#             */
/*   Updated: 2024/08/29 16:53:56 by zchagar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "parsing.h"

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
	char	*element_count = NULL;

	i = 0;
	j = 0;
	element_count = malloc(sizeof(char) * 4);
	while (i < (map -> height))
	{
		line = get_next_line(fd);
		if (ft_coherence(line, i, map, element_count) != 0)
				return (ft_coherence(line, i, map, element_count));
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

t_map	*ft_return_map (int error)
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
	if (state != 0)
	{
		error = state;
		ft_printerror(state);
		return (NULL);
	}
	close(fd);
	return (map);
}


int main()
{
	int		i;
	int		error;
	t_map	*map;

	i = 0;
	error = 0;
	map = ft_return_map(error);
	if (!map)
		return (1);
	ft_print_tab(map);
	while (i < (map -> height))
	{
		free(map -> tab[i]);
		i++;
	}
	free(map -> tab);
	free(map);
}


