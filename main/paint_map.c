#include "minilibx-linux/mlx.h"
#include <stdlib.h>
#include "parsing.h"

// Fonction pour obtenir la couleur d'un pixel d'une image
int ft_get_pixelcolor(t_img *img, int x, int y)
{
    char *pix = img->addr + (y * img->line_len + x * (img->bpp / 8));
    return *(unsigned int*)pix;
}

// Fonction pour dessiner un pixel sur une image
void ft_put_pixelimage(t_img *img, int x, int y, int color)
{
    char *pixel = img->addr + (y * img->line_len + x * (img->bpp / 8));
    *(unsigned int*)pixel = color;
}

// Fonction pour dessiner une tuile (64x64) à la position (x, y)
void ft_draw_tile(t_img *img, t_img *tile, int x, int y)
{
    int i, j;
    unsigned int color;

    for (i = 0; i < 64; i++)
    {
        for (j = 0; j < 64; j++)
        {
            color = ft_get_pixelcolor(tile, i, j);
            if (!(color == (unsigned int)(0xFF << 24))) // Ne pas dessiner les pixels transparents
                ft_put_pixelimage(img, i + (x * 64), j + (y * 64), color);
        }
    }
}

void    ft_paint_map(t_data *data)
{
    t_img   img;
    int i;
    int j;

    i = 0;
    j = 0;

    // Créer une nouvelle image vide où dessiner la tuile
    img.mlx_img = mlx_new_image(data -> mlx, data -> map_width * 64, data -> map_height * 64);
    img.addr = mlx_get_data_addr(img.mlx_img, &img.bpp, &img.line_len, &img.endian);

    // Vérification d'erreur pour `mlx_get_data_addr`
    if (!img.addr)
    {
        // Gestion de l'erreur
        return;
    }

    while (j < data -> map_height)
    {
        i = 0;
        while (i < data -> map_width)
        {
            // Vérification des tuiles avant de les dessiner
            if (data -> tab[j][i] == 'P')
                ft_draw_tile(&img, data -> player_tile, i, j);
            if (data -> tab[j][i] == 'E' && data->exit_tile)
                ft_draw_tile(&img, data -> exit_tile, i, j);
            if (data -> tab[j][i] == 'C' && data->obj_tile)
                ft_draw_tile(&img, data -> obj_tile, i, j);
            if (data -> tab[j][i] == '0' && data->empty_tile)
                ft_draw_tile(&img, data -> empty_tile, i, j);
            if (data -> tab[j][i] == '1' && data->wall_tile)
                ft_draw_tile(&img, data -> wall_tile, i, j);
             if (data -> tab[j][i] == '\n' && data->wall_tile)
                printf("aled");
            i++;
        }
        printf("\n");
        j++;
    }

    // Afficher l'image dans la fenêtre
    mlx_put_image_to_window(data -> mlx, data -> win, img.mlx_img, 0, 0);
}
