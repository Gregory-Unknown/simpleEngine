/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_color.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esobchak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/22 23:07:58 by esobchak          #+#    #+#             */
/*   Updated: 2021/02/22 23:15:50 by esobchak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static int	ft_check_color(char *str)
{
	int rgb;

	rgb = ft_atoi(str);
	if (ft_check_resolution(str) || rgb < 0 || rgb > 255)
		return (-1);
	return (0);
}

int			ft_set_color(char *str, t_col *col)
{
	char **s;

	s = ft_split(str, ',');
	if (ft_check_color(s[0]) || ft_check_color(s[1]) || ft_check_color(s[2]))
		return (-1);
	*col = ft_init_rgb(ft_atoi(s[0]), ft_atoi(s[1]), ft_atoi(s[2]));
	ft_free_str(s);
	return (0);
}
