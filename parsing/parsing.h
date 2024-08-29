# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>
# include <limits.h>
#include "get_next_line.h"

typedef struct Map
{
	int	height;
	int	width;
	char	**tab;
} t_map;

int	ft_coherence(char *line, int index, t_map *(map), char	*count_elements);
char	*ft_count_elements(int index, char* elements, char c);
