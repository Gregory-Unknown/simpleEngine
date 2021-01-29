/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esobchak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 14:21:02 by esobchak          #+#    #+#             */
/*   Updated: 2020/11/01 18:14:28 by esobchak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char		*tmp;
	unsigned const char	*tmp2;
	size_t				num;

	if (!dst && !src)
		return (NULL);
	tmp = dst;
	tmp2 = src;
	num = 0;
	if (tmp < tmp2)
	{
		while (num++ < len)
			*tmp++ = *tmp2++;
	}
	else
	{
		tmp += (len - 1);
		tmp2 += (len - 1);
		while (num++ < len)
			*tmp-- = *tmp2--;
	}
	return (dst);
}
