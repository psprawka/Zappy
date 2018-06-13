/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_pqueue.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psprawka <psprawka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/12 09:20:50 by psprawka          #+#    #+#             */
/*   Updated: 2018/06/12 11:34:41 by psprawka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			push_pqueue(t_pqueue **head, void *data, int priority)
{
	t_pqueue	*tmp;
	t_pqueue	*new;

	if (!(new = create_pnode(data, priority)))
		return (EXIT_FAILURE);
	if (!(*head) || (*head)->priority > new->priority)
	{
		new->next = *head;
		*head = new;
	}
	else
	{
		tmp = *head;
		while (tmp->next && tmp->next->priority < new->priority)
			tmp = tmp->next;
		new->next = tmp->next;
		tmp->next = new;
	}
	return (EXIT_SUCCESS);
}
