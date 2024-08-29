/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zchagar <zchagar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 09:25:49 by zchagar           #+#    #+#             */
/*   Updated: 2024/08/29 10:42:27 by zchagar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int	ft_notchar (char c)
{
	if (c != '0' && c != '1' && c != 'C' && c != 'P' && c != 'E')
		return (-1);
	return (0);
}

char	*ft_count_elements(int index, char* elements, char c)
{
	if(index == 0)
	{
	elements[0] = '0';
	elements[1] = '0';
	elements[2] = '0';
	elements[3] = '\0';
	}
	if (c == 'P')
		elements[0]++;
	if (c == 'E')
		elements[1]++;
	if (c == 'C')
		elements[2]++;
	return (elements);
}
char	*ft_check_elements(char *elements, int index, t_map *(map))
{
	if (elements[0] > '1')
		return (6);
	if (elements[0] < '1')
		return (7);
	if (elements[1] > '1')
		return (4);
	if (elements[1] < '1')
		return (5);
	if (elements[2] < '1' && (index == map -> height))
		return (8);
	return (0);
}
int	ft_checkwall(int index, char *line, t_map *map)
{
	int	i;

	i = 0;
	if(index == 0 || index == map -> height)
	{
		while (i < map -> width)
		{
			if (ft_notchar(line[i]) == -1)
				return (8);
			if (line[i] != '1')
				return (2);
			i++;
		}
	}
	i = 0;
	while (i < map -> width)
	{
		if (ft_notchar(line[i]) == -1)
			return (8);
		if ((line[1] != 1 && line[map -> width] != 1))
			return (2);
		i++;
	}
	return (0);
}
void	ft_printerror(int error)
{
	if(error == 1)
		printf("%s", "Erreur : Map non rectangulaire");
	if(error == 2)
		printf("%s", "Erreur : Pas de mur tout autour\n");
	if(error == 3)
		printf("%s", "Erreur : Trop de sortie");
	if(error == 4)
		printf("%s", "Erreur : Pas de sortie");
	if(error == 5)
		printf("%s", "Erreur : Trop de position de depart");
	if(error == 6)
		printf("%s", "Erreur : Pas de position de depart");
	if(error == 7)
		printf("%s", "Erreur : Pas assez de collectibles");
	if(error == 8)
		printf("%s", "Erreur : Char illegal");
}

int	ft_coherence(char *line, int index, t_map *(map), char	*count_elements) //coherence sur la ligne
{
	int error;

	if (ft_check_elements != 0)
	{
		error = ft_check_wall(index , line, map);
		ft_printerror(error);
		return (error);
	}
	error = ft_check_elements(count_elements, index, map);
	ft_printerror(error);
	return (error);
}


