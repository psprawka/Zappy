/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msz.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-huu- <tle-huu-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/13 17:53:27 by tle-huu-          #+#    #+#             */
/*   Updated: 2018/06/16 19:59:33 by tle-huu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "zappy.h"

void		map_size(int fd)
{
	int					len;
	char				*freer;

	strcpy(g_server.buff, "msz ");
	freer = ft_itoa(g_server.map->width);
	strcat(g_server.buff, freer);
	free(freer);
	strcat(g_server.buff, " ");
	freer = ft_itoa(g_server.map->height);
	strcat(g_server.buff, freer);
	free(freer);
	strcat(g_server.buff, "\n");
	len = strlen(g_server.buff);
	send(fd, g_server.buff, len, 0);
}
