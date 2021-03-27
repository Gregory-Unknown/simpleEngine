/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esobchak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/31 15:35:15 by esobchak          #+#    #+#             */
/*   Updated: 2021/03/27 18:16:38 by esobchak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static int	ft_check_texture(char **str, t_pars *pars)
{
	if (!(*str))
		return (0);
	if (ft_strncmp(str[0], "R", 2) == 0)
		return (ft_screen_resolution(str[1], str[2], pars));
	else if (ft_strncmp(str[0], "NO", 2) == 0)
		return (ft_set_texture(str[1], &pars->no));
	else if (ft_strncmp(str[0], "SO", 2) == 0)
		return (ft_set_texture(str[1], &pars->so));
	else if (ft_strncmp(str[0], "WE", 2) == 0)
		return (ft_set_texture(str[1], &pars->we));
	else if (ft_strncmp(str[0], "EA", 2) == 0)
		return (ft_set_texture(str[1], &pars->ea));
	else if (ft_strncmp(str[0], "S", 1) == 0)
		return (ft_set_texture(str[1], &pars->s));
	else if (ft_strncmp(str[0], "F", 1) == 0)
		return (ft_set_color(str[1], &pars->f_col));
	else if (ft_strncmp(str[0], "C", 1) == 0)
		return (ft_set_color(str[1], &pars->c_col));
	return (1);
}

static char	**make_map(t_list **head, int size)
{
	int		i;
	char	**map;
	t_list	*tmp;

	i = 0;
	map = ft_calloc((size + 1), sizeof(char *));
	tmp = *head;
	while (tmp)
	{
		map[i] = ft_strdup(tmp->content);
		i++;
		tmp = tmp->next;
	}
	ft_lstclear(head, &free);
	return (map);
}

static int	ft_pars(char *line, int *flag, t_pars *pars, t_list **head)
{
	int		size;
	char	**map;

	size = 0;
	map = 0;
	map = ft_split(line, ' ');
	*flag = ft_check_texture(map, pars);
	if (*flag == 1 && line)
	{
		ft_lstadd_back(&(*head), ft_lstnew(ft_strdup(line)));
		size++;
		//free(line);
		//line = NULL;
	}
	free(line);
	ft_free_str(map);
	map = NULL;
	return (size);
}



int			ft_parser(int fd, t_pars *pars)
{
	int		flag;
	int		size;
	char	*line;
	t_list	*head;

	line = 0;
	head = 0;
	size = 0;
	flag = 0;
	ft_init_pars(pars);
	while (flag != -1 && get_next_line(fd, &line))
		size += ft_pars(line, &flag, pars, &head);
	ft_lstadd_back(&head, ft_lstnew(line));
	size++;
	pars->map = make_map(&head, size);
	if (ft_check_map(pars->map))
		flag = -1;
	return (flag);
}
