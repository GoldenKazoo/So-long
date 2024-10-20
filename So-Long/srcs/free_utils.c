/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zchagar <zchagar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 13:33:47 by zchagar           #+#    #+#             */
/*   Updated: 2024/10/20 13:34:04 by zchagar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void	ft_free_img1(t_data *data)
{
	if (data -> empty_tile)
	{
		free(data -> empty_tile);
	}
	if (data -> wall_tile)
	{
		free(data -> wall_tile);
	}
}

void	ft_free_img2(t_data *data)
{
	if (data -> player_tile)
	{
		free(data -> player_tile);
	}
	if (data -> exit_tile)
	{
		free(data -> exit_tile);
	}
	if (data -> obj_tile)
	{
		free(data -> obj_tile);
	}
}

void	ft_free_img(t_data *data)
{
	ft_free_img1(data);
	ft_free_img2(data);
}
