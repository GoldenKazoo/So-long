/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zchagar <zchagar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 10:39:36 by zchagar           #+#    #+#             */
/*   Updated: 2024/10/20 16:43:36 by zchagar          ###   ########.fr       */
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
		ft_printf("Can't init data.\n");
		close(data -> fd);
		free(data);
		exit(EXIT_FAILURE);
	}
	if (state == 11)
	{
		get_next_line(data -> fd, -1);
		free(data -> map_elements);
		ft_free_img(data);
		ft_printf("Map is too big.\n");
		close(data -> fd);
		free(data);
		exit(EXIT_FAILURE);
	}
	return (0);
}
