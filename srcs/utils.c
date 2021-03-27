/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esobchak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/27 13:57:24 by esobchak          #+#    #+#             */
/*   Updated: 2021/03/24 17:33:31 by esobchak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int		is_xpm(char *path)
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

void	pixel_put(t_ray *ray, int x, int y, int color)
{
	char	*dst;

	dst = ray->mlx.img.addr + (y * ray->mlx.img.line_length + x *
	(ray->mlx.img.bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void	pixel_put2(t_ray *ray, int x, int y, int color)
{
	char	*dst;

	dst = ray->mlx.img.addr + (y * ray->sprite.img.line_length + x *
	(ray->sprite.img.bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void	sort_double_vectors(int *order, double *distance, int len)
{
	int		i;
	int		j;
	double	temp;

	i = 0;
	while (i < len - 1)
	{
		j = i + 1;
		while (j < len)
		{
			if (distance[i] < distance[j])
			{
				temp = distance[i];
				distance[i] = distance[j];
				distance[j] = temp;
				temp = (double)order[i];
				order[i] = order[j];
				order[j] = (int)temp;
			}
			j++;
		}
		i++;
	}
}

