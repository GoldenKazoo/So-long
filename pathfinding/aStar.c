#include "parsing.h"

int main()
{
	t_list	*open_list;
	t_list	*closed_list;
	t_node	*depart;
	t_node	*arrive;
	t_node	*current;
	t_node	**tab_node;
	t_node *r_node;
	t_node *l_node;
	t_node *u_node;
	t_node *d_node;

	depart = get_node_P(tab_node);
	open_list -> head = depart; //Ajout du node de depart dans la liste open
	while(1)
	{
		current = get_small_fcost(open_list); //Rcuperation du plus petit fcost dans l'openlist
		closed_list -> head = current;
		if(valide_path("right") == 1 && in_closed_list() == -1)
		{
			r_node = &tab_node[(current -> x)][(current -> y) + 1];
			if (in_closed_list(r_node) == -1)
				add_list(r_node, open_list);
			if (int_open_list(r_node) == 1)
			{
				if (r_node -> p_cost < ft_abs(r_node -> x, depart -> x) + ft_abs(r_node -> y, depart -> y))
				{
					r_node -> parent = current;
					r_node -> p_cost = ft_abs(r_node -> x, depart -> x) + ft_abs(r_node -> y, depart -> y);
					r_node -> e_cost = ft_abs(r_node -> x, depart -> x) + ft_abs(r_node -> y, depart -> y);
					r_node -> f_cost = r_node-> p_cost + r_node-> e_cost;
				}
			}
			r_node -> parent = current;
			r_node -> p_cost = ft_abs(r_node -> x, depart -> x) + ft_abs(r_node -> y, depart -> y);
			r_node -> e_cost = ft_abs(r_node -> x, depart -> x) + ft_abs(r_node -> y, depart -> y);
			r_node -> f_cost = r_node-> p_cost + r_node-> e_cost;
		}
		if(valide_path("left") == 1 && in_closed_list() == -1)
		{
			l_node = &tab_node[(current -> x)][(current -> y) - 1];
			if (in_closed_list(r_node) == -1)
				add_list(l_node, open_list);
			l_node-> parent = current;
			l_node-> p_cost = ft_abs(l_node -> x, depart -> x) + ft_abs(l_node -> y, depart -> y);
			l_node-> e_cost = ft_abs(l_node -> x, depart -> x) + ft_abs(l_node -> y, depart -> y);
			l_node-> f_cost = l_node-> p_cost + l_node-> e_cost;
		}
		if(valide_path("up") == 1 && in_closed_list() == -1)
		{
			u_node = &tab_node[(current -> x - 1)][(current -> y)];
			if (in_closed_list(r_node) == -1)
				add_list(u_node, open_list);
			u_node-> parent = current;
			u_node-> p_cost = ft_abs(u_node -> x, depart -> x) + ft_abs(u_node -> y, depart -> y);
			u_node-> e_cost = ft_abs(u_node -> x, depart -> x) + ft_abs(u_node -> y, depart -> y);
			u_node-> f_cost = u_node-> p_cost + u_node-> e_cost;
		}
		if(valide_path("down") == 1 && in_closed_list() == -1)
		{
			d_node = &tab_node[(current -> x + 1)][(current -> y)];
			if (in_closed_list(r_node) == -1)
				add_list(d_node, open_list);
			d_node-> parent = current;
			d_node-> p_cost = ft_abs(d_node -> x, depart -> x) + ft_abs(d_node -> y, depart -> y);
			d_node-> e_cost = ft_abs(d_node -> x, depart -> x) + ft_abs(d_node -> y, depart -> y);
			d_node-> f_cost = d_node-> p_cost + d_node-> e_cost;
		}
		if (check_end(closed_list) == 1)
			break;
	}
}
