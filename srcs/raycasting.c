/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esobchak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/27 11:47:08 by esobchak          #+#    #+#             */
/*   Updated: 2021/04/01 17:10:09 by esobchak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static void	ft_cam(t_ray *ray, int x)
{
	ray->camerax = 2 * x / (double)ray->pars.r1 - 1;
	ray->raydirx = ray->player.dir.x + ray->player.plane.x * ray->camerax;
	ray->raydiry = ray->player.dir.y + ray->player.plane.y * ray->camerax;
	ray->player.map_pos.x = (int)(ray->player.pos.x);
	ray->player.map_pos.y = (int)(ray->player.pos.y);
	ray->deltadistx = fabs(1 / ray->raydirx);
	ray->deltadisty = fabs(1 / ray->raydiry);
}

static void	ft_step(t_ray *ray)
{
	if (ray->raydirx < 0)
	{
		ray->player.step.x = -1;
		ray->sidedistx = (ray->player.pos.x -
		ray->player.map_pos.x) * ray->deltadistx;
	}
	else
	{
		ray->player.step.x = 1;
		ray->sidedistx = (ray->player.map_pos.x + 1.0 -
		ray->player.pos.x) * ray->deltadistx;
	}
	if (ray->raydiry < 0)
	{
		ray->player.step.y = -1;
		ray->sidedisty = (ray->player.pos.y -
		ray->player.map_pos.y) * ray->deltadisty;
	}
	else
	{
		ray->player.step.y = 1;
		ray->sidedisty = (ray->player.map_pos.y + 1.0 -
		ray->player.pos.y) * ray->deltadisty;
	}
}

static void	ft_side(t_ray *ray)
{
	ray->hit = 0;
	while (ray->hit == 0)
	{
		if (ray->sidedistx < ray->sidedisty)
		{
			ray->sidedistx += ray->deltadistx;
			ray->player.map_pos.x += ray->player.step.x;
			ray->side = 0;
		}
		else
		{
			ray->sidedisty += ray->deltadisty;
			ray->player.map_pos.y += ray->player.step.y;
			ray->side = 1;
		}
		if (ray->pars.map[ray->player.map_pos.x][ray->player.map_pos.y] == '1')
			ray->hit = 1;
	}
}

static void	ft_raycast(t_ray *ray)
{
	int			x;
	int			y;

	x = 0;
	while (x < ray->pars.r1)
	{
		ft_cam(ray, x);
		ft_step(ray);
		ft_side(ray);
		ft_dist(ray);
		ft_route(ray);
		ft_text(ray);
		y = 0;
		while (y < ray->pars.r2)
		{
			ft_draw(ray, x, y);
			y++;
		}
		ray->buffer[x] = ray->perpwalldist;
		x++;
	}
}

int			ft_start(t_ray *ray)
{
	ft_move(ray);
	ft_get_number(ray);
	ray->spr.str = malloc(sizeof(t_d_pos) * ray->number);
	ray->order = (int *)malloc(sizeof(int) * ray->number);
	ray->dist = (double *)malloc(sizeof(double) * ray->number);
	ray->buffer = (double *)malloc(sizeof(double) * ray->pars.r1);
	ft_get_spr(ray);
	ft_raycast(ray);
	ft_sprite(ray);
	free(ray->buffer);
	if (ray->screenshot_flag == 0)
		mlx_put_image_to_window(ray->mlx.mlx, ray->mlx.win, ray->mlx.img.img, 0, 0);
	return (0);
}
