/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_resolution.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esobchak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/22 22:35:04 by esobchak          #+#    #+#             */
/*   Updated: 2021/04/08 11:56:56 by esobchak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int		ft_check_resolution(char *s)
{
	int i;

	i = 0;
	if (!s)
		return (1);
	while (s[i])
	{
		if (ft_isdigit(s[i]) == 0)
			return (1);
		i++;
	}
	return (0);
}

int		ft_screen_resolution(char **s, t_pars *pars)
{
	if (ft_check_resolution(s[1]) || ft_check_resolution(s[2])
	|| pars->r1 != -1 || pars->r2 != -1 || s[3])
		return (-1);
	pars->r1 = ft_atoi(s[1]);
	pars->r2 = ft_atoi(s[2]);
	if (pars->r1 > 1920 || (ft_strlen(s[1]) > 4))
		pars->r1 = 1920;
	if (pars->r2 > 1080 || (ft_strlen(s[2]) > 4))
		pars->r2 = 1080;
	if (pars->r1 < 720)
		pars->r1 = 720;
	if (pars->r2 < 480)
		pars->r2 = 480;
	return (0);
}
