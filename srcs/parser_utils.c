/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esobchak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/22 23:06:19 by esobchak          #+#    #+#             */
/*   Updated: 2021/04/03 11:36:18 by esobchak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int		ft_check_line(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] != ' ')
			return (1);
		i++;
	}
	return (0);
}

void	ft_free_str(char **str)
{
	int i;

	i = 0;
	while (str[i])
		free(str[i++]);
	free(str);
}

int		ft_maplen(char **map)
{
	int		len;

	len = 0;
	if (!map)
		return (0);
	while (map[len])
		len++;
	return (len);
}

t_col	ft_init_rgb(int r, int g, int b)
{
	t_col	rgb;

	rgb.r = r;
	rgb.g = g;
	rgb.b = b;
	rgb.color = ((r * 256 * 256) + (g * 256) + b);
	return (rgb);
}

void	ft_init_pars(t_pars *pars)
{
	pars->r1 = -1;
	pars->r2 = -1;
	pars->no = 0;
	pars->so = 0;
	pars->we = 0;
	pars->ea = 0;
	pars->s = 0;
	pars->f_col = ft_init_rgb(-1, -1, -1);
	pars->c_col = ft_init_rgb(-1, -1, -1);
	pars->map = 0;
}
