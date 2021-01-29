/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esobchak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 15:45:48 by esobchak          #+#    #+#             */
/*   Updated: 2020/11/24 16:14:29 by esobchak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

int		get_next_line(int fd, char **line);
int		ft_strlen(const char *s1);
char	*ft_strdup(const char *s1);
char	*ft_strjoin(char *s1, const char *s2);
char	*ft_strnew(size_t size);
char	*ft_strchr(const char *s, int c);
char	*ft_strcpy(char *s1, const char *s2);
void	ft_strclr(char **s);
char	*check_remainder(char **remainder, char **line);

#endif
