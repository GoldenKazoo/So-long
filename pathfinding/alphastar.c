typedef struct Node
{
	int	x;
	int	y;
	int	cost;
	int	heuristic;
} t_node;

typedef struct Element
{
	int			index;
	t_element	*next;
} t_element;

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
int	ft_compare_heuristic(char **tab, t_node *node1, t_node *node2)
{
	if (node1 -> heuristic < node2 -> heuristic)
		return (1);
	else if (node1 -> heuristic == node2 -> heuristic)
		return (0);
	else
		return (-1);
}


