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

#include <stdbool.h>
#include "parsing.h"

char	**ft_duplicate tab(t_data *data)
{
	int		x;
	int		y;
	char	**duplicate;

	x = 0;
	y = 0;
	duplicate = malloc (sizeof(char *) * ((data -> map_height)));
	while (i < (data -> map_height))
	{
		data -> tab[i] = malloc(sizeof(char) * (data -> map_width + 1));
		i++;
	}
	while (y < data -> map_height)
	{
		i = 0;
		while (i < data ->map_width)
		{
			duplicate[y][x] = data -> tab[y][x];
		}
		y++;
	}
	return (duplicate)
}

void	flood_fill(t_data *data, int x, int y, int *items_left)
{
	if (x < 0 || x >= data -> map_width || y < 0 || y >= data -> map_height)
		return ;
	if (data -> tab[y][x] == '1' || data -> tab[y][x] == 'V')
		return ;
	if (data ->tab[y][x] == 'C')
		(*items_left)--;
	if (data -> tab[y][x] == 'E')
		data -> found_exit = 1;
	data -> tab[y][x] = 'V';
	flood_fill(data, x + 1, y, items_left);
	flood_fill(data, x - 1, y, items_left);
	flood_fill(data, x, y + 1, items_left);
	flood_fill(data, x, y - 1, items_left);
}

void	check_map_accessibility_loop(t_data *data, int	*items_left)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (y < data -> map_height)
	{
		x = 0;
		while (x < data ->map_width)
		{
			if (data->tab[y][x] == 'P')
			{
				data -> p_pos_x = x;
				data -> p_pos_y = y;
			}
			if (data->tab[y][x] == 'C')
				items_left++;
			x++;
		}
		y++;
	}
}

int	check_map_accessibility(t_data *data)
{
	int	items_left;

	items_left = 0;
	check_map_accessibility_loop(data, &items_left);
	flood_fill(data, data -> p_pos_x, data -> p_pos_y, &items_left);
	if ((items_left == 0) && (data -> found_exit == 1))
		return (1);
	else
		return (0);
}
