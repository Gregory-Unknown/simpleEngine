/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esobchak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/29 18:37:08 by esobchak          #+#    #+#             */
/*   Updated: 2021/04/01 16:30:51 by esobchak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void		ft_print_error(char *str)
{
	write(2, str, ft_strlen(str));
	exit(-1);
}

static int	ft_check_file(char *str)
{
	int i;

	i = 0;
	while (str[i] && str[i] != '.')
		i++;
	if (ft_strncmp(&str[i], ".cub", ft_strlen(&str[i])) == 0)
		return (1);
	return (0);
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
	if (!ft_check_file(argv[1]))
		ft_print_error("ERROR: not found .cub file\n");
	if (argc == 3 && !ft_check_save(argv[2]))
		ft_print_error("ERROR: invalid arguments!\n");
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		ft_print_error("ERROR: the file cannot be opened!\n");
	if (ft_parser(fd, &ray.pars) == -1)
		ft_print_error("ERROR: map error!\n");
	if (argc == 2)
		ft_init_game(&ray);
	else
		ft_do_screenshot(&ray);
	return (0);
}
