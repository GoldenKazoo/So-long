#include "parsing.h"
#include "minilibx-linux/mlx.h"

t_data	*ft_data_init(t_data *data)
{
	data = ft_return_map(data);
	data -> mlx = mlx_init();
	data -> win = mlx_new_window(data -> mlx, 64 * data -> map_width,
	64 * data -> map_height, "So long");
	data -> tile_dim = 64;
	ft_print_tab(data);
	data -> empty_tile = mlx_xpm_file_to_image(data -> mlx,
	"xpm/Grass.xpm", &(data -> tile_dim), &(data -> tile_dim));
	if (!data -> empty_tile)
{
    // Gestion de l'erreur, libérer correctement et retourner NULL
    ft_free_all(data);
    return NULL;
}


	data -> player_tile = mlx_xpm_file_to_image(data -> mlx,
	"xpm/Player1.xpm", &(data -> tile_dim), &(data -> tile_dim));
	if (!data -> empty_tile)
{
    // Gestion de l'erreur, libérer correctement et retourner NULL
    ft_free_all(data);
    return NULL;
}


	data -> exit_tile = mlx_xpm_file_to_image(data -> mlx,
	"xpm/Exit.xpm", &(data -> tile_dim), &(data -> tile_dim));
	if (!data -> empty_tile)
{
    // Gestion de l'erreur, libérer correctement et retourner NULL
    ft_free_all(data);
    return NULL;
}


	data -> wall_tile = mlx_xpm_file_to_image(data -> mlx,
	"xpm/Wall.xpm", &(data -> tile_dim), &(data -> tile_dim));
	if (!data -> empty_tile)
	{
    // Gestion de l'erreur, libérer correctement et retourner NULL
    ft_free_all(data);
    return NULL;
	}
	data -> obj_tile = mlx_xpm_file_to_image(data -> mlx,
	"xpm/Item.xpm", &(data -> tile_dim), &(data -> tile_dim));

	if (!data -> empty_tile)
{
    // Gestion de l'erreur, libérer correctement et retourner NULL
    ft_free_all(data);
    return NULL;
}
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
	int		i;
	int		fd;

	fd = open("map/valide_map.ber", O_RDONLY);
	i = 1;
	data = malloc(sizeof(t_data));
	if (!data)
		return (0);
	data = ft_data_init(data);
	data -> player_posX = get_posX(data);
	data -> player_posY = get_posY(data);
	printf("%c\n", data -> map_elements[2]);
	if(!data)
	{
		return (0);
	}
	if (i == 1)
	{
		ft_print_map(data);
	}
	ft_key_hooks(data);
	mlx_loop(data -> mlx);
}
