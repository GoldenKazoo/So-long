#include "parsing.h"

t_node	**ft_to_nodetab(t_map *map)
{
	int		i;
	int		j;
	t_node	**nodetab;

	i = 0;
	j = 0;

	nodetab = malloc(sizeof(t_node *) * (map -> height));
	while ( i < map -> height)
	{
		nodetab[i] = malloc(sizeof(t_node) * (map -> width));
		j = 0;
		while (j < map -> width)
		{
			nodetab[i][j].element = map -> tab[i][j];
			nodetab[i][j].x = i;
			nodetab[i][j].y = j;
			nodetab[i][j].f_cost = 0;
			nodetab[i][j].p_cost = 0;
			nodetab[i][j].e_cost = 0;
			j++;
		}
		i++;
	}
	return (nodetab);
}

t_node *get_node_P(t_node **tabnode, t_map map)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (i < map.height)
	{
		j = 0;
		while (j < map.width)
		{
			if (tabnode[i][j].element == 'P')
			{
				return (&tabnode[i][j]);
			}
			j++;
		}
		i++;
	}
	return (NULL);
}

valide_path("right");
get_small_fcost(open_list);
in_closed_list(r_node);
in_open_list(r_node);
add_list(l_node, open_list);
