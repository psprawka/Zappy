/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_ai.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psprawka <psprawka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/14 22:03:33 by psprawka          #+#    #+#             */
/*   Updated: 2018/06/21 05:26:21 by psprawka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "zappy.h"

t_events	g_events_ai[] =
{
	{"advance", 7, command_advance}, 				//0
	{"right", 7, command_right},					//1
	{"left", 7, command_left},						//2
	{"see", 7, command_see},						//3
	{"inventory", 1, command_inventory},			//4
	{"take", 7, command_take},						//5
	{"put", 7, command_put},						//6
	{"kick", 7, command_kick},						//7
	{"broadcast", 7, command_broadcast},			//8
	{"incantation", 0, command_incantation},		//9
	{"fork", 42, command_fork},						//10
	{"connect_nbr", 0, command_connect_nbr},		//11
	{"hatches", 600, command_hatch},				//12
	{"eat", 126, command_eat},						//13
	{"egg_death", 600 + 1260, command_egg_death}, 	//14		//hatching time + 1260 because 10 * 126 so egg's "lifetime"
	{"levelup", 300, command_levelup},				//15
	{NULL, 0, NULL}
};

/*
**	In function handle_ai we iterate through g_event_ai dispatch table
**	and search for an event a player requested. If command is found, event
**	is added to priority queue and EXIT_SUCCESS returned, otherwise
**	a MSG_NOCOMMAND message is sent to client and EXIT_FAILURE returned.
*/
int		handle_ai(int fd, char *msg)
{
	int i;

	i = 0;
	while (g_events_ai[i].msg)
	{
		if (!ft_strcmp(g_events_ai[i].msg, msg) || strstr(msg, g_events_ai[i].msg))
		{
			if (strstr(msg, "fork"))
				notify_lay_egg(g_entity[fd]);
			add_event(g_entity[fd], T_PLAYER, i, msg);
			return (EXIT_SUCCESS);
		}
		i++;
	}
	if (send(fd, MSG_NOCOMMAND, ft_strlen(MSG_NOCOMMAND), 0) == -1)
		error(0, "Send [handle_ai]", true);
	return (EXIT_FAILURE);
}
