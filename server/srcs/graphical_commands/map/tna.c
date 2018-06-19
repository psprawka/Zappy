/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tna.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-huu- <tle-huu-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/13 16:55:29 by tle-huu-          #+#    #+#             */
/*   Updated: 2018/06/16 19:59:38 by tle-huu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "zappy.h"

void	send_teams(int fd)
{
	int					i;
	int					len;

	i = 0;
	while (g_server.teams && g_server.teams[i])
	{
		strcpy(g_server.buff, "tna ");
		strcat(g_server.buff, g_server.teams[i]->name);
		strcat(g_server.buff, "\n");
		len = strlen(g_server.buff);
		send(fd, g_server.buff, len, 0);
		i++;
	}
}
