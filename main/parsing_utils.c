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

int	ft_check_line(t_data *data, char *l)
{
	size_t	i;

	i = 0;
	while (i < ft_strlen(l) - 1)
	{
		if (l[i] == 'P')
			data -> map_elements[0] = data -> map_elements[0] + 1;
		if (l[i] == 'E')
			data -> map_elements[1] = data -> map_elements[1] + 1;
		if (l[i] == 'C')
			data -> map_elements[2] = data -> map_elements[2] + 1;
		if (l[i] != '1' && l[i] != '0'
			&& l[i] != 'P' && l[i] != 'E' && l[i] != 'C')
			return (1);
		if (data -> map_elements[0] > '1')
			return (7);
		if (data -> map_elements[1] > '1')
			return (5);
		i++;
	}
	if (l[0] != '1' || l[ft_strlen(l) - 2] != '1')
		return (3);
	return (0);
}

int	ft_check_first_last_line(char *line)
{
	size_t	i;

	i = 0;
	while (i < ft_strlen(line) - 1)
	{
		if (line[i] != '1')
			return (3);
		i++;
	}
	return (0);
}

int	ft_check_elements(t_data *data)
{
	if (data -> map_elements[0] < '1')
		return (6);
	if (data -> map_elements[1] < '1')
		return (4);
	if (data -> map_elements[2] < '1')
		return (8);
	return (0);
}
