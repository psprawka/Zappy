/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-huu- <tle-huu-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/24 17:19:47 by tle-huu-          #+#    #+#             */
/*   Updated: 2018/06/14 12:38:30 by tle-huu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

t_list		*ft_lstnew(void const *content, long long int content_size)
{
	t_list		*list;

	if (!(list = (t_list *)ft_memalloc(sizeof(t_list)))
		|| !(list->content = ft_memalloc(content_size)))
		return (NULL);
	if (content)
	{
		memmove(list->content, content, content_size);
		list->content_size = content_size;
	}
	else
	{
		list->content = NULL;
		list->content_size = 0;
	}
	list->next = NULL;
	return (list);
}
