/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   edi.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-huu- <tle-huu-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/16 18:01:33 by tle-huu-          #+#    #+#             */
/*   Updated: 2018/06/18 00:34:59 by tle-huu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "zappy.h"

void	notify_starve_egg(int fd, t_egg *egg)
{
	int		len;
	char	*freer;

	strcpy(g_server.buff, "edi ");
	strcat(g_server.buff, (freer = ft_itoa(egg->number)));
	free(freer);
	strcat(g_server.buff, "\n");
	len = strlen(g_server.buff);
	send(fd, g_server.buff, len, 0);
}
