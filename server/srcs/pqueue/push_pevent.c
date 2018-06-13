/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_pevent.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psprawka <psprawka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/12 13:54:03 by psprawka          #+#    #+#             */
/*   Updated: 2018/06/13 15:24:55 by psprawka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "zappy.h"


int		compare_delays(struct timeval first, struct timeval second)
{
	if (first.tv_sec != second.tv_sec)
		return (first.tv_sec >= second.tv_sec);
	
	return (first.tv_usec >= second.tv_usec);
}

int		push_pevent(t_pevent **head, t_pevent *new)
{
	t_pevent	*tmp;

	if (!(*head) || compare_delays((*head)->delaytime, new->delaytime))
	{
		new->next = *head;
		*head = new;
	}
	else
	{
		tmp = *head;
		while (tmp->next && !(compare_delays(tmp->next->delaytime, new->delaytime)))
			tmp = tmp->next;
		new->next = tmp->next;
		tmp->next = new;
	}
	new->player->requests_nb++;
	return (EXIT_SUCCESS);
}