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

#include "parsing.h"

void	ft_free_all(t_data *data)
{
	int	i;

	i = 0;
	while (i < (data -> map_height))
	{
		free(data -> tab[i]);
		i++;
	}
	free(data -> tab);
	free(data -> map_elements);
	free(data);
}

int	ft_print_error(int state, t_data *data, int fd)
{
	if (fd < 0)
	{
		printf("Error can't open map\n");
		free(data);
		exit(EXIT_FAILURE);
	}
	if (state == 1)
	{
		printf("Error char illegal\n");
		free(data);
		close(fd);
		exit(EXIT_FAILURE);
	}
	if (state == 2)
	{
		printf("Error reading map dimensions.\n");
		free(data);
		close(fd);
		exit(EXIT_FAILURE);
	}
	if (state == 3)
	{
		printf("Error no wall around.\n");
		free(data);
		close(fd);
		exit(EXIT_FAILURE);
	}
	if (state == 4)
	{
		printf("Error no exit.\n");
		free(data);
		close(fd);
		exit(EXIT_FAILURE);
	}
	if (state == 5)
	{
		printf("Error too much exits.\n");
		free(data);
		close(fd);
		exit(EXIT_FAILURE);
	}
	if (state == 6)
	{
		printf("Error no player.\n");
		free(data);
		close(fd);
		exit(EXIT_FAILURE);
	}
	if (state == 7)
	{
		printf("Error too much player.\n");
		free(data);
		close(fd);
		exit(EXIT_FAILURE);
	}
	if (state == 8)
	{
		printf("Error not enough collectible.\n");
		free(data);
		close(fd);
		exit(EXIT_FAILURE);
	}
	return (0);
}
