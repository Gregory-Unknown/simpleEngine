/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esobchak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/22 23:13:09 by esobchak          #+#    #+#             */
/*   Updated: 2021/04/01 17:10:10 by esobchak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	ft_init(t_ray *ray)
{
	ray->screenshot_flag = 0;
	ray->maplen = ft_maplen(ray->pars.map);
	ray->player.pos.x = 0;
	ray->player.pos.y = 0;
	ray->player.map_pos.x = 0;
	ray->player.map_pos.y = 0;
	ray->player.dir.x = 0;
	ray->player.dir.y = 0;
	ray->player.plane.x = 0;
	ray->player.plane.y = 0;
	ray->w = 0;
	ray->s = 0;
	ray->a = 0;
	ray->d = 0;
	ray->left = 0;
	ray->right = 0;
	ray->no.path = ray->pars.no;
	ray->so.path = ray->pars.so;
	ray->we.path = ray->pars.we;
	ray->ea.path = ray->pars.ea;
	ray->str = ray->pars.s;
}

void	ft_init_texture(t_text *texture, t_ray *ray)
{
	texture->img.img = mlx_xpm_file_to_image(ray->mlx.mlx,
	texture->path, &texture->width, &texture->height);
	texture->img.addr = mlx_get_data_addr(texture->img.img,
	&texture->img.bits_per_pixel,
	&texture->img.line_length,
	&texture->img.endian);
}

void	ft_init_texture_sprite(t_ray *ray)
{
	ray->sprite.img.img = mlx_xpm_file_to_image(ray->mlx.mlx,
	ray->str, &ray->spr.width, &ray->spr.height);
	ray->sprite.img.addr = mlx_get_data_addr(ray->sprite.img.img,
	&ray->sprite.img.bits_per_pixel,
	&ray->sprite.img.line_length,
	&ray->sprite.img.endian);
}

int		ft_init_game(t_ray *ray)
{
	ft_init(ray);
	ft_init_player(ray);
	ray->mlx.mlx = mlx_init();
	ray->mlx.win = mlx_new_window(ray->mlx.mlx,
	ray->pars.r1, ray->pars.r2, "cub3D");
	ft_init_texture(&ray->no, ray);
	ft_init_texture(&ray->so, ray);
	ft_init_texture(&ray->we, ray);
	ft_init_texture(&ray->ea, ray);
	ft_init_texture_sprite(ray);
	ray->mlx.img.img = mlx_new_image(ray->mlx.mlx, ray->pars.r1, ray->pars.r2);
	ray->mlx.img.addr = mlx_get_data_addr(ray->mlx.img.img,
	&ray->mlx.img.bits_per_pixel,
	&ray->mlx.img.line_length, &ray->mlx.img.endian);
	mlx_hook(ray->mlx.win, 2, 1L << 0, ft_press_key, ray);
	mlx_hook(ray->mlx.win, 3, 1L << 1, ft_unpress_key, ray);
	mlx_hook(ray->mlx.win, 33, 1L << 0, ft_exit, ray);
	mlx_loop_hook(ray->mlx.mlx, ft_start, ray);
	mlx_loop(ray->mlx.mlx);
	return (0);
}
