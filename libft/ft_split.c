/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esobchak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 19:25:34 by esobchak          #+#    #+#             */
/*   Updated: 2020/11/07 13:11:14 by esobchak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_word_count(char const *s, char c)
{
	size_t count;
	size_t flag;

	count = 0;
	flag = 0;
	while (*s)
	{
		if (flag == 0 && *s != c && *s)
		{
			flag = 1;
			count++;
		}
		if (*s == c && flag == 1)
			flag = 0;
		s++;
	}
	return (count);
}

static size_t	ft_len(char const *s, char c)
{
	size_t len;

	len = 0;
	while (*s && *s != c)
	{
		len++;
		s++;
	}
	return (len);
}

static void		*ft_free(char **str, size_t i)
{
	while (i--)
		free(str[i]);
	free(str);
	return (NULL);
}

char			**ft_split(char const *s, char c)
{
	char	**str;
	size_t	i;
	size_t	j;

	if (!s)
		return (NULL);
	i = 0;
	if (!(str = (char **)malloc(sizeof(char*) * (ft_word_count(s, c) + 1))))
		return (NULL);
	while (*s)
	{
		if (*s == c)
			s++;
		else
		{
			if (!(str[i] = (char *)malloc(sizeof(char) * (ft_len(s, c) + 1))))
				return (ft_free(str, i));
			j = 0;
			while (*s && *s != c)
				str[i][j++] = *s++;
			str[i++][j] = '\0';
		}
	}
	str[i] = NULL;
	return (str);
}
