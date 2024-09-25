
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
	if ((keycode == XK_W ||keycode == XK_w) && data -> tab[(data -> player_posX) - 1][(data -> player_posY)] != '1' )//&& data -> tab[(data -> player_posX) - 1][(data -> player_posY)] != 'E')
	{
		if (data -> tab[(data -> player_posX) - 1][(data -> player_posY)] == 'C')
		{
			data -> map_elements[2] = data -> map_elements[2] - 1;
		}
		if (data -> tab[(data -> player_posX) - 1][(data -> player_posY)] == 'E' && (data -> map_elements[2] == '0'))
			exit(EXIT_FAILURE);
		if (data -> tab[(data -> player_posX) - 1][(data -> player_posY)] != 'E')
		{
		data -> player_posX = data -> player_posX;
		data -> player_posY = data -> player_posY;
		data -> tab[data -> player_posX][data -> player_posY] = '0';
		mlx_put_image_to_window(data -> mlx, data -> win,
		 (data -> empty_tile),64 * (data -> player_posY), 64 * (data -> player_posX));
		data -> tab[(data -> player_posX) - 1][(data -> player_posY)] = 'P';
		data -> player_posX = get_posX(data);
		mlx_put_image_to_window(data -> mlx, data -> win,
		 (data -> player_tile),64 * (data -> player_posY), 64 * (data -> player_posX));
		}
	}
	if ((keycode == XK_S ||keycode == XK_s) && data -> tab[(data -> player_posX) + 1][(data -> player_posY)] != '1' )//&& data -> tab[(data -> player_posX) + 1][(data -> player_posY)] != 'E')
	{
		if (data -> tab[(data -> player_posX) + 1][(data -> player_posY)] == 'C')
		{
			data -> map_elements[2] = data -> map_elements[2] - 1;
		}
		if (data -> tab[(data -> player_posX) + 1][(data -> player_posY)] == 'E' && (data -> map_elements[2] == '0'))
			exit(EXIT_FAILURE);
		if (data -> tab[(data -> player_posX) + 1][(data -> player_posY)] != 'E')
		{
		data -> player_posX = data -> player_posX;
		data -> player_posY = data -> player_posY;
		data -> tab[data -> player_posX][data -> player_posY] = '0';
		mlx_put_image_to_window(data -> mlx, data -> win,
		 (data -> empty_tile),64 * (data -> player_posY), 64 * (data -> player_posX));
		data -> tab[(data -> player_posX) + 1][(data -> player_posY)] = 'P';
		data -> player_posX = get_posX(data);
		mlx_put_image_to_window(data -> mlx, data -> win,
		 (data -> player_tile),64 * (data -> player_posY), 64 * (data -> player_posX));
		}
	}
	return(0);
}

void	ft_moove_right_left(int keycode, t_data *data)
{
	if ((keycode == XK_A ||keycode == XK_a) && data -> tab[(data -> player_posX)][(data -> player_posY) - 1] != '1')//&& data -> tab[(data -> player_posX)][(data -> player_posY)- 1] != 'E')
	{
		if (data -> tab[(data -> player_posX)][(data -> player_posY) - 1] == 'C')
			data -> map_elements[2] = data -> map_elements[2] - 1;
		if (data -> tab[(data -> player_posX)][(data -> player_posY) - 1] == 'E' && (data -> map_elements[2] == '0'))
			exit(EXIT_FAILURE);
		if (data -> tab[(data -> player_posX)][(data -> player_posY)- 1] != 'E')
		{
			data -> player_posY = data -> player_posY;
			data -> tab[data -> player_posX][data -> player_posY] = '0';
			mlx_put_image_to_window(data -> mlx, data -> win,
			 (data -> empty_tile),64 * (data -> player_posY), 64 * (data -> player_posX));
			data -> tab[(data -> player_posX)][(data -> player_posY) - 1] = 'P';
			data -> player_posY = get_posY(data);
			mlx_put_image_to_window(data -> mlx, data -> win,
			 (data -> player_tile),64 * (data -> player_posY), 64 * (data -> player_posX));
			printf("PosX:%i\n", data -> player_posY);
		}

	}
	if ((keycode == XK_D ||keycode == XK_d)&& data -> tab[(data -> player_posX)][(data -> player_posY) + 1] != '1')//&& data -> tab[(data -> player_posX)][(data -> player_posY) + 1] != 'E')
	{
		if (data -> tab[(data -> player_posX)][(data -> player_posY) + 1] == 'E' && (data -> map_elements[2] == '0'))
			exit(EXIT_FAILURE);

		if (data -> tab[(data -> player_posX)][(data -> player_posY) + 1] == 'C')
		{
			data -> map_elements[2] = data -> map_elements[2] - 1;
		}
		if (data -> tab[(data -> player_posX)][(data -> player_posY) + 1] != 'E')
		{
		printf("Next :%c\n", data -> tab[(data -> player_posX)][(data -> player_posY) + 1]);
		data -> player_posY = data -> player_posY;
		data -> tab[data -> player_posX][data -> player_posY] = '0';
		mlx_put_image_to_window(data -> mlx, data -> win,
		 (data -> empty_tile),64 * (data -> player_posY), 64 * (data -> player_posX));
		data -> tab[(data -> player_posX)][(data -> player_posY) + 1] = 'P';
		data -> player_posY = get_posY(data);
		mlx_put_image_to_window(data -> mlx, data -> win,
		 (data -> player_tile),64 * (data -> player_posY), 64 * (data -> player_posX));
		printf("PosX:%i\n", data -> player_posY);
		}
	}
}
int	inputs(int keycode, t_data *data)
{
	int i;

	i = 0;
	if(keycode == XK_Escape)
	{
	printf("%s\n", "SKILL ISSUE");
	mlx_destroy_image(data -> mlx, data -> player_tile);
	mlx_destroy_image(data -> mlx, data -> empty_tile);
	mlx_destroy_image(data -> mlx, data -> wall_tile);
	mlx_destroy_image(data -> mlx, data -> obj_tile);
	mlx_destroy_image(data -> mlx, data -> exit_tile);
	mlx_destroy_window(data -> mlx, data -> win);
	mlx_destroy_display(data -> mlx);
	free(data-> mlx);
	ft_print_tab(data);
	ft_free_all(data);
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
	i++;
	printf("Player X:%i\n", data -> player_posX);
	printf("Player Y:%i\n", data -> player_posY);
	printf("%c\n", data -> map_elements[2]);
	return (0);
}
int	ft_key_hooks(t_data *data)
{
	mlx_key_hook(data -> win, inputs, data);
	return(0);
}
