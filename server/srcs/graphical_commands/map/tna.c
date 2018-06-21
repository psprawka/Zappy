/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tna.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psprawka <psprawka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/13 16:55:29 by tle-huu-          #+#    #+#             */
/*   Updated: 2018/06/21 06:14:25 by psprawka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "zappy.h"

void	send_teams(int fd)
{
	int		i;

	i = 0;
	while (g_server.teams && g_server.teams[i])
	{
		strcpy(g_server.buff, "tna ");
		strcat(g_server.buff, g_server.teams[i]->name);
		strcat(g_server.buff, "\n");
		if (notify_graphics(fd) == EXIT_FAILURE)
			error(0, "Send [g: tna]", true);
		i++;
	}
}
