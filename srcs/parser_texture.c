/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_texture.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esobchak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/22 22:53:03 by esobchak          #+#    #+#             */
/*   Updated: 2021/04/03 14:36:08 by esobchak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static int	ft_check_path(char *s)
{
	int	fd;
	int tmp;

	fd = open(s, O_DIRECTORY);
	tmp = fd;
	if (tmp != -1)
		return (1);
	fd = open(s, O_RDONLY);
	tmp = fd;
	close(fd);
	if (tmp < 0)
		return (1);
	return (0);
}

int			ft_set_texture(char *str, char **path)
{
	if (*path || ft_check_path(str))
		return (-1);
	*path = ft_strdup(str);
	return (0);
}
