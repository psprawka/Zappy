/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sgt.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asyed <asyed@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/07 16:11:15 by asyed             #+#    #+#             */
/*   Updated: 2018/06/16 19:59:30 by tle-huu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "zappy.h"

void		send_timeunit(int fd)
{
	static char	timeunit[12] =	"\0";
	int							len;
	char						*freer;

	freer = NULL;
	if (!timeunit[0])
		strcpy(timeunit, (freer = ft_itoa(g_server.timeunit)));
	free(freer);
	strcpy(g_server.buff, "sgt ");
	strcat(g_server.buff, timeunit);
	strcat(g_server.buff, "\n");
	len = strlen(g_server.buff);
	if (send(fd, g_server.buff, len, 0) < 0)
		printf("SEND FAILED\n");
}
