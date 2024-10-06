 /************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zchagar <zchagar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 13:38:58 by zchagar           #+#    #+#             */
/*   Updated: 2024/10/01 13:38:59 by zchagar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


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
	free(data -> map_elements);
	free(data);
}

int	ft_check_line(t_data *data, char *l)
{
	size_t	i;

	i = 0;
	while (i < ft_strlen(l) - 1)
	{
		if (l[i] == 'P')
			data -> map_elements[0] = data -> map_elements[0] + 1;
		if (l[i] == 'E')
			data -> map_elements[1] = data -> map_elements[1] + 1;
		if (l[i] == 'C')
			data -> map_elements[2] = data -> map_elements[2] + 1;

		// printf("P :%c\n", data -> map_elements[0]);
		if (l[i] != '1' && l[i] != '0' && l[i] != 'P' && l[i] != 'E' && l[i] != 'C')
			return (1); // Illegal char
		if (data -> map_elements[0] > '1')
			return (7); // Too much players
		if (data -> map_elements[1] > '1')
			return (5); // Too much exits
		i++;
	}
	if (l[0] != '1' || l[ft_strlen(l) - 2] != '1')
		return (3);
	return (0);
}
int	ft_check_first_last_line(char *line)
{
	size_t	i;

	i = 0;
	while (i < ft_strlen(line) - 1)
	{
		if(line[i] != '1')
			return (3); // No wall around
		i++;
	}
	return (0);
}

int	ft_check_elements(t_data *data)
{
	if (data -> map_elements[0] < '1')
		return (6);
	if (data -> map_elements[1] < '1')
		return (4);
	if (data -> map_elements[2] < '1')
		return (8);
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

void	ft_fill_map_tab(t_data *data, char *longline)
{
	int		i;
	int		j;
	int		k;

	i = 0;
	j = 0;
	k = 0;
	while (i < (data -> map_height))
	{
		while (j < (data -> map_width) + 1)
		{
			data->tab[i][j] = longline[k];
			k++;
			j++;
		}
		j = 0;
		i++;
	}
}
int	parsing(t_data *data, int fd)
{
	int		state;
	size_t	roof;
	int		height;
	char	*line1;
	char	*line2;
	char	*long_line;

	state = 0;
	height = 0;
	line1 = get_next_line(fd);
	long_line = line1;
	if (!line1)
		exit(EXIT_FAILURE);
	roof = ft_strlen(line1);
	state = ft_check_first_last_line(line1);
	while (line1 != NULL)
	{
		state = ft_check_line(data, line1);
		if (state != 0)
			ft_print_error(state, data, fd);
		line2 = line1;
		if (ft_strlen(line1) != roof)
			return (2);
		if (line2 != NULL && height != 0)
			long_line = ft_strjoin(long_line, line1);
		line1 = get_next_line(fd);
		height++;
	}
	state = ft_check_first_last_line(line2);
	if (state != 0)
		return (state);
	state = ft_check_elements(data);
	data -> map_height = height;
	data -> map_width = roof - 1;
	ft_map_to_tab(data);
	ft_fill_map_tab(data, long_line);
	return (state);
}
int	ft_print_error(int state, t_data *data, int fd)
{
	if (fd < 0) //ERROR 9
	{
		printf("Error can't open map\n");
		free(data);
		exit(EXIT_FAILURE);
	}
	if (state == 1) //ERROR 1
	{
		printf("Error char illegal\n");
		free(data);
		close(fd);
		exit(EXIT_FAILURE);
	}

	if (state == 2) //ERROR 2
	{
		printf("Error reading map dimensions.\n");
		free(data);
		close(fd);
		exit(EXIT_FAILURE);
	}

	if (state == 3) //ERROR 3
	{
		printf("Error no wall around.\n");
		free(data);
		close(fd);
		exit(EXIT_FAILURE);
	}

	if (state == 4) //ERROR 4
	{
		printf("Error no exit.\n");
		free(data);
		close(fd);
		exit(EXIT_FAILURE);
	}

	if (state == 5) //ERROR 5
	{
		printf("Error too much exits.\n");
		free(data);
		close(fd);
		exit(EXIT_FAILURE);
	}

	if (state == 6) //ERROR 6
	{
		printf("Error no player.\n");
		free(data);
		close(fd);
		exit(EXIT_FAILURE);
	}

	if (state == 7) //ERROR 7
	{
		printf("Error too much player.\n");
		free(data);
		close(fd);
		exit(EXIT_FAILURE);
	}

	if (state == 8) //ERROR 8
	{
		printf("Error not enough collectible.\n");
		free(data);
		close(fd);
		exit(EXIT_FAILURE);
	}

	// printf("Height: %i\n", data -> map_height);
	// printf("Width: %i\n", data -> map_width);
	return (0);
}

void	ft_print_tab(t_data *data)
{
	char	s;
	if (data -> tab == NULL)
	{
		printf("%s", "ALED");
	}
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

t_data *ft_return_map(t_data *data, int fd)
{
	int	state;

	data -> map_elements = malloc(sizeof(char) * 4);
	data -> map_elements[0] = '0';
	data -> map_elements[1] = '0';
	data -> map_elements[2] = '0';
	data -> map_elements[3] = '\0';
	state = parsing(data, fd);
	ft_print_error(state, data, fd);
	close(fd);
	return (data);
}


// int main()
// {
// 	t_data *data;

// 	data = malloc(sizeof(t_data));
// 	if (!data)
// 		return (0);

// 	data = ft_return_map(data);
// 	ft_print_tab(data);
// }
