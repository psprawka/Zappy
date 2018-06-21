/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   take.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psprawka <psprawka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/29 21:49:59 by psprawka          #+#    #+#             */
/*   Updated: 2018/06/21 06:16:53 by psprawka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "zappy.h"

/*
**		Parse the message to know what ressource the player wants to take
*/

static int		parse_message(char *msg)
{
	char	*ressource_name;
	int		ressource_nbr;
	int		i;

	if (!strnstr(msg, "take ", 5))
		return (-1);
	ressource_name = msg + 5;
	ressource_nbr = 0;
	i = 0;
	while (g_ressources[ressource_nbr]
			&& !strstr(ressource_name, g_ressources[ressource_nbr]))
		ressource_nbr++;
	if (ressource_nbr >= 7)
		return (-1);
	return (ressource_nbr);
}

int				command_take(void *entity, char *msg)
{
	t_square	*square;
	int			x;
	int			y;
	int			ressource_nbr;

	printf("%sPlayer [%d] -> [take]%s\n", CYAN, P_ENTITY->fd, NORMAL);
	ressource_nbr = parse_message(msg);
	if (ressource_nbr < 0 || ressource_nbr > 6)
	{
		if (send(P_ENTITY->fd, MSG_KO, strlen(MSG_KO), 0) == -1)
			return (error(0, "Send [take]", false));
		return (error(8, NULL, true));
	}
	x = P_ENTITY->x;
	y = P_ENTITY->y;
	square = g_server.map->squares[x][y];
	if (square->ressources[ressource_nbr] > 0)
	{
		P_ENTITY->inventory[ressource_nbr]++;
		square->ressources[ressource_nbr]--;
		if (send(P_ENTITY->fd, MSG_OK, strlen(MSG_OK), 0) == -1)
			return (error(0, "Send [take]", false));
	}
	else
	{
		if (send(P_ENTITY->fd, MSG_KO, strlen(MSG_KO), 0) == -1)
			return (error(0, "Send [take]", false));
	}
	notify_ressource_pickup(P_ENTITY, ressource_nbr);
	send_inventory(0, P_ENTITY);
	send_block_contents(0, x, y);
	P_ENTITY->requests_nb--;
	return (EXIT_SUCCESS);
}
