/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_structs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psprawka <psprawka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/26 18:45:10 by psprawka          #+#    #+#             */
/*   Updated: 2018/06/14 11:58:06 by tle-huu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "zappy.h"

int		init_square(t_square *square)
{
	int	i;

	i = 0;
	if (!(square = ft_memalloc(sizeof(t_square))))
		return (EXIT_FAILURE);
	// ft_bzero(square->ressources, 7);
	if (!(square->players = ft_memalloc(sizeof(t_player) * FD_SETSIZE)))
		return (EXIT_FAILURE);
	while (i < FD_SETSIZE)
		square->players[i++] = NULL;
	return (EXIT_SUCCESS);
}

int		init_map(t_server *server)
{
	int i;
	int j;


//		Change X Y ?
	i = 0;
	if (!(server->map->squares = ft_memalloc(server->map->height * sizeof(t_square *))))
		return (EXIT_FAILURE);
	while (i < server->map->height)
	{
		if (!(server->map->squares[i] = ft_memalloc(server->map->width * sizeof(t_square))))
		{
			//Free all that aren't NULL.
			return (EXIT_FAILURE);
		}
		j = 0;
		while (j < server->map->width)
		{
			if (init_square(server->map->squares[i][j++]) == EXIT_FAILURE)
				return(error(0, "Initialize map", true));
		}
		i++;
	}
	return (EXIT_SUCCESS);
}


t_player	*init_player(int sockfd, t_server *server)
{
	t_player *new;

	if (!(new = ft_memalloc(sizeof(t_player))))
		return (NULL);
	new->fd = sockfd;
	new->team = NULL;
	new->level = 0;
	new->direction = rand_direction();
	ft_bzero(new->inventory, 7);
	new->inventory[0] = 10;
	new->see_range = 1;
	rand_position(new, server->map);
	ft_bzero(&new->last_request, sizeof(struct timeval));
	new->requests_nb = 0;
	new->type = T_NONDEF;
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
	if (!(serv->buff = ft_memalloc(2048 * sizeof(char))))
		return (EXIT_FAILURE);

	serv->timeunit = -1;
	serv->port = 0;
	serv->max_team_players = 0;
	serv->teamcount = 0;
	serv->sockfd = 0;
	return (EXIT_SUCCESS);
}

int			init_action_arg(t_action_arg *arg, int ressource, char *message)
{
	//		!!!! HAS TO BE USED WITH AN ACTION ARG ALLOCATED ON THE STACK !!
	arg->ressource = ressource;
	arg->message = message;
	return (EXIT_SUCCESS);
}
