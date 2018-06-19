/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sgt.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psprawka <psprawka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/07 16:11:15 by asyed             #+#    #+#             */
/*   Updated: 2018/06/19 04:23:26 by psprawka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "zappy.h"

void		send_timeunit(int fd)
{
	static char	timeunit[12] =	"\0";
	int							len;

	if (!timeunit[0])
		strcpy(timeunit, ft_itoa(g_server.timeunit));
	strcpy(g_server.buff, "sgt ");
	strcat(g_server.buff, timeunit);
	strcat(g_server.buff, "\n");
	len = strlen(g_server.buff);
	if (g_server.graphic_fd && g_server.graphic_fd && send(fd, g_server.buff, len, 0) == -1)
		error(0, "Send [g: sgt]", true);
}
