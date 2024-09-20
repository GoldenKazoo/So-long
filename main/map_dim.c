#include "parsing.h"

void	ft_free_all(t_data *data)
{
	int	i;

	i = 0;
	while (i < (data -> map_height))
	{
		free(data -> tab[i]);
		i++;
	}
	free(data -> tab);
	free(data);
}
void	ft_free_gnl(fd)
{
	char	*line;
	int	i;

	i = 0;
	line = get_next_line(fd);
	while (line != NULL)
	{
		free(line);
		line = get_next_line(fd);
		i++;
	}
	free(line);
}
int	ft_map_dim(int fd, t_data *data)
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
	{
		free (elements);
		return (-1);
	}
	roof = ft_strlen(line);
	state = ft_check_wall_and_char(roof, line, elements);
	if (state != 0)
	{
		free(elements);
		return (state);
	}
	height = 1;
	free(line);

	while ((line = get_next_line(fd)) != NULL)
	{
		state = ft_check_wall_and_char(roof, line, elements);
		if (state != 0)
		{
			free(elements);
			return (state);
		}
		height++;
		free(line);
	}
	state = ft_check_elements_end(elements);
	if (state != 0)
	{
		free(elements);
		return (state);
	}
	data -> map_height = height;
	data -> map_width = roof - 1;
	free(elements);
	return (0);
}
void	ft_map_to_tab (t_data *data)
{
	int	i;

	i = 0;
	data -> tab = malloc (sizeof(char *) * ((data -> map_height)));
	while (i < (data -> map_height))
	{
		data -> tab[i] = malloc(sizeof(char) * (data -> map_width + 1));
		i++;
	}
}

void	ft_fill_map_tab(int fd, t_data *data)
{
	int		i;
	int		j;
	char	*line;

	i = 0;
	j = 0;
	while (i < (data -> map_height))
	{
		line = get_next_line(fd);
		while (j < (data -> map_width))
		{
			data->tab[i][j] = line[j];
			j++;
		}
		data -> tab[i][j] = '\0';
		j = 0;
		i++;
		free(line);
	}
	get_next_line(fd);
}

void	ft_print_tab(t_data *data)
{
	char	s;
	printf("--------------\n");
	for(int i = 0; i < data -> map_height; i++)
	{
		for(int j = 0; j < data -> map_width; j++)
		{
			s = (data -> tab[i][j]);
			printf("%c", s);
		}
		printf("%c", '\n');
	}
	printf("--------------\n");
	printf(" Longueur : %i\n", data -> map_height);
	printf(" Largeur : %i\n", data -> map_width);
	printf("--------------\n");
}
t_data	*ft_return_map (t_data *data)
{
	int		fd;
	int		state;

	data = malloc(sizeof(t_data));
	if (!data)
		return (NULL);
	fd = open("map/valide_map.ber", O_RDONLY);
	state = ft_map_dim(fd, data);
	if(state != 0)
	{
		ft_free_gnl(fd);
		ft_print_error(state, data, fd);
		return (NULL);
	}
	fd = open("map/valide_map.ber", O_RDONLY);
	ft_map_to_tab(data); //malloc le tableau
	if (!(data -> tab))
	{
		ft_free_gnl(fd);
		ft_free_all(data);
		return (NULL);
	}
	ft_fill_map_tab(fd, data);

	state = ft_check_top_bot(data);
	if(state != 0)
	{
		ft_free_gnl(fd);
		ft_print_error(state, data, fd);
		ft_free_all(data);
		return (NULL);
	}
	ft_free_gnl(fd);
	// ft_print_tab(data); //affiche le tableau
	close(fd);
	return (data);
}
