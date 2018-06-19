/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   seg.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-huu- <tle-huu-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/13 17:48:29 by tle-huu-          #+#    #+#             */
/*   Updated: 2018/06/18 01:49:40 by tle-huu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "zappy.h"

void			game_over(int fd, t_team *team)
{
	int				len;

	strcpy(g_server.buff, "seg ");
	strcat(g_server.buff, team->name);
	strcat(g_server.buff, "\n");
	len = strlen(g_server.buff);
	send(fd, g_server.buff, len, 0);
}
