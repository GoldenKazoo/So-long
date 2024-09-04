#include "parsing.h"
void	ft_free(t_map *map)
{
	int	i;

	i = 0;
	while (i < (map -> height))
	{
		free(map -> tab[i]);
		i++;
	}
	free(map -> tab);
	free(map);
}
int	ft_map_dim(int fd, t_map *map)
{
	int		state;
	int		height;
	char	*line;
	char	*elements;
	size_t	roof;

	elements = malloc(sizeof(char) * 4);
	elements[0] = '0';
	elements[1] = '0';
	elements[2] = '0';
	elements[3] = '\0';
	line = get_next_line(fd);
	if (!line)
		return (-1);
	roof = ft_strlen(line);
	state = ft_check_wall_and_char(roof, line, elements);
	if (state != 0)
		return (state);
	height = 1;
	free(line);

	while ((line = get_next_line(fd)) != NULL)
	{
		state = ft_check_wall_and_char(roof, line, elements);
		if (state != 0)
			return (state);
		height++;
		free(line);
	}
	state = ft_check_elements_end(elements);
	if (state != 0)
		return (state);
	map -> height = height;
	map -> width = roof - 1;
	free(elements);
	return (0);
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
int main()
{
	t_map	*map;
	int		fd;
	int		state;

	map = malloc(sizeof(t_map));
	if (!map)
		return (1);
	fd = open("valide_map.ber", O_RDONLY);
	state = ft_map_dim(fd, map);
	if(state != 0)
	{
		ft_print_error(state, map, fd);
		return (1);
	}
	fd = open("valide_map.ber", O_RDONLY);
	ft_map_to_tab(map); //malloc le tableau
	if (!(map -> tab))
	{
		ft_free(map);
		return 0;
	}
	ft_fill_map_tab(fd, map); //remplie le tableau
	state = ft_check_top_bot(map);
	if(state != 0)
	{
		ft_print_error(state, map, fd);
		return (1);
	}
	ft_print_tab(map); //affiche le tableau
	close(fd);
	return (0);
}
