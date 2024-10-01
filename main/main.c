#include "parsing.h"
#include "minilibx-linux/mlx.h"

void	ft_data_init_img_aux(t_data *data, t_img *img, char * filename)
{

	img -> mlx_img = mlx_xpm_file_to_image(data -> mlx, filename, &(data -> tile_dim), &(data -> tile_dim));
	img -> bpp = 8;
	img -> line_len = 64;
	img -> endian = 0;
	// img -> addr = mlx_get_data_addr(img -> mlx_img, &(img -> bpp), &(img -> line_len), &(img -> endian));
}
void	ft_data_init_img(t_data *data)
{
	ft_data_init_img_aux(data, data -> player_tile, "xpm/Player.xpm");
	ft_data_init_img_aux(data, data -> empty_tile, "xpm/Grass.xpm");
	ft_data_init_img_aux(data, data -> wall_tile, "xpm/Wall.xpm");
	ft_data_init_img_aux(data, data -> obj_tile, "xpm/Item.xpm");
	ft_data_init_img_aux(data, data -> exit_tile, "xpm/Exit.xpm");
}
t_data	*ft_data_init(t_data *data, int fd)
{
	data = ft_return_map(data, fd);
	data -> mlx = mlx_init();
	data -> win = mlx_new_window(data -> mlx, 64 * data -> map_width,
	64 * data -> map_height, "So long");
	data -> tile_dim = 64;
	ft_data_init_img(data);
	data -> player_posX = get_posX(data);
	data -> player_posY = get_posX(data);
	if (!data)
		free(data);
	if (data == NULL)
		ft_free_all(data);
	return (data);
}

t_data	*ft_data_init_aux(t_data *data, int fd)
{
	if (!data)
		return (NULL);
	if (ft_return_map(data, fd) == NULL)
	{
		free(data);
		return NULL;
	}
	data = ft_data_init(data, fd);
	if (!data)
		free(data);
	if (data == NULL)
		ft_free_all(data);
	return (data);
}
int	main(int argc, char **argv)
{
	t_data *data;
	int		i;
	int		fd;

	if (argc != 2)
		return (0);
	fd = open(argv[1], O_RDONLY);
	i = 1;
	data = malloc(sizeof(t_data));
	if (!data)
		return (0);

	data -> player_tile = malloc(sizeof(t_img));
	data -> empty_tile = malloc(sizeof(t_img));
	data -> wall_tile = malloc(sizeof(t_img));
	data -> obj_tile = malloc(sizeof(t_img));
	data -> exit_tile = malloc(sizeof(t_img));
	data = ft_data_init(data, fd);
	printf("%i\n", data -> player_tile -> bpp);
	data -> player_posX = get_posX(data);
	data -> player_posY = get_posY(data);
	if(!data)
	{
		return (0);
	}
	ft_print_tab(data);
	ft_key_hooks(data);
	mlx_loop(data -> mlx);
}
