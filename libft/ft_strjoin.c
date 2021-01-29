/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esobchak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 15:24:18 by esobchak          #+#    #+#             */
/*   Updated: 2020/11/01 19:28:53 by esobchak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	char	*tmp;
	size_t	sz1;
	size_t	sz2;

	if (!s1 || !s2)
		return (NULL);
	sz1 = ft_strlen(s1);
	sz2 = ft_strlen(s2);
	str = (char *)malloc(sizeof(char) * (sz1 + sz2 + 1));
	if (!str)
		return (NULL);
	tmp = str;
	while (*s1)
		*str++ = *s1++;
	while (*s2)
		*str++ = *s2++;
	*str = '\0';
	return (tmp);
}
