/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esobchak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 19:14:38 by esobchak          #+#    #+#             */
/*   Updated: 2020/10/30 21:42:14 by esobchak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char *str;

	if (c == 0)
		return ((void*)(s + ft_strlen(s)));
	str = (char*)s;
	while (*(str))
	{
		if (*str == (char)c)
			return (str);
		str++;
	}
	return (NULL);
}
