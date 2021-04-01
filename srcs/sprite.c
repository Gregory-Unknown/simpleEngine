/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esobchak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/27 12:36:03 by esobchak          #+#    #+#             */
/*   Updated: 2021/03/29 16:44:31 by esobchak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	ft_sort(t_ray *ray)
{
	int		i;
	int		j;
	double	temp;

	i = 0;
	while (i < ray->number - 1)
	{
		j = i + 1;
		while (j < ray->number)
		{
			if (ray->dist[i] < ray->dist[j])
			{
				temp = ray->dist[i];
				ray->dist[i] = ray->dist[j];
				ray->dist[j] = temp;
				temp = (double)ray->order[i];
				ray->order[i] = ray->order[j];
				ray->order[j] = (int)temp;
			}
			j++;
		}
		i++;
	}
}

void	ft_get_data(t_ray *ray, int x)
{
	ray->spr.spr.x = ray->spr.str[ray->order[x]].x - ray->player.pos.x;
	ray->spr.spr.y = ray->spr.str[ray->order[x]].y - ray->player.pos.y;
	ray->spr.invdet = 1.0 / (ray->player.plane.x * ray->player.dir.y -
	ray->player.plane.y * ray->player.dir.x);
	ray->spr.transform.x = ray->spr.invdet * (ray->player.dir.y *
	ray->spr.spr.x - ray->player.dir.x * ray->spr.spr.y);
	ray->spr.transform.y = ray->spr.invdet * (-ray->player.plane.y
	* ray->spr.spr.x + ray->player.plane.x * ray->spr.spr.y);
	ray->spr.sscreen = (int)((ray->pars.r1 / 2) *
	(1 + ray->spr.transform.x / ray->spr.transform.y));
}

void	ft_calc_render(t_ray *ray)
{
	ray->spr.height = abs((int)(ray->pars.r2 / (ray->spr.transform.y)));
	ray->spr.drawstart.y = -ray->spr.height / 2 + ray->pars.r2 / 2;
	if (ray->spr.drawstart.y < 0)
		ray->spr.drawstart.y = 0;
	ray->spr.drawend.y = ray->spr.height / 2 + ray->pars.r2 / 2;
	if (ray->spr.drawend.y >= ray->pars.r2)
		ray->spr.drawend.y = ray->pars.r2 - 1;
	ray->spr.width = abs((int)(ray->pars.r2 / ray->spr.transform.y));
	ray->spr.drawstart.x = -ray->spr.width / 2 + ray->spr.sscreen;
	if (ray->spr.drawstart.x < 0)
		ray->spr.drawstart.x = 0;
	ray->spr.drawend.x = ray->spr.width / 2 + ray->spr.sscreen;
	if (ray->spr.drawend.x >= ray->pars.r1)
		ray->spr.drawend.x = ray->pars.r1 - 1;
}

void	ft_check(t_ray *ray)
{
	if (ray->spr.transform.y > 0 && ray->spr.stripe > 0
	&& ray->spr.stripe < ray->pars.r1 &&
	ray->spr.transform.y < ray->buffer[ray->spr.stripe])
	{
		ray->spr.tmpsy = ray->spr.drawstart.y;
		while (ray->spr.tmpsy < ray->spr.drawend.y)
		{
			ray->spr.tmpsd = (ray->spr.tmpsy) * 256 - ray->pars.r2 * 128 +
			ray->spr.height * 128;
			ray->spr.stext.y = ((ray->spr.tmpsd * TH) / ray->spr.height) / 256;
			ray->spr.scol =
			ft_get_pixel(ray, ray->spr.stext.x, ray->spr.stext.y);
			if (ray->spr.scol > 0)
				pixel_put(ray, ray->spr.stripe, ray->spr.tmpsy, ray->spr.scol);
			ray->spr.tmpsy++;
		}
	}
}

void	ft_sprite(t_ray *ray)
{
	int x;

	x = 0;
	ft_init_spr(ray);
	ft_sort(ray);
	while (x < ray->number)
	{
		ft_get_data(ray, x);
		ft_calc_render(ray);
		ray->spr.stripe = ray->spr.drawstart.x;
		while (ray->spr.stripe < ray->spr.drawend.x)
		{
			ray->spr.stext.x = (int)(256 * (ray->spr.stripe - (-ray->spr.width /
			2 + ray->spr.sscreen)) * TW / ray->spr.width) / 256;
			ft_check(ray);
			ray->spr.stripe++;
		}
		x++;
	}
	free(ray->spr.str);
	free(ray->order);
	free(ray->dist);
}
