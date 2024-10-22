/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paint_map_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zchagar <zchagar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 10:39:36 by zchagar           #+#    #+#             */
/*   Updated: 2024/10/22 13:00:34 by zchagar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int	ft_get_pixelcolor(t_img *img, int x, int y)
{
	char	*pix;

	pix = img->addr + (y * img->line_len + x * (img->bpp / 8));
	return (*(int *)pix);
}

void	ft_put_pixelimage(t_img *img, int x, int y, int color)
{
	char	*pix;

	pix = img->addr + (y * img->line_len + x * (img->bpp / 8));
	*(int *)pix = color;
}

void	ft_draw_tile(t_img *img, t_img *tile, int x, int y)
{
	int	i;
	int	j;
	int	color;

	i = 0;
	j = 0;
	while (i < 64)
	{
		j = 0;
		while (j < 64)
		{
			color = ft_get_pixelcolor(tile, i, j);
			ft_put_pixelimage(img, i + (x * 64), j + (y * 64), color);
			j++;
		}
		i++;
	}
}
