#include "parsing.h"

int	main()
{
	t_map	*map;

	map = ft_return_map();
	if (!map)
		free(map);
	if (map != NULL)
	{
		ft_free_all(map);
	}
}
