/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esobchak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 13:17:05 by esobchak          #+#    #+#             */
/*   Updated: 2020/11/01 19:15:18 by esobchak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char		*tmp;
	unsigned const char *tmp2;

	if (!dst && !src)
		return (NULL);
	tmp = dst;
	tmp2 = src;
	while (n--)
	{
		*(tmp++) = *(tmp2++);
	}
	return (dst);
}
