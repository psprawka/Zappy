/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psprawka <psprawka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/17 06:42:16 by psprawka          #+#    #+#             */
/*   Updated: 2018/06/19 07:43:12 by psprawka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "zappy.h"

/*
**	In order to get rid of all the actions associated with dying player, 
**	function clena_queue will go through pqueue of event and will remove
**	all of player's events.
*/
void	clean_queue(int fd)
{
	t_node		*tmp;
	t_node		*prev;
	t_node		*to_free;
	t_event		*event;
	int 	i;
	
	tmp = g_server.events->first;
	prev = NULL;
	while (tmp)
	{
		event = tmp->data;
		if (event && ((t_player *)event->entity)->fd == fd)
		{
			remove_node(&g_server.events, prev, tmp);
			free_event(event);
			to_free = tmp;
			tmp = tmp->next;
			free(to_free);
		}
		else
			prev = tmp;
	}
}