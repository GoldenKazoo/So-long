/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zchagar <zchagar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 13:35:07 by zchagar           #+#    #+#             */
/*   Updated: 2024/10/22 11:32:23 by zchagar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void	ft_print_error1(int state, t_data *data)
{
	if (state == 12)
	{
		get_next_line(data -> fd, -1);
		ft_putstr_fd("Error\nCan't find path.\n", 2);
	}
	if (data -> fd < 0)
	{
		free(data -> map_elements);
		ft_free_img(data);
		get_next_line(data -> fd, -1);
		ft_putstr_fd("Error\nCan't open map\n", 2);
		close(data -> fd);
		free(data);
		exit(1);
	}
	if (state == 1)
	{
		free(data -> map_elements);
		ft_free_img(data);
		get_next_line(data -> fd, -1);
		ft_putstr_fd("Error\nChar illegal\n", 2);
		close(data -> fd);
		free(data);
		exit(1);
	}
}

void	ft_print_error2(int state, t_data *data)
{
	if (state == 2)
	{
		free(data -> map_elements);
		ft_free_img(data);
		get_next_line(data -> fd, -1);
		ft_putstr_fd("Error\nInvalid map dimensions.\n", 2);
		close(data -> fd);
		free(data);
		exit(1);
	}
	if (state == 3)
	{
		free(data -> map_elements);
		ft_free_img(data);
		get_next_line(data -> fd, -1);
		ft_putstr_fd("Error\nNo wall around.\n", 2);
		close(data -> fd);
		free(data);
		exit(1);
	}
}

void	ft_print_error3(int state, t_data *data)
{
	if (state == 4)
	{
		free(data -> map_elements);
		ft_free_img(data);
		ft_putstr_fd("Error\nNo exit.\n", 2);
		close(data -> fd);
		free(data);
		exit(1);
	}
	if (state == 5)
	{
		free(data -> map_elements);
		ft_free_img(data);
		ft_putstr_fd("Error\nToo much exits.\n", 2);
		close(data -> fd);
		free(data);
		exit(1);
	}
}

void	ft_print_error4(int state, t_data *data)
{
	if (state == 6)
	{
		free(data -> map_elements);
		ft_free_img(data);
		ft_putstr_fd("Error\nNo player.\n", 2);
		close(data -> fd);
		free(data);
		exit(1);
	}
	if (state == 7)
	{
		free(data -> map_elements);
		ft_free_img(data);
		ft_putstr_fd("Error\nToo much player.\n", 2);
		close(data -> fd);
		free(data);
		exit(1);
	}
}

void	ft_print_error5(int state, t_data *data)
{
	if (state == 8)
	{
		free(data -> map_elements);
		ft_free_img(data);
		ft_putstr_fd("Error\nNot enough collectible.\n", 2);
		close(data -> fd);
		free(data);
		exit(1);
	}
	if (state == 9)
	{
		free(data -> map_elements);
		ft_free_img(data);
		ft_putstr_fd("Error\nEmpty file.\n", 2);
		close(data -> fd);
		free(data);
		exit(1);
	}
}
