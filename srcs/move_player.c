/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esobchak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/27 14:40:02 by esobchak          #+#    #+#             */
/*   Updated: 2021/03/29 16:35:16 by esobchak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static void	ft_forward(t_ray *ray)
{
	if (ray->w == 1)
	{
		if (ray->pars.map[(int)(ray->player.pos.x + ray->player.dir.x
		* MV_SPEED)][(int)(ray->player.pos.y)] == '0')
			ray->player.pos.x += ray->player.dir.x * MV_SPEED;
		if (ray->pars.map[(int)(ray->player.pos.x)]
		[(int)(ray->player.pos.y + ray->player.dir.y * MV_SPEED)] == '0')
			ray->player.pos.y += ray->player.dir.y * MV_SPEED;
	}
	if (ray->s == 1)
	{
		if (ray->pars.map[(int)(ray->player.pos.x - ray->player.dir.x
		* MV_SPEED)][(int)(ray->player.pos.y)] == '0')
			ray->player.pos.x -= ray->player.dir.x * MV_SPEED;
		if (ray->pars.map[(int)(ray->player.pos.x)]
		[(int)(ray->player.pos.y - ray->player.dir.y * MV_SPEED)] == '0')
			ray->player.pos.y -= ray->player.dir.y * MV_SPEED;
	}
}

static void	ft_left(t_ray *ray)
{
	if (ray->a == 1)
	{
		if (ray->pars.map[(int)(ray->player.pos.x)]
		[(int)(ray->player.pos.y + ray->player.dir.x * MV_SPEED)] == '0')
			ray->player.pos.y += ray->player.dir.x * MV_SPEED;
		if (ray->pars.map[(int)(ray->player.pos.x - ray->player.dir.y
		* MV_SPEED)][(int)(ray->player.pos.y)] == '0')
			ray->player.pos.x -= ray->player.dir.y * MV_SPEED;
	}
	if (ray->d == 1)
	{
		if (ray->pars.map[(int)(ray->player.pos.x)]
		[(int)(ray->player.pos.y - ray->player.dir.x * MV_SPEED)] == '0')
			ray->player.pos.y -= ray->player.dir.x * MV_SPEED;
		if (ray->pars.map[(int)(ray->player.pos.x + ray->player.dir.y
		* MV_SPEED)][(int)(ray->player.pos.y)] == '0')
			ray->player.pos.x += ray->player.dir.y * MV_SPEED;
	}
}

static void	ft_turn_left(t_ray *ray)
{
	ray->olddirx = ray->player.dir.x;
	ray->player.dir.x = ray->player.dir.x * cos(-ROT_SPEED) -
	ray->player.dir.y * sin(-ROT_SPEED);
	ray->player.dir.y = ray->olddirx * sin(-ROT_SPEED) +
	ray->player.dir.y * cos(-ROT_SPEED);
	ray->oldplanex = ray->player.plane.x;
	ray->player.plane.x = ray->player.plane.x * cos(-ROT_SPEED) -
	ray->player.plane.y * sin(-ROT_SPEED);
	ray->player.plane.y = ray->oldplanex * sin(-ROT_SPEED) +
	ray->player.plane.y * cos(-ROT_SPEED);
}

static void	ft_turn_right(t_ray *ray)
{
	ray->olddirx = ray->player.dir.x;
	ray->player.dir.x = ray->player.dir.x * cos(ROT_SPEED) -
	ray->player.dir.y * sin(ROT_SPEED);
	ray->player.dir.y = ray->olddirx * sin(ROT_SPEED) +
	ray->player.dir.y * cos(ROT_SPEED);
	ray->oldplanex = ray->player.plane.x;
	ray->player.plane.x = ray->player.plane.x * cos(ROT_SPEED) -
	ray->player.plane.y * sin(ROT_SPEED);
	ray->player.plane.y = ray->oldplanex * sin(ROT_SPEED) +
	ray->player.plane.y * cos(ROT_SPEED);
}

void		ft_move(t_ray *ray)
{
	if (ray->w == 1 || ray->s == 1)
		ft_forward(ray);
	if (ray->a == 1 || ray->d == 1)
		ft_left(ray);
	if (ray->left == 1)
		ft_turn_left(ray);
	if (ray->right == 1)
		ft_turn_right(ray);
}
