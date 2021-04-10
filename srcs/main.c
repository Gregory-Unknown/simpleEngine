/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esobchak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/29 18:37:08 by esobchak          #+#    #+#             */
/*   Updated: 2021/04/05 16:52:02 by esobchak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void		ft_print_error(char *str)
{
	write(2, str, ft_strlen(str));
	exit(-1);
}

static void	ft_print_error_2(char *str, t_ray *ray)
{
	if (ray->pars.map)
		ft_free_str(ray->pars.map);
	write(2, str, ft_strlen(str));
	exit(-1);
}

static int	ft_check_file(char *str)
{
	int i;
	int fd;

	fd = open(str, O_DIRECTORY);
	if (fd != -1)
		return (1);
	close(fd);
	i = ft_strlen(str) - 4;
	if (ft_strncmp(&str[i], ".cub", ft_strlen(&str[i])) == 0)
		return (0);
	return (1);
}

static int	ft_check_save(char *str)
{
	int len;

	len = (ft_strlen(str) > 6 ? ft_strlen(str) : 6);
	if (ft_strncmp(str, "--save", len))
		return (0);
	return (1);
}

int			main(int argc, char **argv)
{
	int		fd;
	t_ray	ray;

	if (argc > 3 || argc < 2)
		ft_print_error("ERROR: invalid number of arguments!\n");
	if (ft_check_file(argv[1]))
		ft_print_error("ERROR: not found .cub file\n");
	if (argc == 3 && !ft_check_save(argv[2]))
		ft_print_error("ERROR: invalid arguments!\n");
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		ft_print_error("ERROR: the file cannot be opened!\n");
	if (ft_parser(fd, &ray.pars) == -1)
		ft_print_error_2("ERROR: map error!\n", &ray);
	close(fd);
	if (argc == 2)
		ft_init_game(&ray);
	else
		ft_do_screenshot(&ray);
	return (0);
}
