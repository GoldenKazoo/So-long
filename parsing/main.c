#include "parsing.h"

int	main()
{
	t_map	*map;

	map = ft_return_map();
	if (map != NULL)
		free(map);
}
