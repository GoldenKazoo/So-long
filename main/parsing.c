/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zchagar <zchagar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 10:39:36 by zchagar           #+#    #+#             */
/*   Updated: 2024/08/27 16:14:14 by zchagar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void	ft_map_to_tab(t_data *data)
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

int	parsing_aux (t_data *data, char *line1, char *long_line, int state, int fd)
{
	char	*line2;


	return (state);
}

int	parsing(t_data *data, int fd)
{
	int		state;
	char	*line1;
	char	*line2;
	char	*long_line;

	state = 0;
	line1 = get_next_line(fd);
	long_line = line1;
	if (!line1)
		exit(EXIT_FAILURE);
	data -> map_width = ft_strlen(line1);
	data -> map_height = 0;
	state = ft_check_first_last_line(line1);
	while (line1 != NULL)
	{
		state = ft_check_line(data, line1);
		if (state != 0)
			ft_print_error(state, data, fd);
		line2 = ft_strdup(line1);
		if (ft_strlen(line1) != data -> map_width)
			return (2);
		if (line2 != NULL && (data -> map_height) != 0)
		{
			long_line = ft_strjoin(long_line, line1);
		}
		line1 = get_next_line(fd);
		(data -> map_height)++;
	}
	state = ft_check_first_last_line(line2);
	if (state != 0)
		return (state);
	state = ft_check_elements(data);
	(data -> map_width)--;
	ft_map_to_tab(data);
	ft_fill_map_tab(data, long_line);
	free(long_line);
	return (state);
}

t_data	*ft_return_map(t_data *data, int fd)
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

/*
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
}*/
