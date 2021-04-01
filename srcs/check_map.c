/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esobchak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/22 23:10:28 by esobchak          #+#    #+#             */
/*   Updated: 2021/04/01 16:33:35 by esobchak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static int	ft_check_field(char c)
{
	if (c == ' ' || c == '1')
		return (0);
	return (1);
}

static int	ft_check_margin(int i, int j, char **s)
{
	if (i == 0 || i == ft_maplen(s) - 1)
		return (1);
	if (j == 0 || j == (int)ft_strlen(s[i]) - 1)
		return (1);
	if (s[i][j - 1] == ' ' || s[i][j + 1] == ' ')
		return (1);
	if (s[i - 1][j] == ' ' || s[i + 1][j] == ' ')
		return (1);
	if (s[i - 1][j - 1] == ' ' || s[i + 1][j - 1] == ' ')
		return (1);
	if (j >= ((int)ft_strlen(s[i - 1]) - 1) ||
	j >= ((int)ft_strlen(s[i + 1]) - 1))
		return (1);
	return (0);
}

static int	ft_check_player(char c, int *flag)
{
	if (ft_strchr("NSWE", c))
	{
		if (*flag == 1)
			return (1);
		*flag = 1;
	}
	return (0);
}

int			ft_check_map(char **s)
{
	int	i;
	int	j;
	int	flag;

	i = 0;
	flag = 0;
	while (i < ft_maplen(s))
	{
		j = 0;
		while (j < (int)ft_strlen(s[i]))
		{
			if (ft_check_field(s[i][j]) && ft_check_margin(i, j, s))
				return (-1);
			if (ft_check_player(s[i][j], &flag))
				return (-1);
			j++;
		}
		i++;
	}
	if (flag == 0)
		return (-1);
	return (0);
}
