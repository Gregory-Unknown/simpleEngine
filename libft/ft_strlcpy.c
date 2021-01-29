/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esobchak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 20:03:06 by esobchak          #+#    #+#             */
/*   Updated: 2020/11/03 16:53:16 by esobchak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t count;

	if (!dst || !src)
		return (0);
	count = ft_strlen(src);
	if (dstsize == 0)
		return (count);
	while (--dstsize && *src)
		*dst++ = *src++;
	*dst = '\0';
	return (count);
}
