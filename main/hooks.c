
#include "parsing.h"
#include <X11/Xutil.h>
#include "minilibx-linux/mlx.h"
#include <stdlib.h>

int	get_posX (t_data *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while(i < data -> map_height)
	{
		j = 0;
		while(j < data -> map_width)
		{
			if(data -> tab[i][j] == 'P')
				return(i);
			j++;
		}
		i++;
	}
	return (0);
}

int	get_posY (t_data *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while(i < data -> map_height)
	{
		j = 0;
		while(j < data -> map_width)
		{
			if(data -> tab[i][j] == 'P')
				return(j);
			j++;
		}
		i++;
	}
	return (0);
}
int	*ft_moove_up_down(int keycode, t_data *data)
{
	data -> player_posX = get_posX(data);
	data -> player_posY = get_posX(data) - 1;
	data -> tab[data -> player_posX][data -> player_posY + 1] = '0';
	data -> tab[data -> player_posX][data -> player_posY] = 'P';
	if (keycode == XK_W ||keycode == XK_w)
	{
		data -> tab[data -> player_posX][data -> player_posY] = 'P';
		data -> tab[data -> player_posX][data -> player_posY] = '0';
		mlx_put_image_to_window(data -> mlx, data -> win,
		 (data -> player_tile),32 * (data -> player_posX + 1), 32 * (data -> player_posY));
		mlx_put_image_to_window(data -> mlx, data -> win,
		 (data -> empty_tile),32 * (data -> player_posX), 32 * (data -> player_posY));
	}
	if (keycode == XK_S ||keycode == XK_s)
	{
		data -> tab[data -> player_posX][data -> player_posY] = 'P';
		data -> tab[data -> player_posX][data -> player_posY] = '0';
		mlx_put_image_to_window(data -> mlx, data -> win,
		 (data -> player_tile),32 * (data -> player_posX + 1), 32 * (data -> player_posY));
		mlx_put_image_to_window(data -> mlx, data -> win,
		 (data -> empty_tile),32 * (data -> player_posX), 32 * (data -> player_posY));
	}
	return(0);
}

t_data	*ft_moove_right_left(int keycode, t_data *data)
{
	if (keycode == XK_A ||keycode == XK_a)
	{
		data -> player_posX = get_posX(data);
		data -> player_posY = get_posX(data) - 1;
		data -> tab[data -> player_posX][data -> player_posY] = '0';
		data -> tab[data -> player_posX][data -> player_posY] = 'P';
		mlx_put_image_to_window(data -> mlx, data -> win,
		 (data -> player_tile),32 * (data -> player_posX + 1), 32 * (data -> player_posY));
		mlx_put_image_to_window(data -> mlx, data -> win,
		 (data -> empty_tile),32 * (data -> player_posX), 32 * (data -> player_posY));

	}
	if (keycode == XK_D ||keycode == XK_d)
	{
		data -> player_posX = data -> player_posX + 1;
		data -> player_posY = data -> player_posY;
		data -> tab[data -> player_posX - 1][data -> player_posY] = '0';
		data -> tab[data -> player_posX][data -> player_posY] = 'P';
		mlx_put_image_to_window(data -> mlx, data -> win,
		 (data -> player_tile),32 * (data -> player_posX), 32 * (data -> player_posY));
		mlx_put_image_to_window(data -> mlx, data -> win,
		 (data -> empty_tile),32 * (data -> player_posX), 32 * (data -> player_posY));

	}
	return data;
}
int	inputs(int keycode, t_data *data)
{
	if(keycode == XK_Escape)
	{
		mlx_destroy_window(data -> mlx, data -> win);
		ft_print_tab(data);
		exit(EXIT_SUCCESS);
	}
	if(keycode == XK_W || keycode == XK_w || keycode == XK_S || keycode == XK_s)
	{
		ft_moove_up_down(keycode, data);
		ft_print_tab(data);
}
	if(keycode == XK_A || keycode == XK_a || keycode == XK_D || keycode == XK_d)
	{
		ft_moove_right_left(keycode, data);
		ft_print_tab(data);
	}
	printf("Player X:%i\n", data -> player_posX);
	printf("Player Y:%i\n", data -> player_posY);
	return (0);
}
int	ft_key_hooks(t_data *data)
{
	mlx_key_hook(data -> win, inputs, data);
	return(0);
}
