#include "parsing.h"

int	ft_notchar (char c)
{
	if (c != '0' && c != '1' && c != 'C' && c != 'P' && c != 'E')
		return (-1);
	return (0);
}

int	ft_check_elements(char *elements)
{

	if (elements[0] > '1')
		return (7);
	if (elements[1] > '1')
		return (5);
	return (0);
}
int	ft_check_elements_end(char *elements)
{
	if (elements[0] < '1')
	{
		printf("%c", elements[0]);
		printf("%c", elements[1]);
		printf("%c", elements[2]);
		return (6);
	}
	if (elements[1] < '1')
		return (4);
	if (elements[2] < '1')
		return (8);
	return 0;
}

void ft_count_elements(char c, char *elements)
{
	if (c == 'P')
		elements[0]++;
	if (c == 'E')
		elements[1]++;
	if (c == 'C')
		elements[2]++;
}
int	ft_check_wall_and_char(size_t roof, char *line, char *elements)
{
	size_t	i;

	i = 0;
	while (i < roof - 1)
	{
		if (ft_notchar(line[i]) == -1)
		{
			free(line);
			return (1);
		}
		ft_count_elements(line[i], elements);
		i++;
	}
	i = 0;
	if (roof != ft_strlen(line))
	{
		free(line);
		return (-1);
	}
	if (line[0] != '1' || line[roof-2] != '1')
	{
		free(line);
		return (3);
	}
	if (line[0] != '1' || line[roof-2] != '1')
	{
		free(line);
		return (3);
	}
	if (ft_check_elements(elements) != 0)
	{
		free(line);
		return (ft_check_elements(elements));
	}
	return (0);
}

int	ft_check_top_bot(t_data *data)
{
	int	i;

	i = 0;
	while (i < data -> map_width - 1)
	{
		if (data -> tab[0][i] != '1' || data -> tab[data -> map_height - 1][i] != '1')
		{
			printf("%i\n",data -> map_height);
			printf("%i\n",data -> map_width);
			printf("%c\n",data -> tab[0][i]);
			printf("%c\n",data -> tab[data -> map_height - 1][i]);
			return (3);
		}
		i++;
	}
	return (0);
}

int	ft_print_error(int state, t_data *data, int fd)
{
	if (fd < 0) //ERROR 9
	{
		printf("Error can't open map\n");
		free(data);
		return (1);
	}
	if (state == 1) //ERROR 1
	{
		printf("Error char illegal\n");
		free(data);
		close(fd);
		return (1);
	}

	if (state == 2) //ERROR 2
	{
		printf("Error reading map dimensions.\n");
		free(data);
		close(fd);
		return (1);
	}

	if (state == 3) //ERROR 3
	{
		printf("Error no wall around.\n");
		free(data);
		close(fd);
		return (1);
	}

	if (state == 4) //ERROR 4
	{
		printf("Error no exit.\n");
		free(data);
		close(fd);
		return (1);
	}

	if (state == 5) //ERROR 5
	{
		printf("Error too much exits.\n");
		free(data);
		close(fd);
		return (1);
	}

	if (state == 6) //ERROR 6
	{
		printf("Error no player.\n");
		free(data);
		close(fd);
		return (1);
	}

	if (state == 7) //ERROR 7
	{
		printf("Error too much player.\n");
		free(data);
		close(fd);
		return (1);
	}

	if (state == 8) //ERROR 8
	{
		printf("Error not enough collectible.\n");
		free(data);
		close(fd);
		return (1);
	}

	printf("Height: %i\n", data -> map_height);
	printf("Width: %i\n", data -> map_width);

	ft_free_all(data);
	close(fd);
	return (0);
}
