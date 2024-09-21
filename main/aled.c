#include "minilibx-linux/mlx.h"
#include <stdio.h>
#include <stdlib.h>
#include <X11/Xutil.h>

typedef struct	s_vars {
	void	*mlx;
	void	*win;
}				t_vars;

int	close(int keycode, t_vars *vars)
{
	printf("%i", keycode);
	if(keycode == XK_Escape)
		mlx_destroy_window(vars->mlx, vars->win);
	return (0);
}

int	main(void)
{
	t_vars	*vars;

	vars = malloc(sizeof(t_vars));
	vars -> mlx = mlx_init();
	vars -> win = mlx_new_window(vars -> mlx, 1920, 1080, "Hello world!");
	mlx_hook(vars -> win, 2, 1L<<0, close, vars);
	mlx_loop(vars -> mlx);
}
