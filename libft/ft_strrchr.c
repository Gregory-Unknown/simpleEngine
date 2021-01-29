/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esobchak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 19:45:10 by esobchak          #+#    #+#             */
/*   Updated: 2020/11/01 18:15:18 by esobchak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*ptr;
	char	*tmp;

	if (c == 0)
		return ((void*)(s + ft_strlen(s)));
	tmp = (char*)s;
	ptr = NULL;
	while (*tmp)
	{
		if (*tmp == (char)c)
			ptr = tmp;
		tmp++;
	}
	if (ptr != NULL)
		return (ptr);
	return (NULL);
}
