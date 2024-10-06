#include "parsing.h"
#include "minilibx-linux/mlx.h"
#include <fcntl.h> // pour open()

void	ft_data_init_img_aux(t_data *data, t_img *img, char *filename)
{
    img->mlx_img = mlx_xpm_file_to_image(data->mlx, filename, &(data->tile_dim), &(data->tile_dim));
    if (!img->mlx_img)
    {
        printf("Erreur lors du chargement de l'image %s\n", filename);
        exit(1);
    }
    img->addr = mlx_get_data_addr(img->mlx_img, &(img->bpp), &(img->line_len), &(img->endian));
    if (!img->addr)
    {
        printf("Erreur lors de l'obtention des données de l'image\n");
        exit(1);
    }
}

void	ft_data_init_img(t_data *data)
{
    ft_data_init_img_aux(data, data->player_tile, "xpm/Player1.xpm");
    ft_data_init_img_aux(data, data->empty_tile, "xpm/Grass.xpm");
    ft_data_init_img_aux(data, data->wall_tile, "xpm/Wall.xpm");
    ft_data_init_img_aux(data, data->obj_tile, "xpm/Item.xpm");
    ft_data_init_img_aux(data, data->exit_tile, "xpm/Exit.xpm");
}

t_data	*ft_data_init(t_data *data, int fd)
{
    data = ft_return_map(data, fd);
    if (!data || !data->tab)
    {
        printf("Erreur lors du chargement de la carte\n");
        return (NULL);
    }
    
    data->mlx = mlx_init();
    if (!data->mlx)
    {
        printf("Erreur: échec de l'initialisation de MLX\n");
        return (NULL);
    }
    
    data->win = mlx_new_window(data->mlx, 64 * data->map_width, 64 * data->map_height, "So long");
    if (!data->win)
    {
        printf("Erreur: échec de la création de la fenêtre\n");
        return (NULL);
    }

    data->tile_dim = 64;
    ft_data_init_img(data);  // Initialiser toutes les images
    data->player_posX = get_posX(data);
    data->player_posY = get_posY(data);

    return (data);
}

int	main(int argc, char **argv)
{
    t_data *data;
    int fd;

    if (argc != 2)
    {
        printf("Usage: %s <map_file>\n", argv[0]);
        return (1);
    }

    fd = open(argv[1], O_RDONLY);
    if (fd < 0)
    {
        printf("Erreur: impossible d'ouvrir le fichier %s\n", argv[1]);
        return (1);
    }

    data = malloc(sizeof(t_data));
    if (!data)
        return (1);

    data->player_tile = malloc(sizeof(t_img));
    data->empty_tile = malloc(sizeof(t_img));
    data->wall_tile = malloc(sizeof(t_img));
    data->obj_tile = malloc(sizeof(t_img));
    data->exit_tile = malloc(sizeof(t_img));

    data = ft_data_init(data, fd);
	printf("LArgeur :%i \n", data -> map_width);
	printf("Longueur :%i \n", data -> map_height);
    if (!data)
    {
        printf("Erreur lors de l'initialisation des données\n");
        return (1);
    }
    
    // Dessiner la carte
    ft_paint_map(data);
    ft_key_hooks(data);
    // Lancer la boucle MLX
    mlx_loop(data->mlx);

    return (0);
}
