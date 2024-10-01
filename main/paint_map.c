#include "parsing.h"
#include "minilibx-linux/mlx.h"

int ft_get_pixelcolor(t_img *img, int x, int y)
{
	int		color;
	char	*pix;

	pix = (img -> addr) + (y * img -> line_len + x * ((img -> bpp) / 8));
	color = *(int*)pix;
	return (color);
}

void ft_put_pixelimage(t_img *img, int x, int y, int color)
{
	char	*pixel;

	pixel = (img -> addr) + (y * img -> line_len + x * ((img -> bpp) / 8));
	*(int*)pixel = color;
}
void	ft_draw_tile(t_img *img,t_img *tile, int	x, int	y)
{
	int	i;
	int	j;
	int	color;

	i = 0;
	j = 0;
	while (i < 64)
	{
		j = 0;
		while (j < 64)
		{
			color = ft_get_pixelcolor(tile, i, j);
			ft_put_pixelimage(img, i + (x * 64), j + (y * 64), color);
			j++;
		}
		i++;
	}
}
void	ft_print_map(t_img *img, t_data *data, int x, int y)
{
	if (data -> tab[x][y] == 'P')
		ft_draw_tile(img, data -> player_tile, x, y);
	if (data -> tab[x][y] == 'E')
		ft_draw_tile(img, data -> exit_tile, x, y);
	if (data -> tab[x][y] == 'C')
		ft_draw_tile(img, data -> obj_tile, x, y);
	if (data -> tab[x][y] == '0')
		ft_draw_tile(img, data -> empty_tile, x, y);
	if (data -> tab[x][y] == '1')
		ft_draw_tile(img, data -> wall_tile, x, y);
}
void	ft_paint_map(t_data *data)
{
	int		x;
	int		y;
	void	*img;

	x = 0;
	y = 0;
	img = mlx_new_image(data -> mlx, 1000, 1000);
	while(x < data -> map_height)
	{
		y = 0;
		while(y < data -> map_width)
		{
			ft_print_map(img, data, x, y);
			y++;
		}
		x++;
	}
}
