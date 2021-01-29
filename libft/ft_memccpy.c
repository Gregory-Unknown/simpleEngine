/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esobchak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 13:54:49 by esobchak          #+#    #+#             */
/*   Updated: 2020/11/02 12:51:29 by esobchak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char		*tmp;
	unsigned const char *tmp2;

	tmp = dst;
	tmp2 = src;
	while (n--)
	{
		if (*tmp2 == (unsigned char)c)
		{
			*tmp = (unsigned char)c;
			return (tmp + 1);
		}
		*(tmp++) = *(tmp2++);
	}
	return (NULL);
}
