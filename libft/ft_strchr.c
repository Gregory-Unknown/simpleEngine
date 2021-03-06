/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esobchak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 19:14:38 by esobchak          #+#    #+#             */
/*   Updated: 2021/03/02 13:23:08 by esobchak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strchr(const char *s, int c)
{
	char *str;

	if (c == 0)
		return (1);
	str = (char*)s;
	while (*(str))
	{
		if (*str == (char)c)
			return (1);
		str++;
	}
	return (0);
}
