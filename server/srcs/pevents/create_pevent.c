/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_pevent.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psprawka <psprawka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/12 13:54:49 by psprawka          #+#    #+#             */
/*   Updated: 2018/06/14 08:26:28 by psprawka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "zappy.h"

t_pevent *create_pevent(t_player *player, struct timeval *event_time, int itable, char *msg)
{
	t_pevent *new;

	if (!player || !(new = ft_memalloc(sizeof(t_pevent))))
	{
		error(0, "Create pevent", true);
		return (NULL);
	}

	new->player = player;
	new->fct = g_commands[itable].fct;
	new->msg = ft_strdup(msg);
	new->event_time = ft_memdup(event_time, sizeof(struct timeval));
	player->last_request = ft_memdup(new->event_time, sizeof(struct timeval));
	new->next = NULL;
	return (new);
}
