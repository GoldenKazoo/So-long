/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zchagar <zchagar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 04:16:19 by zchagar           #+#    #+#             */
/*   Updated: 2024/10/16 04:41:35 by zchagar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void	ft_bzero(void *s, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		*(char *)&s[i] = 0;
		i++;
	}
}

void	*ft_calloc(size_t elementcount, size_t elementsize)
{
	void	*p;
	size_t	i;

	if (elementsize > 0 && elementcount > (UINT_MAX / elementsize))
		return (NULL);
	i = 0;
	p = malloc(elementcount * elementsize);
	if (!p)
	{
		return (NULL);
	}
	ft_bzero(p, elementcount * elementsize);
	return (p);
}

void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	i = 0;
	while (s && s[i] != '\0')
	{
		write(fd, &s[i], 1);
		i++;
	}
}
