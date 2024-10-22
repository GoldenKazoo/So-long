/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zchagar <zchagar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 10:39:36 by zchagar           #+#    #+#             */
/*   Updated: 2024/10/22 10:36:29 by zchagar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"
#include <X11/Xutil.h>

void	ft_moove_up(int keycode, t_data *data)
{
	if ((keycode == XK_W || keycode == XK_w)
		&& data -> tab[(data -> p_pos_x) - 1][(data -> p_pos_y)] != '1')
	{
		if (data -> tab[(data -> p_pos_x) - 1][(data -> p_pos_y)] == 'C')
			data -> map_elements[2] = data -> map_elements[2] - 1;
		if (data -> tab[(data -> p_pos_x) - 1][(data -> p_pos_y)]
		== 'E' && (data -> map_elements[2] == 0))
		{
			ft_close_window(data);
		}
		if (data -> tab[(data -> p_pos_x) - 1][(data -> p_pos_y)] != 'E')
		{
			data -> coups = data -> coups + 1;
			ft_printf("Coups : %i\n", data -> coups);
			data -> p_pos_x = data -> p_pos_x;
			data -> p_pos_y = data -> p_pos_y;
			data -> tab[data -> p_pos_x][data -> p_pos_y] = '0';
			data -> tab[(data -> p_pos_x) - 1][(data -> p_pos_y)] = 'P';
			data -> p_pos_x = get_pos_x(data);
			ft_paint_map(data);
		}
	}
}

void	ft_moove_down(int keycode, t_data *data)
{
	if ((keycode == XK_S || keycode == XK_s)
		&& data -> tab[(data -> p_pos_x) + 1][(data -> p_pos_y)] != '1' )
	{
		if (data -> tab[(data -> p_pos_x) + 1][(data -> p_pos_y)] == 'C')
		{
			data -> map_elements[2] = data -> map_elements[2] - 1;
		}
		if (data -> tab[(data -> p_pos_x) + 1][(data -> p_pos_y)] == 'E' &&
			(data -> map_elements[2] == 0))
		{
			ft_close_window(data);
		}
		if (data -> tab[(data -> p_pos_x) + 1][(data -> p_pos_y)] != 'E')
		{
			data -> coups = data -> coups + 1;
			ft_printf("Coups : %i\n", data -> coups);
			data -> p_pos_x = data -> p_pos_x;
			data -> p_pos_y = data -> p_pos_y;
			data -> tab[data -> p_pos_x][data -> p_pos_y] = '0';
			data -> tab[(data -> p_pos_x) + 1][(data -> p_pos_y)] = 'P';
			data -> p_pos_x = get_pos_x(data);
			ft_paint_map(data);
		}
	}
}

void	ft_moove_right(int keycode, t_data *data)
{
	if ((keycode == XK_A || keycode == XK_a)
		&& data -> tab[(data -> p_pos_x)][(data -> p_pos_y) - 1] != '1')
	{
		if (data -> tab[(data -> p_pos_x)][(data -> p_pos_y) - 1] == 'C')
			data -> map_elements[2] = data -> map_elements[2] - 1;
		if (data -> tab[(data -> p_pos_x)][(data -> p_pos_y) - 1] == 'E'
			&& (data -> map_elements[2] == 0))
		{
			ft_close_window(data);
		}
		if (data -> tab[(data -> p_pos_x)][(data -> p_pos_y) - 1] != 'E')
		{
			data -> coups = data -> coups + 1;
			ft_printf("Coups : %i\n", data -> coups);
			data -> p_pos_y = data -> p_pos_y;
			data -> tab[data -> p_pos_x][data -> p_pos_y] = '0';
			data -> tab[(data -> p_pos_x)][(data -> p_pos_y) - 1] = 'P';
			data -> p_pos_y = get_pos_y(data);
			ft_paint_map(data);
		}
	}
}

void	ft_moove_left(int keycode, t_data *data)
{
	if ((keycode == XK_D || keycode == XK_d)
		&& data -> tab[(data -> p_pos_x)][(data -> p_pos_y) + 1] != '1')
	{
		if (data -> tab[(data -> p_pos_x)][(data -> p_pos_y) + 1] == 'E'
			&& (data -> map_elements[2] == 0))
		{
			ft_close_window(data);
		}
		if (data -> tab[(data -> p_pos_x)][(data -> p_pos_y) + 1] == 'C')
		{
			data -> map_elements[2] = data -> map_elements[2] - 1;
		}
		if (data -> tab[(data -> p_pos_x)][(data -> p_pos_y) + 1] != 'E')
		{
			data -> coups = data -> coups + 1;
			ft_printf("Coups : %i\n", data -> coups);
			data -> p_pos_y = data -> p_pos_y;
			data -> tab[data -> p_pos_x][data -> p_pos_y] = '0';
			data -> tab[(data -> p_pos_x)][(data -> p_pos_y) + 1] = 'P';
			data -> p_pos_y = get_pos_y(data);
			ft_paint_map(data);
		}
	}
}
