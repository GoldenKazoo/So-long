/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zchagar <zchagar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 10:39:36 by zchagar           #+#    #+#             */
/*   Updated: 2024/10/16 02:07:12 by zchagar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"
#include <X11/Xutil.h>
#include "minilibx-linux/mlx.h"
#include <stdlib.h>

int	get_pos_x(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < data -> map_height)
	{
		j = 0;
		while (j < data -> map_width)
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
	while (i < data -> map_height)
	{
		j = 0;
		while (j < data -> map_width)
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
	if (keycode == XK_Escape)
	{
		ft_close_window(data);
		exit(EXIT_SUCCESS);
	}
	if (keycode == XK_W || keycode == XK_w)
		ft_moove_up(keycode, data);
	if (keycode == XK_S || keycode == XK_s)
		ft_moove_down(keycode, data);
	if (keycode == XK_A || keycode == XK_a)
		ft_moove_right(keycode, data);
	if (keycode == XK_D || keycode == XK_d)
		ft_moove_left(keycode, data);
	if ((keycode == XK_W || keycode == XK_w
			|| keycode == XK_S || keycode == XK_s
			|| keycode == XK_A || keycode == XK_a
			|| keycode == XK_D || keycode == XK_d))
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
