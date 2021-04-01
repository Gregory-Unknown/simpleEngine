/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esobchak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/27 13:57:24 by esobchak          #+#    #+#             */
/*   Updated: 2021/03/29 16:12:20 by esobchak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int				is_xpm(char *path)
{
	int i;

	i = 0;
	while (i < (int)ft_strlen(path))
	{
		if (ft_strncmp(&path[i], ".xpm", ft_strlen(&path[i])) == 0)
			return (0);
		i++;
	}
	return (-1);
}

void			pixel_put(t_ray *ray, int x, int y, int color)
{
	char	*dst;

	dst = ray->mlx.img.addr + (y * ray->mlx.img.line_length + x *
	(ray->mlx.img.bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void			pixel_put2(t_ray *ray, int x, int y, int color)
{
	char	*dst;

	dst = ray->mlx.img.addr + (y * ray->sprite.img.line_length + x *
	(ray->sprite.img.bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

unsigned int	ft_get_pixel(t_ray *ray, int x, int y)
{
	unsigned int	color;
	char			*dest;

	dest = ray->sprite.img.addr +
	(y * ray->sprite.img.line_length +
	x * (ray->sprite.img.bits_per_pixel / 8));
	color = *(unsigned int*)dest;
	return (color);
}
