/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esobchak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 15:45:48 by esobchak          #+#    #+#             */
/*   Updated: 2021/01/31 20:49:42 by esobchak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

#define BUFFER_SIZE 1000

int		get_next_line(int fd, char **line);
int		ft_strlen1(const char *s1);
char	*ft_strdup1(const char *s1);
char	*ft_strjoin1(char *s1, const char *s2);
char	*ft_strnew1(size_t size);
char	*ft_strchr1(const char *s, int c);
char	*ft_strcpy1(char *s1, const char *s2);
void	ft_strclr1(char **s);
char	*check_remainder(char **remainder, char **line);

#endif
