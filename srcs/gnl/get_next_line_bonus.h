/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esobchak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 13:36:17 by esobchak          #+#    #+#             */
/*   Updated: 2020/11/25 13:38:48 by esobchak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

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
