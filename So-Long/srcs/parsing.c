/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zchagar <zchagar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 10:39:36 by zchagar           #+#    #+#             */
/*   Updated: 2024/10/22 10:13:43 by zchagar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void	ft_fill_map_tab_aux(t_data *data)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	data -> tab = malloc (sizeof(char *) * ((data -> map_h)));
	if (!data -> tab)
	{
		ft_print_error(10, data);
		return ;
	}
	while (i < (data -> map_h))
	{
		data -> tab[i] = malloc(sizeof(char) * (data -> map_w + 1));
		if (!data -> tab[i])
		{
			ft_print_error(10, data);
			return ;
		}
		i++;
	}
}

void	ft_fill_map_tab(t_data *data, char *longline)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	j = 0;
	k = 0;
	ft_fill_map_tab_aux(data);
	while (i < (data -> map_h))
	{
		while (j < (data -> map_w) + 1)
		{
			data->tab[i][j] = longline[k];
			k++;
			j++;
		}
		j = 0;
		i++;
	}
}

void	ft_end_parsing(t_data *data, char *line, char *long_line, int state)
{
	if ((data -> map_w * 64) * (data -> map_h * 64) >= 100000000)
	{
		free(line);
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
	(data -> map_w)--;
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
	if (!long_line)
		return (10);
	state = ft_check_first_line(long_line);
	if (state != 0)
		ft_free_to_error(data, state, line, long_line);
	data -> map_w = ft_strlen(line);
	while (line != NULL && (data -> win_size) <= 100000000)
	{
		if (data -> map_h != 0)
			parsing_loop(data, line, &long_line, state);
		free(line);
		line = get_next_line(data -> fd, state);
		data -> map_h++;
	}
	ft_end_parsing(data, line, long_line, state);
	return (state);
}

t_data	*ft_return_map(t_data *data, int fd)
{
	int	state;

	data -> map_h = 0;
	data -> map_w = 0;
	data -> map_elements = malloc(sizeof(int) * 3);
	if (!data -> map_elements)
		return (NULL);
	data -> map_elements[0] = 0;
	data -> map_elements[1] = 0;
	data -> map_elements[2] = 0;
	state = parsing(data);
	ft_print_error(state, data);
	close(fd);
	return (data);
}
