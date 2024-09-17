#include "parsing.h"
t_node	*get_small_fcost(t_list *open_list)
{
	t_node	*smallest;

	while (open_list->head != NULL)
	{
		if(open_list->head->f_cost < smallest)
		{
			smallest = open_list -> head;
		}
	}
	return (smallest);
}
int	in_closed_list(t_node *node, t_list *closed_list)
{
	while (closed_list-> head != NULL)
	{
		if (closed_list -> head == node)
			return (1);
	}
	return(0);
}
int	in_open_list(t_node *node, t_list *open_list)
{
	while (open_list-> head != NULL)
	{
		if (open_list -> head == node)
			return (1);
	}
	return(0);
}
void	add_list(t_node *node, t_list *list)
{
	while (list -> head  -> next != NULL)
		list-> head = (list -> head) -> next;
	list -> head -> next = node;
}

int	valide_path(char *direction, )
{
	if (direction == "right" &&)
	{

	}
	if(direction == "left")
	{

	}
	if(direction == "up")
	{

	}
	if(direction == "down")
	{

	}
}
