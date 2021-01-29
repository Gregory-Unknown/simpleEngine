/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esobchak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 15:44:33 by esobchak          #+#    #+#             */
/*   Updated: 2020/11/25 15:11:29 by esobchak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int			ft_strlen(const char *s1)
{
	size_t i;

	if (!s1)
		return (0);
	i = 0;
	while (*s1)
	{
		i++;
		s1++;
	}
	return (i);
}

char		*ft_strdup(const char *s1)
{
	char	*dest;
	size_t	len;
	size_t	i;

	if (!s1)
		return (NULL);
	len = ft_strlen(s1) + 1;
	if (!(dest = (char *)malloc(sizeof(char) * len)))
		return (NULL);
	i = 0;
	while (*(s1 + i))
	{
		*(dest + i) = *(s1 + i);
		i++;
	}
	*(dest + i) = '\0';
	return (dest);
}

char		*ft_strjoin(char *s1, char const *s2)
{
	char	*str;
	size_t	i;
	size_t	sz;

	if (!s1 || !s2)
		return (NULL);
	sz = ft_strlen(s1) + ft_strlen(s2) + 1;
	if (!(str = (char *)malloc(sizeof(char) * sz)))
		return (NULL);
	i = 0;
	while (*(s1 + i))
	{
		*(str + i) = *(s1 + i);
		i++;
	}
	free(s1);
	while (*s2)
	{
		*(str + i) = *s2++;
		i++;
	}
	*(str + i) = '\0';
	return (str);
}

char		*ft_strnew(size_t size)
{
	char	*str;
	size_t	i;

	if (!(str = (char *)malloc(sizeof(char) * (size + 1))))
		return (NULL);
	i = 0;
	while (i < size)
	{
		*(str + i) = '\0';
		i++;
	}
	*(str + i) = '\0';
	return (str);
}

char		*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if (*s == (char)c)
		return ((char *)s);
	return (NULL);
}
