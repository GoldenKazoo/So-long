/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zchagar <zchagar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 10:39:36 by zchagar           #+#    #+#             */
/*   Updated: 2024/10/20 14:24:21 by zchagar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void	ft_fill_map_tab(t_data *data, char *longline)
{
	int		i;
	int		j;
	int		k;

	i = 0;
	j = 0;
	k = 0;
	data -> tab = malloc (sizeof(char *) * ((data -> map_height)));
	while (i < (data -> map_height))
	{
		data -> tab[i] = malloc(sizeof(char) * (data -> map_width + 1));
		i++;
	}
	i = 0;
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

void	parsing_loop(t_data *data, char *line, char **long_line, int state)
{
	int	line_len;

	state = ft_check_line(data, line);
	if (state != 0)
	{
		ft_free_to_error(data, state, line, *long_line);
	}
	line_len = ft_strlen(line);
	if (ft_strchr(line, '\n') == NULL)
		line_len++;
	if (line_len != data -> map_width)
	{
		state = 2;
		ft_free_to_error(data, state, line, *long_line);
	}
	if (line != NULL && (data -> map_height) != 0)
	{
		*long_line = ft_strjoin(*long_line, line);
	}
}

void	ft_end_parsing(t_data *data, char *line, char *long_line, int state)
{
	if (data -> map_height * data -> map_width > 10000
		|| data -> map_height > 30)
	{
		free(long_line);
		ft_print_error(11, data);
		exit(1);
	}
	state = ft_check_last_line(data, long_line);
	free(line);
	if (state != 0)
	{
		free(long_line);
		ft_print_error(state, data);
	}
	state = ft_check_elements(data);
	if (state != 0)
	{
		free(long_line);
		ft_print_error(state, data);
	}
	(data -> map_width)--;
	ft_fill_map_tab(data, long_line);
	free(long_line);
}

int	parsing(t_data *data)
{
	int		state;
	char	*line;
	char	*long_line;

	state = 0;
	line = get_next_line(data -> fd, state);
	if (line == NULL)
		return (9);
	long_line = ft_strdup(line);
	state = ft_check_first_line(long_line);
	if (state != 0)
		ft_free_to_error(data, state, line, long_line);
	data -> map_width = ft_strlen(line);
	while (line != NULL)
	{
		if (data -> map_height != 0)
			parsing_loop(data, line, &long_line, state);
		free(line);
		line = get_next_line(data -> fd, state);
		data -> map_height++;
	}
	ft_end_parsing(data, line, long_line, state);
	return (state);
}

t_data	*ft_return_map(t_data *data, int fd)
{
	int	state;

	data -> map_height = 0;
	data -> map_width = 0;
	data -> map_elements = malloc(sizeof(int) * 3);
	data -> map_elements[0] = 0;
	data -> map_elements[1] = 0;
	data -> map_elements[2] = 0;
	state = parsing(data);
	ft_print_error(state, data);
	close(fd);
	return (data);
}
