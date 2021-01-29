/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esobchak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 18:08:36 by esobchak          #+#    #+#             */
/*   Updated: 2020/11/02 13:15:53 by esobchak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	size_t	count;

	if (!s1)
		return (NULL);
	while (*s1 && ft_strchr(set, *s1))
		s1++;
	count = ft_strlen(s1);
	while (count && ft_strchr(set, s1[count - 1]))
		count--;
	str = (char *)malloc(sizeof(char) * (count + 1));
	if (!str)
		return (NULL);
	ft_memcpy(str, s1, count);
	str[count] = '\0';
	return (str);
}
