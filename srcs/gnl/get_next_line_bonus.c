/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esobchak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 13:35:25 by esobchak          #+#    #+#             */
/*   Updated: 2020/11/25 15:14:13 by esobchak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_strcpy(char *s1, const char *s2)
{
	int i;

	i = 0;
	while (*(s2 + i))
	{
		*(s1 + i) = *(s2 + i);
		i++;
	}
	*(s1 + i) = '\0';
	return (s1);
}

void	ft_strclr(char **s)
{
	if (*s)
	{
		free(*s);
		*s = NULL;
	}
}

char	*check_remainder(char **remainder, char **line)
{
	char	*tmp;

	tmp = NULL;
	if (*remainder)
	{
		if ((tmp = ft_strchr(*remainder, '\n')))
		{
			*tmp++ = '\0';
			*line = ft_strdup(*remainder);
			if (*tmp)
				ft_strcpy(*remainder, tmp);
			else
				ft_strclr(&(*remainder));
		}
		else
		{
			*line = ft_strdup(*remainder);
			ft_strclr(&(*remainder));
		}
	}
	else
		*line = ft_strnew(0);
	return (tmp);
}

int		get_next_line(int fd, char **line)
{
	static char	*remainder[1024];
	char		*buff;
	char		*tmp;
	int			ret;

	if (fd < 0 || !line ||
			!(buff = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1))))
		return (-1);
	tmp = check_remainder(&remainder[fd], line);
	if (!(*line))
		return (-1);
	while (!tmp && (ret = read(fd, buff, BUFFER_SIZE)))
	{
		buff[ret] = '\0';
		if ((tmp = ft_strchr(buff, '\n')))
		{
			*tmp++ = '\0';
			if (*tmp && !(remainder[fd] = ft_strdup(tmp)))
				return (-1);
		}
		if ((ret < 0) || !(*line = ft_strjoin(*line, buff)))
			return (-1);
	}
	free(buff);
	return (tmp ? 1 : 0);
}
