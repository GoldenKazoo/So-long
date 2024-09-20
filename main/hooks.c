
#include "parsing.h"
#include <X11/Xutil.h>
#include "minilibx-linux/mlx.h"
#include <stdlib.h>

t_data	*inputs(int keycode, t_data *data)
{
	if(keycode == XK_Escape)
	{

		mlx_destroy_window(data -> mlx, data -> win);
		exit(EXIT_SUCCESS);
	}
	if(keycode = XK_W || XK_w || XK_S || XK_s)
	{
		ft_moove_up_down(keycode, data);
		return (data);
	}
	if(keycode = XK_A || XK_a || XK_D || XK_d)
	{
		ft_moove_right_left(keycode, data);
		return (data);
	}
	return (data);
}
t_data	*ft_moove_up_down(int keycode, t_data *data)
{
	if (keycode == XK_W ||keycode == XK_w)
	{
		data -> tab[data -> player_posX + 1][data -> player_posY] = 'P';
		data -> tab[data -> player_posX][data -> player_posY] = '0';
		mlx_put_image_to_window(data -> mlx, data -> win,
		 (data -> player_tile),32 * (data -> player_posX + 1), 32 * (data -> player_posY));
		mlx_put_image_to_window(data -> mlx, data -> win,
		 (data -> empty_tile),32 * (data -> player_posX), 32 * (data -> player_posY));
		return (data);
	}
	if (keycode == XK_S ||keycode == XK_s)
	{
		data -> tab[data -> player_posX - 1][data -> player_posY] = 'P';
		data -> tab[data -> player_posX][data -> player_posY] = '0';
		mlx_put_image_to_window(data -> mlx, data -> win,
		 (data -> player_tile),32 * (data -> player_posX + 1), 32 * (data -> player_posY));
		mlx_put_image_to_window(data -> mlx, data -> win,
		 (data -> empty_tile),32 * (data -> player_posX), 32 * (data -> player_posY));
		return (data);
	}
}
int	ft_key_hooks(t_data *data)
{
	mlx_hook(data -> win, 3, 1L<<0, inputs, &data);
}
