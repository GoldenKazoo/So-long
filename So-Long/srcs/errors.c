/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zchagar <zchagar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 10:39:36 by zchagar           #+#    #+#             */
/*   Updated: 2024/10/22 10:29:30 by zchagar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int	ft_print_error(int state, t_data *data)
{
	ft_print_error1(state, data);
	ft_print_error2(state, data);
	ft_print_error3(state, data);
	ft_print_error4(state, data);
	ft_print_error5(state, data);
	if (state == 10)
	{
		free(data -> map_elements);
		ft_free_img(data);
		ft_putstr_fd("Error\nCan't init data.\n", 2);
		close(data -> fd);
		free(data);
		exit(1);
	}
	if (state == 11)
	{
		get_next_line(data -> fd, -1);
		free(data -> map_elements);
		ft_free_img(data);
		ft_putstr_fd("Error\nMap is too big.\n", 2);
		close(data -> fd);
		free(data);
		exit(1);
	}
	return (0);
}
