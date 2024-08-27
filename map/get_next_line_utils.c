/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zchagar <zchagar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 15:16:50 by zchagar           #+#    #+#             */
/*   Updated: 2024/06/27 16:33:30 by zchagar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strdup(char *src)
{
	char	*p;
	int		i;

	i = 0;
	p = malloc(sizeof(char) * ft_strlen(src) + 1);
	if (!p)
	{
		return (NULL);
	}
	while (src[i] != '\0')
	{
		p[i] = src[i];
		i++;
	}
	p[i] = '\0';
	return (p);
}

char	*ft_fill_join(char *s1, char *s2, char *p)
{
	size_t		i;
	size_t		k;

	i = 0;
	k = 0;
	while (s1[i] != '\0')
	{
		p[i] = s1[i];
		i++;
	}
	while (s2[k] != '\0')
		p[i++] = s2[k++];
	p[i] = '\0';
	return (p);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char		*p;

	if (!s1)
	{
		s1 = ft_strdup("");
		if (!s1)
			return (NULL);
	}
	if (!s2)
	{
		s2 = ft_strdup("");
		if (!s2)
			return (NULL);
	}
	p = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2)) + 1);
	if (!p)
	{
		free(p);
		return (NULL);
	}
	p = ft_fill_join(s1, s2, p);
	free(s1);
	return (p);
}

char	*ft_substr(char *s, unsigned int start, size_t len)
{
	char	*p;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	if (len > ft_strlen(s + start))
		len = ft_strlen(s + start);
	p = malloc(sizeof(char) * len + 1);
	if (!p)
		return (NULL);
	while (s[i] != '\0')
	{
		if (i >= start && j < len)
		{
			p[j++] = s[i];
		}
		i++;
	}
	p[j] = '\0';
	return (p);
}

char	*ft_strchr(const char *str, int searchedchar)
{
	char	*p;
	int		i;

	i = 0;
	p = NULL;
	if (!str)
		return (NULL);
	while (str[i] != '\0')
	{
		if (str[i] == (char)searchedchar)
		{
			p = (char *)&str[i];
			return (p);
		}
		i++;
	}
	if (str[i] == (char) searchedchar)
	{
		p = (char *) &str[i];
		return (p);
	}
	return (p);
}
