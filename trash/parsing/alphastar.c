#include "parsing.h"


int	ft_abs(int	value)
{
	if(value < 0)
		return (value * -1);
	return (value);
}
t_node	ft_search_start(char	**tab, t_node *start)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (tab[x][y] != 'P')
	{
		x++;
		y++;
	}
	start -> x = x;
	start -> y = y;
}

t_node	ft_search_exit(char	**tab, t_node *exit)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (tab[x][y] != 'P')
	{
		x++;
		y++;
	}
	exit -> x = x;
	exit -> y = y;
}
t_node	**ft_create_nodes(t_map *map)
{
	int		i;
	int		x;
	int		y;
	t_node	**node_tab;

	i = 0;
	node_tab = malloc(sizeof(t_node *) * (map -> width));
	if (!node_tab)
		return (NULL);
	while (i < map -> height)
	{
		node_tab[i] = malloc(sizeof(t_node) * map -> width);
		i++;
	}
	while (x < map -> height)
	{
		while (y < map -> width)
		{
			node_tab[x][y].element = map -> tab[x][y];
			node_tab[x][y].x = x;
			node_tab[x][y].y = y;
			node_tab[x][y].heuristic_P = 0;
			node_tab[x][y].heuristic_E = 0;
			node_tab[x][y].cost = 0;
			y++;
		}
		y = 0;
		x++;
	}
}
int	ft_compare_heuristic(char **tab, t_node *node1, t_node *node2)
{
	if (node1 -> heuristic < node2 -> heuristic)
		return (1);
	else if (node1 -> heuristic == node2 -> heuristic)
		return (0);
	else
		return (-1);
}

int main()
{
	t_list	*open_list;
	t_list	*closed_list;

	open_list = malloc(sizeof(t_list));
	closed_list = malloc(sizeof(t_list));


}


