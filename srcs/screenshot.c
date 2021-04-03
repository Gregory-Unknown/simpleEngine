/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screenshot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esobchak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/22 23:13:45 by esobchak          #+#    #+#             */
/*   Updated: 2021/04/03 14:36:52 by esobchak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static void	ft_init_screenshots(t_ray *ray)
{
	ft_init(ray);
	ft_init_player(ray);
	ray->screenshot_flag = 1;
	ray->mlx.mlx = mlx_init();
	ft_init_texture(&ray->no, ray);
	ft_init_texture(&ray->so, ray);
	ft_init_texture(&ray->we, ray);
	ft_init_texture(&ray->ea, ray);
	ft_init_texture_sprite(ray);
	ray->mlx.img.img = mlx_new_image(ray->mlx.mlx, ray->pars.r1, ray->pars.r2);
	ray->mlx.img.addr = mlx_get_data_addr(ray->mlx.img.img,
	&ray->mlx.img.bits_per_pixel,
	&ray->mlx.img.line_length, &ray->mlx.img.endian);
}

static void	*ft_init_bitmap(t_ray *ray)
{
	static char		bitmap[54];

	ft_bzero(bitmap, 54);
	bitmap[0] = 'B';
	bitmap[1] = 'M';
	*((int*)(bitmap + 2)) = ray->pars.r1 * ray->pars.r2 * 4 + 54;
	*(int*)(bitmap + 10) = 54;
	*(int*)(bitmap + 14) = 40;
	*(int*)(bitmap + 18) = (int)ray->pars.r1;
	*(int*)(bitmap + 22) = (int)ray->pars.r2;
	*(bitmap + 26) = 1;
	*(bitmap + 28) = 32;
	return ((void*)bitmap);
}

static void	ft_write_img(int fd, t_ray *ray)
{
	int32_t		x;
	int32_t		y;
	int			col;

	y = ray->pars.r2 - 1;
	while (y >= 0)
	{
		x = 0;
		while (x < ray->pars.r1)
		{
			col = *(int*)(ray->mlx.img.addr + (y * ray->mlx.img.line_length +
								x * (ray->mlx.img.bits_per_pixel / 8)));
			write(fd, &col, 4);
			x++;
		}
		y--;
	}
}

void		ft_do_screenshot(t_ray *ray)
{
	int		fd;
	void	*bitmap;

	fd = open("cub3D.bmp", O_CREAT | O_WRONLY | O_TRUNC, S_IRWXU);
	if (fd < 0)
		ft_print_error("ERROR: file couldn't be create !\n");
	ft_init_screenshots(ray);
	ft_start(ray);
	bitmap = ft_init_bitmap(ray);
	write(fd, bitmap, 54);
	ft_write_img(fd, ray);
	close(fd);
	ft_exit(ray);
}
