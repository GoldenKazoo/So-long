#include "parsing.h"
#include "minilibx-linux/mlx.h"

t_data	*ft_data_init(t_data *data)
{
	data = ft_return_map(data);
	data -> mlx = mlx_init();
	data -> win = mlx_new_window(data -> mlx, 32 * data -> map_width,
	32 * data -> map_height, "So long");
	data -> tile_dim = 32;
	ft_print_tab(data);
	data -> empty_tile = mlx_xpm_file_to_image(data -> mlx,
	"xpm/Grass.xpm", &(data -> tile_dim), &(data -> tile_dim));
	data -> player_tile = mlx_xpm_file_to_image(data -> mlx,
	"xpm/Moumouton.xpm", &(data -> tile_dim), &(data -> tile_dim));
	data -> exit_tile = mlx_xpm_file_to_image(data -> mlx,
	"xpm/Grass.xpm", &(data -> tile_dim), &(data -> tile_dim));
	data -> wall_tile = mlx_xpm_file_to_image(data -> mlx,
	"xpm/Grass.xpm", &(data -> tile_dim), &(data -> tile_dim));
	data -> obj_tile = mlx_xpm_file_to_image(data -> mlx,
	"xpm/Grass.xpm", &(data -> tile_dim), &(data -> tile_dim));
	data -> player_posX = get_posX(data);
	data -> player_posY = get_posX(data);
	if (!data)
		free(data);
	if (data == NULL)
		ft_free_all(data);
	return (data);
}

t_data	*ft_data_init_aux(t_data *data)
{
	if (!data)
		return (NULL);
	if (ft_return_map(data) == NULL)
	{
		free(data);
		return NULL;
	}
	data = ft_data_init(data);
	if (!data)
		free(data);
	if (data == NULL)
		ft_free_all(data);
	return (data);
}
int	main()
{
	t_data *data;
	static int		i;

	i = 1;
	data = malloc(sizeof(t_data));
	if (!data)
		return(0);
	data = ft_data_init(data);
	if(!data)
	{
		return (0);
	}
	if (i == 1)
	{
		// ft_print_map(data);
		i++;
	}
	ft_key_hooks(data);
	mlx_loop(data -> mlx);
}
