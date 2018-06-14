/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_pevent.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psprawka <psprawka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/12 13:54:03 by psprawka          #+#    #+#             */
/*   Updated: 2018/06/14 06:36:56 by psprawka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "zappy.h"

int		push_pevent(t_pevent **head, t_pevent *new)
{
	t_pevent	*tmp;

	if (!(*head) || time_compare((*head)->event_time, new->event_time))
	{
		new->next = *head;
		*head = new;
	}
	else
	{
		tmp = *head;
		while (tmp->next && !(time_compare(tmp->next->event_time, new->event_time)))
			tmp = tmp->next;
		new->next = tmp->next;
		tmp->next = new;
	}
	new->player->requests_nb++;
	return (EXIT_SUCCESS);
}