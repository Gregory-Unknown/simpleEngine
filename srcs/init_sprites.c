/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_sprites.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esobchak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/27 12:23:59 by esobchak          #+#    #+#             */
/*   Updated: 2021/03/24 17:26:21 by esobchak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	ft_get_number(t_ray *ray)
{
	int	x;
	int	y;

	x = 0;
	ray->number = 0;
	while (x < ray->maplen)
	{
		y = 0;
		while (y < (int)ft_strlen(ray->pars.map[x]))
		{
			if (ray->pars.map[x][y] == '2')
				ray->number++;
			y++;
		}
		x++;
	}
}

void	ft_get_spr(t_ray *ray)
{
	int	x;
	int	y;
	int	i;

	x = 0;
	i = 0;
	while (x < ray->maplen)
	{
		y = 0;
		while (y < (int)ft_strlen(ray->pars.map[x]))
		{
			if (ray->pars.map[x][y] == '2')
			{
				ray->spr.str[i].x = x + 0.5;
				ray->spr.str[i].y = y + 0.5;
				i++;
			}
			y++;
		}
		x++;
	}
}

void	ft_init_spr(t_ray *ray)
{
	int	i;

	i = 0;
	while (i < ray->number)
	{
		ray->order[i] = i;
		ray->dist[i] = ((ray->player.pos.x - ray->spr.str[i].x)
		* (ray->player.pos.x - ray->spr.str[i].x)
		+ (ray->player.pos.y - ray->spr.str[i].y)
		* (ray->player.pos.y - ray->spr.str[i].y));
		i++;
	}
}
