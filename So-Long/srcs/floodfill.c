/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floodfill.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zchagar <zchagar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 10:39:36 by zchagar           #+#    #+#             */
/*   Updated: 2024/10/16 04:09:46 by zchagar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void	ft_duplicate_tab(t_data *data)
{
	int		i;
	int		y;

	i = 0;
	y = 0;
	data -> copy = calloc (sizeof(char *), (data -> map_height));
	if (!(data -> copy))
		return ;
	while (i < (data -> map_height))
	{
		data -> copy[i] = malloc(sizeof(char) * (data -> map_width + 1));
		if (!(data -> copy[i]))
			return ;
		i++;
	}
	while (y < data -> map_height)
	{
		i = 0;
		while (i < data -> map_width)
		{
			data -> copy[y][i] = data -> tab[y][i];
			i++;
		}
		y++;
	}
}

void	flood_fill(t_data *data, int x, int y, int *items_left)
{
	if (x < 0 || x >= data -> map_width || y < 0 || y >= data -> map_height)
		return ;
	if (data -> copy[y][x] == 'E')
	{
		data -> copy[y][x] = '1';
		data -> found_exit = 1;
	}
	if (data -> copy[y][x] == '1' || data -> copy[y][x] == 'V')
		return ;
	if (data -> copy[y][x] == 'C')
		(*items_left)--;
	data -> copy[y][x] = 'V';
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
		while (x < data -> map_width)
		{
			if (data -> copy[y][x] == 'P')
			{
				data -> p_pos_x = x;
				data -> p_pos_y = y;
			}
			if (data->copy[y][x] == 'C')
				(*items_left)++;
			x++;
		}
		y++;
	}
}

int	check_map_accessibility(t_data *data)
{
	int	items_left;

	items_left = 0;
	ft_duplicate_tab(data);
	check_map_accessibility_loop(data, &items_left);
	flood_fill(data, data -> p_pos_x, data -> p_pos_y, &items_left);
	if ((items_left == 0) && (data -> found_exit == 1))
	{
		ft_free_all_dup(data);
		free(data -> copy);
		return (1);
	}
	else
	{
		ft_free_all_dup(data);
		free(data -> copy);
		return (0);
	}
}
