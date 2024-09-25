#include "parsing.h"

int	ft_check_line(t_data *data, char *l)
{
	int	i;

	i = 0;
	while (i < ft_strlen(l))
	{
		if (l[i] == 'P')
			data -> map_elements[0] = data -> map_elements[0] + 1;
		if (l[i] == 'E')
			data -> map_elements[1] = data -> map_elements[1] + 1;
		if (l[i] == 'C')
			data -> map_elements[2] = data -> map_elements[2] + 1;

		if (l[i] != '1' || l[i] != '0' || l[i] != 'P' || l[i] != 'E' || l[i] != 'C')
			return (1); // Illegal char
		if (data -> map_elements[0] > 1)
			return (6); // Too much exit
		if (data -> map_elements[1] > 1)
			return (7); // Too much player
		i++;
	}
	if (l[0] || l[ft_strlen(l) - 1])
		return (3);
	return (0);
}
int	ft_check_first_last_line(char *line)
{
	int	i;

	i = 0;
	while (i < ft_strlen(line))
	{
		if(line[i] != '1')
			return (2); // No wall around
		i++;
	}
	return (0);
}

int	ft_check_elements(t_data *data)
{
	if (data -> map_elements[0] < '1')
		return (6);
	if (data -> map_elements[1] < '1')
		return (4);
	if (data -> map_elements[2] < '1')
		return (8);
	return (0);
}
