/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esobchak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 11:15:30 by esobchak          #+#    #+#             */
/*   Updated: 2021/03/26 15:36:59 by esobchak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static void	ft_player_pos(char **map, t_ray *ray)
{
	int x;
	int y;

	x = 0;
	while (x < ray->maplen)
	{
		y = 0;
		while (y < (int)ft_strlen(map[x]))
		{
			if (ft_strchr("NEWS", map[x][y]))
			{
				ray->player.start_view = map[x][y];
				ray->player.map_pos.x = x;
				ray->player.map_pos.y = y;
				map[x][y] = '0';
			}
			y++;
		}
		x++;
	}
}

static void		ft_init_NW(t_ray *ray)
{
	if (ray->player.start_view == 'W')
	{
		ray->player.dir.x = 0;
		ray->player.dir.y = -1;
		ray->player.plane.x = -0.66;
		ray->player.plane.y = 0;
	}
	else
	{
		ray->player.dir.x = -1;
		ray->player.dir.y = 0;
		ray->player.plane.x = 0;
		ray->player.plane.y = 0.66;
	}
}

static void		ft_init_ES(t_ray *ray)
{
	if (ray->player.start_view == 'S')
	{
		ray->player.dir.x = 1;
		ray->player.dir.y = 0;
		ray->player.plane.x = 0;
		ray->player.plane.y = -0.66;
	}
	else
	{
		ray->player.dir.x = 0;
		ray->player.dir.y = 1;
		ray->player.plane.x = 0.66;
		ray->player.plane.y = 0;
	}
}

void			ft_init_player(t_ray *ray)
{
	ft_player_pos(ray->pars.map, ray);
	ray->player.pos.x = (double)ray->player.map_pos.x + 0.5;
	ray->player.pos.y = (double)ray->player.map_pos.y + 0.5;
	if (ft_strchr("NW", ray->player.start_view))
		ft_init_NW(ray);
	else
		ft_init_ES(ray);

}
