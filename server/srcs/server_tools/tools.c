/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psprawka <psprawka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/31 13:23:45 by psprawka          #+#    #+#             */
/*   Updated: 2018/06/19 04:34:54 by psprawka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "zappy.h"

int			graphic_direction(int direction)
{
	if (direction == NORTH)
		return (1);
	else if (direction == EAST)
		return (2);
	else if (direction == SOUTH)
		return (3);
	else if (direction == WEST)
		return (4);
	return (0);
}

uint32_t	ft_modulo(int k, int n)
{
	while (k < 0)
		k += n;
	return (k % n);
}

/*
**	A function below sends world's dimentions to a player by. A EXIT_SUCCESS
**	value is returned upon successful sending, otherwise EXIT_FAILURE.
*/
int			tools_world_dimensions(t_player *player)
{
	ft_bzero(g_server.buff, SERV_BUFF_SIZE);
	ft_strcpy(g_server.buff, ft_itoa(g_server.map->width));
	ft_strcat(g_server.buff, " ");
	ft_strcat(g_server.buff, ft_itoa(g_server.map->height));
	ft_strcat(g_server.buff, "\n");
	if (send(player->fd, g_server.buff, ft_strlen(g_server.buff), 0) == -1)
		return (error(0, "Send [tools_world_dimensions]", true));
	return (EXIT_SUCCESS);
}

/*
**	An error function just handles all error messages based on the number
**	sent in function call. If number is not found, strerror mesage is sent.
**	I bool flag (ifailure) is set to true func returns EXIT_FAILURE,
**	otherwise EXIT_SUCCESS.
*/
int			error(int errnb, char *msg, bool ifailure)
{
	if (errnb == 1)
		printf("Usage: server -p <port> -x <width> -y <height> -n <team> [<team>] [<team>] ... -c <nb> -t <t>\n");
	else if (errnb == 2)
		printf("Port number has to be between 1024 and 65535!\n");
	else if (errnb == 3)
		printf("world's width and height have to be between 2 and 100\n");
	else if (errnb == 4)
		printf("At least one team required\n");
	else if (errnb == 5)
		printf("Number of clients at the beginning: form 1 to %d.\n", FD_SETSIZE);
	else if (errnb == 6)
		printf("Time unit has to be between 1 and 10000\n");
	else if (errnb == 7)
		printf("%sA graphic client already watching%s\n", RED, NORMAL);
	else if (errnb == 8)
		printf("%sError resource number: resource doesn't exist\n%s", RED, NORMAL);
	else
		printf("%s%s: %s%s\n", RED, msg, strerror(errno), NORMAL);
	return (ifailure == true ? EXIT_FAILURE : EXIT_SUCCESS);
}
