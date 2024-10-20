/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zchagar <zchagar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 13:35:07 by zchagar           #+#    #+#             */
/*   Updated: 2024/10/20 14:34:03 by zchagar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void	ft_print_error1(int state, t_data *data)
{
	if (data -> fd < 0)
	{
		free(data -> map_elements);
		ft_free_img(data);
		ft_printf("Error can't open map\n");
		close(data -> fd);
		free(data);
		exit(EXIT_FAILURE);
	}
	if (state == 1)
	{
		free(data -> map_elements);
		ft_free_img(data);
		ft_printf("Error char illegal\n");
		close(data -> fd);
		free(data);
		exit(EXIT_FAILURE);
	}
}

void	ft_print_error2(int state, t_data *data)
{
	if (state == 2)
	{
		free(data -> map_elements);
		ft_free_img(data);
		ft_printf("Error reading map dimensions.\n");
		close(data -> fd);
		free(data);
		exit(EXIT_FAILURE);
	}
	if (state == 3)
	{
		free(data -> map_elements);
		ft_free_img(data);
		ft_printf("Error no wall around.\n");
		close(data -> fd);
		free(data);
		exit(EXIT_FAILURE);
	}
}

void	ft_print_error3(int state, t_data *data)
{
	if (state == 4)
	{
		free(data -> map_elements);
		ft_free_img(data);
		ft_printf("Error no exit.\n");
		close(data -> fd);
		free(data);
		exit(EXIT_FAILURE);
	}
	if (state == 5)
	{
		free(data -> map_elements);
		ft_free_img(data);
		ft_printf("Error too much exits.\n");
		close(data -> fd);
		free(data);
		exit(EXIT_FAILURE);
	}
}

void	ft_print_error4(int state, t_data *data)
{
	if (state == 6)
	{
		free(data -> map_elements);
		ft_free_img(data);
		ft_printf("Error no player.\n");
		close(data -> fd);
		free(data);
		exit(EXIT_FAILURE);
	}
	if (state == 7)
	{
		free(data -> map_elements);
		ft_free_img(data);
		ft_printf("Error too much player.\n");
		close(data -> fd);
		free(data);
		exit(EXIT_FAILURE);
	}
}

void	ft_print_error5(int state, t_data *data)
{
	if (state == 8)
	{
		free(data -> map_elements);
		ft_free_img(data);
		ft_printf("Error not enough collectible.\n");
		close(data -> fd);
		free(data);
		exit(EXIT_FAILURE);
	}
	if (state == 9)
	{
		free(data -> map_elements);
		ft_free_img(data);
		ft_printf("Empty file.\n");
		close(data -> fd);
		free(data);
		exit(EXIT_FAILURE);
	}
}
