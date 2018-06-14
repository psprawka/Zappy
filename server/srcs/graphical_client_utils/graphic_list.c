/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphic_list.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-huu- <tle-huu-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/13 16:23:56 by tle-huu-          #+#    #+#             */
/*   Updated: 2018/06/13 16:28:06 by tle-huu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "zappy_graphic_queue.h"


t_graphic_list		*ft_lstnew(int fd)
{
	t_graphic_list		*list;

	if (!(list = (t_graphic_list *)ft_memalloc(sizeof(t_graphic_list))))
		return (NULL);
	list->fd = fd;
	list->next = NULL;
	return (list);
}

void				glist_add(t_graphic_list **alst, t_graphic_list *nw)
{
	if (alst && nw)
	{
		if (!nw)
			return ;
		nw->next = *alst;
		*alst = nw;
	}
}


void				glist_add_end(t_graphic_list **alst, t_graphic_list *nw)
{
	t_graphic_list	*tmp;

	if (alst && nw)
	{
		if (!new)
			return ;
		if (!(tmp = *alst))
		{
			*alst = new;
			return ;
		}
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
	}
}


int					glist_length(t_graphic_list *list)
{
	if (!list)
		return (0)
	return (1 + glist_length(list->next));
}
