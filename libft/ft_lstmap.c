/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esobchak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 19:02:54 by esobchak          #+#    #+#             */
/*   Updated: 2020/11/04 10:23:36 by esobchak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*list;
	t_list	*list2;

	list = 0;
	while (lst)
	{
		if (!(list2 = ft_lstnew(f(lst->content))))
		{
			ft_lstclear(&list, del);
			return (0);
		}
		ft_lstadd_back(&list, list2);
		lst = lst->next;
	}
	return (list);
}
