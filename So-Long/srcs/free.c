/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zchagar <zchagar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 19:51:29 by zchagar           #+#    #+#             */
/*   Updated: 2024/10/22 09:02:06 by zchagar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int	ft_close_window(t_data *data)
{
	int	quit;

	quit = data -> quit;
	ft_free_all(data);
	free(data -> tab);
	free(data -> map_elements);
	mlx_destroy_image(data -> mlx, data -> empty_tile -> mlx_img);
	free(data -> empty_tile);
	mlx_destroy_image(data -> mlx, data -> wall_tile -> mlx_img);
	free(data -> wall_tile);
	mlx_destroy_image(data -> mlx, data -> player_tile -> mlx_img);
	free(data -> player_tile);
	mlx_destroy_image(data -> mlx, data -> exit_tile -> mlx_img);
	free(data -> exit_tile);
	mlx_destroy_image(data -> mlx, data -> obj_tile -> mlx_img);
	free(data -> obj_tile);
	mlx_destroy_window(data -> mlx, data -> win);
	mlx_destroy_display(data -> mlx);
	free(data -> mlx);
	free(data);
	exit(quit);
}

void	ft_free_all(t_data *data)
{
	int	i;

	i = 0;
	while (i < (data -> map_height))
	{
		free(data -> tab[i]);
		i++;
	}
}

void	ft_free_all_dup(t_data *data)
{
	int	i;

	i = 0;
	while (i < (data -> map_height))
	{
		free(data -> copy[i]);
		i++;
	}
}

void	ft_free_to_error(t_data *data, int state, char *line, char *long_line)
{
	free(line);
	free(long_line);
	get_next_line(data -> fd, -1);
	ft_print_error(state, data);
}
