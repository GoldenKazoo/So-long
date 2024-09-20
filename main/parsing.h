# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>
# include <limits.h>
#include "get_next_line.h"

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct s_data
{
	char	**tab;
	int		map_width;
	int		map_height;
	int		tile_dim;
	int		player_posX;
	int		player_posY;
	void	*empty_tile;
	void	*wall_tile;
	void	*player_tile;
	void	*exit_tile;
	void	*obj_tile;
	void	*mlx;
	void	*win;
} t_data;

// typedef struct s_map
// {
// 	int	height;
// 	int	width;
// 	char	**tab;
// } t_map;

// typedef struct s_node
// {
// 	char	element;
// 	int		x;
// 	int		y;
// 	int		f_cost;
// 	int		p_cost; //distance du depart
// 	int		e_cost; //distance arrivee
// 	struct s_node	*next;
// 	struct s_node	*parent;
// } t_node;

// typedef struct s_list
// {
// 	t_node	*head;
// } t_list;
void	ft_free_all(t_data *data);
t_data	*ft_return_map ();
int	ft_coherence(char *line, int index, t_data *data, char	*count_elements);
void	ft_count_elements(char c, char *elements);
void	ft_printerror(int error);

void    ft_print_map(t_data *data);
void	ft_print_tab(t_data *data);
int ft_give_dim(t_data *data, int fd);
int	ft_notchar (char c);
int	ft_check_1st(size_t roof, char *line);
int	ft_check_wall_and_char(size_t roof, char *line, char *elements);
int	ft_check_elements_end(char *elements);
int	ft_check_top_bot(t_data *data);
int	ft_print_error(int state, t_data *data, int fd);
void	ft_free_all(t_data *data);
t_data	*ft_return_map ();
