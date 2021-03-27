/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esobchak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/27 13:10:37 by esobchak          #+#    #+#             */
/*   Updated: 2021/03/26 16:03:53 by esobchak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	ft_dist(t_ray *ray)
{
	if (ray->side == 0)
		ray->perpwalldist = (ray->player.map_pos.x - ray->player.pos.x +
		(1 - ray->player.step.x) / 2) / ray->raydirx;
	else
		ray->perpwalldist = (ray->player.map_pos.y - ray->player.pos.y +
		(1 - ray->player.step.y) / 2) / ray->raydiry;
	ray->lineheight = (int)(SH / ray->perpwalldist);
	ray->drawstart = -ray->lineheight / 2 + SH / 2;
	if (ray->drawstart < 0)
		ray->drawstart = 0;
	ray->drawend = ray->lineheight / 2 + SH / 2;
	if (ray->drawend >= SH)
		ray->drawend = SH - 1;
}

void	ft_route(t_ray *ray)
{
	if (ray->side == 1)
	{
		if (ray->player.step.y > 0)
			ray->textur = ray->no;
		if (ray->player.step.y < 0)
			ray->textur = ray->so;
	}
	if (ray->side == 0)
	{
		if (ray->player.step.x > 0)
			ray->textur = ray->we;
		if (ray->player.step.x < 0)
			ray->textur = ray->ea;
	}
}

void	ft_text(t_ray *ray)
{
	if (ray->side == 0)
		ray->wallx = ray->player.pos.y +
		ray->perpwalldist * ray->raydiry;
	else
		ray->wallx = ray->player.pos.x +
		ray->perpwalldist * ray->raydirx;
	ray->wallx -= floor(ray->wallx * 1.0);
	ray->textur.pos.x = (int)(ray->wallx * (double)TW);
	if (ray->side == 0 && ray->raydirx > 0)
		ray->textur.pos.x = TW - ray->textur.pos.x - 1;
	if (ray->side == 1 && ray->raydiry < 0)
		ray->textur.pos.x = TW - ray->textur.pos.x - 1;
	ray->textur.step = 1.0 * TH / ray->lineheight;
	ray->textur.start_pos = (ray->drawstart - SH / 2 +
	ray->lineheight / 2) * ray->textur.step;
}

void	ft_draw(t_ray *ray, int x, int y)
{
	if (y < ray->drawstart)
	{
		pixel_put(ray, x, y, ray->pars.f_col.color);
	}
	if (y >= ray->drawstart && y <= ray->drawend)
	{
		ray->textur.pos.y = (int)ray->textur.start_pos & (64 - 1);
		ray->textur.start_pos += ray->textur.step;
		ray->textur.color = ((int *)ray->textur.img.addr)
		[64 * ray->textur.pos.y + ray->textur.pos.x];
		pixel_put(ray, x, y, ray->textur.color);
	}
	if (y > ray->drawend)
	{
		pixel_put(ray, x, y, ray->pars.c_col.color);
	}
}
