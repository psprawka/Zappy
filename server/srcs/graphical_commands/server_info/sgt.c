/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sgt.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psprawka <psprawka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/07 16:11:15 by asyed             #+#    #+#             */
/*   Updated: 2018/06/21 06:14:45 by psprawka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "zappy.h"

void		send_timeunit(int fd)
{
	static char	timeunit[12] =	"\0";

	if (!timeunit[0])
		strcpy(timeunit, ft_itoa(g_server.timeunit));
	strcpy(g_server.buff, "sgt ");
	strcat(g_server.buff, timeunit);
	strcat(g_server.buff, "\n");
	if (notify_graphics(fd) == EXIT_FAILURE)
		error(0, "Send [g: sgt]", true);
}
