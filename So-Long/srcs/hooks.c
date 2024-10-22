/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zchagar <zchagar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 10:39:36 by zchagar           #+#    #+#             */
/*   Updated: 2024/10/22 11:58:22 by zchagar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"
#include <X11/Xutil.h>
#include <stdlib.h>

int	get_pos_x(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < data -> map_h)
	{
		j = 0;
		while (j < data -> map_w)
		{
			if (data -> tab[i][j] == 'P')
				return (i);
			j++;
		}
		i++;
	}
	return (0);
}

int	get_pos_y(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < data -> map_h)
	{
		j = 0;
		while (j < data -> map_w)
		{
			if (data -> tab[i][j] == 'P')
				return (j);
			j++;
		}
		i++;
	}
	return (0);
}

int	inputs(int keycode, t_data *data)
{
	if (keycode == 65307)
	{
		ft_close_window(data);
	}
	if (keycode == 119 || keycode == 119)
		ft_moove_up(keycode, data);
	if (keycode == 115 || keycode == 115)
		ft_moove_down(keycode, data);
	if (keycode == 97 || keycode == 97)
		ft_moove_right(keycode, data);
	if (keycode == 100 || keycode == 100)
		ft_moove_left(keycode, data);
	if ((keycode == 119 || keycode == 119
			|| keycode == 115 || keycode == 115
			|| keycode == 97 || keycode == 97
			|| keycode == 100 || keycode == 100))
	{
	}
	return (0);
}

int	ft_key_hooks(t_data *data)
{
	int	temp;

	data -> coups = 0;
	temp = data -> p_pos_x;
	data -> p_pos_x = data -> p_pos_y;
	data -> p_pos_y = temp;
	mlx_key_hook(data -> win, inputs, data);
	return (0);
}
