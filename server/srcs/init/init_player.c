/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psprawka <psprawka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/15 00:15:03 by psprawka          #+#    #+#             */
/*   Updated: 2018/06/19 02:30:12 by psprawka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "zappy.h"

/*
**	Init_player initialize a player and sets all its variables as needed, e.g.:
**	-> orientation (new->direction) is set randomly,
**	-> inventory is set to 0,
**	-> food (new->inventory[0]) is set to 10 (1260 timeunit),
**	-> player is randomly set on the map (rand_position(new, ...)),
**	-> incantation process is set to false,
**	-> time of last request is set to 0 (ft_bzero(&new->last_request, ...)).
**	-> requests is set 1 because at the beginning we're sending a number of
**		connections allowed for this team which is a command, thus we have
**		to add one (since connect_nbr is requested from server).
*/

t_player	*init_player(int sockfd)
{
	t_player *new;

	if (!(new = ft_memalloc(sizeof(t_player))))
		return (NULL);
	new->fd = sockfd;
	new->team = NULL;
	new->level = 1;
	new->direction = rand_direction();
	ft_bzero(new->inventory, 7);
	new->inventory[0] = 10000;//
	new->inventory[1] = 10;//
	new->inventory[2] = 10;//
	new->inventory[3] = 10;//
	new->inventory[4] = 10;//
	new->inventory[5] = 10;//
	new->inventory[6] = 10;//
	rand_position(new);
	new->incantation = false;
	ft_bzero(&new->last_request, sizeof(struct timeval));
	new->requests_nb = 1;
	return (new);
}

///////////////////////////////////////////////////////////////////////
