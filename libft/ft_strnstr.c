/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esobchak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 11:31:19 by esobchak          #+#    #+#             */
/*   Updated: 2020/11/07 22:51:59 by esobchak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t n;
	size_t i;

	n = ft_strlen(needle);
	if (n == 0)
		return ((char *)haystack);
	i = 0;
	while (*haystack && i + n <= len)
	{
		if (ft_strncmp(haystack, needle, n) == 0)
			return ((char*)haystack);
		haystack++;
		i++;
	}
	return (NULL);
}
