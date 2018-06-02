/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_structs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asyed <asyed@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/26 18:45:10 by psprawka          #+#    #+#             */
/*   Updated: 2018/06/02 02:28:59 by asyed            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "zappy.h"

t_player	*init_player(int sockfd, t_server *server)
{
	t_player *new;

	if (!(new = ft_memalloc(sizeof(t_player))))
		return (NULL);
	new->fd = sockfd;
	new->direction = rand_direction();
	new->see_range = 1;
	new->position = rand_position(server->map);
	new->lifetime = 1260;
	return (new);
}

int			init_server(t_server *serv)
{
	if (!(serv->players = ft_memalloc(sizeof(t_player *) * FD_SETSIZE)))
		return (EXIT_FAILURE);
	if (!(serv->map = ft_memalloc(sizeof(t_map))))
	{
		free(serv->players);
		return (EXIT_FAILURE);
	}
	serv->time = 10;
	serv->min_players = 1;
	return (EXIT_SUCCESS);
}
