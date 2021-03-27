/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esobchak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 16:42:23 by esobchak          #+#    #+#             */
/*   Updated: 2021/03/26 14:23:14 by esobchak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int		ft_press_key(int key, t_ray *ray)
{
	if (key == W)
		ray->w = 1;
	if (key == S)
		ray->s = 1;
	if (key == A)
		ray->a = 1;
	if (key == D)
		ray->d = 1;
	if (key == LEFT)
		ray->left = 1;
	if (key == RIGHT)
		ray->right = 1;
	if (key == ESC)
	{
		mlx_destroy_window(ray->mlx.mlx, ray->mlx.win);
		exit(1);
	}
	return (0);
}

int		ft_unpress_key(int key, t_ray *ray)
{
	if (key == W)
		ray->w = 0;
	if (key == S)
		ray->s = 0;
	if (key == A)
		ray->a = 0;
	if (key == D)
		ray->d = 0;
	if (key == LEFT)
		ray->left = 0;
	if (key == RIGHT)
		ray->right = 0;
	return (0);
}

int		ft_exit(t_ray *ray)
{
	mlx_destroy_window(ray->mlx.mlx, ray->mlx.win);
	exit(1);
	return (0);
}