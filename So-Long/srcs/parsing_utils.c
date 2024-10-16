/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zchagar <zchagar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 10:39:36 by zchagar           #+#    #+#             */
/*   Updated: 2024/10/16 04:40:41 by zchagar          ###   ########.fr       */
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
		if (data -> map_elements[0] > 1)
			return (7);
		if (data -> map_elements[1] > 1)
			return (5);
		i++;
	}
	if (l[0] != '1' || l[ft_strlen(l) - 2] != '1')
		return (3);
	return (0);
}

int	ft_check_first_line(char *line)
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

int	ft_check_last_line(t_data *data, char *long_line)
{
	size_t	i;
	char	c;

	i = ft_strlen(long_line) - 1;
	while ((ft_strlen(long_line) - data -> map_width) < i)
	{
		c = long_line[i];
		if (long_line[i] != '1' && long_line[i] != '\n')
			return (3);
		i--;
	}
	return (0);
}

int	ft_check_elements(t_data *data)
{
	if (data -> map_elements[0] < 1)
		return (6);
	if (data -> map_elements[1] < 1)
		return (4);
	if (data -> map_elements[2] < 1)
		return (8);
	return (0);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (0);
	while (s1[i] == s2[i] && (i < n - 1) && s1[i])
		i++;
	return ((unsigned char) s1[i] - (unsigned char) s2[i]);
}
