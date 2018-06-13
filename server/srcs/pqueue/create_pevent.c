/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_pevent.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psprawka <psprawka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/12 13:54:49 by psprawka          #+#    #+#             */
/*   Updated: 2018/06/12 16:02:19 by psprawka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "zappy.h"

t_pevent *create_pevent(t_player *player, struct timeval delaytime, int itable, char *msg)
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
    new->delaytime = delaytime;
	player->last_request = new->delaytime;
	new->next = NULL;
	return (new);
}
