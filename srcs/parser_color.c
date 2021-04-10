/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_color.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esobchak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/22 23:07:58 by esobchak          #+#    #+#             */
/*   Updated: 2021/04/06 01:17:43 by esobchak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static int	ft_check_str(char *str)
{
	char	**s;
	int		count;
	int		i;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] == ',')
			count++;
		i++;
	}
	if (count != 2)
		return (1);
	s = ft_split(str, ' ');
	count = ft_maplen(s);
	if (count != 2)
	{
		ft_free_str(s);
		return (1);
	}
	ft_free_str(s);
	return (0);
}

static int	ft_check_color(char *str)
{
	int rgb;

	if (!str)
		return (1);
	rgb = ft_atoi(str);
	if (ft_check_resolution(str) || rgb < 0 || rgb > 255)
		return (1);
	return (0);
}

int			ft_set_color(char *str, t_col *col, char *line)
{
	char	**s;
	int		count;

	if (ft_check_str(line))
		return (-1);
	s = ft_split(str, ',');
	count = ft_maplen(s);
	if (ft_check_color(s[0]) || ft_check_color(s[1]) ||
	ft_check_color(s[2]) || count != 3)
	{
		ft_free_str(s);
		return (-1);
	}
	*col = ft_init_rgb(ft_atoi(s[0]), ft_atoi(s[1]), ft_atoi(s[2]));
	ft_free_str(s);
	return (0);
}
