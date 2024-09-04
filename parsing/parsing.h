# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>
# include <limits.h>
#include "get_next_line.h"

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct Map
{
	int	height;
	int	width;
	char	**tab;
} t_map;

int	ft_coherence(char *line, int index, t_map *(map), char	*count_elements);
void	ft_count_elements(char c, char *elements);
void	ft_printerror(int error);


int ft_give_dim(t_map *map, int fd);
int	ft_notchar (char c);
int	ft_check_1st(size_t roof, char *line);
int	ft_check_wall_and_char(size_t roof, char *line, char *elements);
int	ft_check_elements_end(char *elements);
int	ft_check_top_bot(t_map *map);
int	ft_print_error(int state, t_map *map, int fd);
void	ft_free(t_map *map);
