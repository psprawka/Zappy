/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstutils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-huu- <tle-huu-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/28 10:11:04 by tle-huu-          #+#    #+#             */
/*   Updated: 2018/06/14 12:17:40 by tle-huu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

t_list				*ft_lst_pop(t_list **list)
{
	t_list		*tmp;

	tmp = NULL;
	if (*list)
	{
		tmp = *list;
		(*list) = (*list)->next;
		tmp->next = NULL;
	}
	return (tmp);
}

int					ft_lst_is_sorted(t_list *stack)
{
	if (!stack || !(stack->next))
		return (1);
	return (stack->content_size <= stack->next->content_size
		&& ft_lst_is_sorted(stack->next));
}
