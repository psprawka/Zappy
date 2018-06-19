/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ebo.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-huu- <tle-huu-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/13 17:01:08 by tle-huu-          #+#    #+#             */
/*   Updated: 2018/06/18 00:34:56 by tle-huu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "zappy.h"

// TODO: IMPLEMENT THE EGG SYSTEM

void	notify_connectegg(int fd, t_egg *egg)
{
	int		len;
	char	*freer;

	strcpy(g_server.buff, "ebo ");
	strcat(g_server.buff, (freer = ft_itoa(egg->number)));
	free(freer);
	strcat(g_server.buff, "\n");
	len = strlen(g_server.buff);
	send(fd, g_server.buff, len, 0);
}
