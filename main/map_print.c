#include "minilibx-linux/mlx.h"
#include "parsing.h"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

void	ft_print_map_aux(t_data *data, int x, int y, int i, int j)
{
	if (data -> tab[x][y] == 'P')
	{
		mlx_put_image_to_window(data -> mlx, data -> win, data -> player_tile,i,j);
	}
	if (data -> tab[x][y] == 'E')
		mlx_put_image_to_window(data -> mlx, data -> win, data -> exit_tile,i,j);
	if (data -> tab[x][y] == 'C')
		mlx_put_image_to_window(data -> mlx, data -> win, data -> obj_tile,i,j);
	if (data -> tab[x][y] == '0')
		mlx_put_image_to_window(data -> mlx, data -> win, data -> empty_tile,i,j);
	if (data -> tab[x][y] == '1')
		mlx_put_image_to_window(data -> mlx, data -> win, data -> wall_tile,i,j);
}
void    ft_print_map(t_data *data)
{
	int		i;
	int		j;
	int		x;
	int		y;
	i = 0;
	j = 0;
	x = 0;
	y = 0;

	while(x < data -> map_width)
	{
		j = 0;
		y = 0;
		while(y < data -> map_height)
		{
			ft_print_map_aux(data, y, x, i, j);
			j = j + 64;
			y++;
		}
		i = i + 64;
		x++;
	}
}
