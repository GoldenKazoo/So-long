#include "parsing.h"
#include "minilibx-linux/mlx.h"

t_data	*ft_data_init(t_data *data)
{
	if (!data)
		return (NULL);
	if (ft_return_map(data) == NULL)
	{
		free(data);
		return NULL;
	}

	data = ft_return_map(data);
	ft_print_tab(data);
	data -> mlx = mlx_init();
	data -> win = mlx_new_window(data -> mlx,
	 32 * data -> map_height, 32 * data -> map_width, "So long");
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
	ft_print_tab(data);
	if (!data)
		free(data);
	if (data == NULL)
		ft_free_all(data);
	ft_print_tab(data);
	return (data);
}
int	main()
{
	t_data *data;

	data = malloc(sizeof(t_data));
	if (!data)
		return(0);
	data = ft_data_init(data);
	if(!data)
	{
		return (0);
	}
	ft_print_map(data);
	mlx_loop(data -> mlx);
}
