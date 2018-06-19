/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eht.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-huu- <tle-huu-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/13 17:44:53 by tle-huu-          #+#    #+#             */
/*   Updated: 2018/06/18 00:35:03 by tle-huu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "zappy.h"

void	notify_hatchegg(int fd, t_egg *egg)
{
	int		len;
	char	*freer;

	strcpy(g_server.buff, "eht ");
	strcat(g_server.buff, (freer = ft_itoa(egg->number)));
	free(freer);
	strcat(g_server.buff, "\n");
	len = ft_strlen(g_server.buff);
	send(fd, g_server.buff, len, 0);

}
