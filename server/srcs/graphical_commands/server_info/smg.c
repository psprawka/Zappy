/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smg.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psprawka <psprawka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/13 17:49:53 by tle-huu-          #+#    #+#             */
/*   Updated: 2018/06/19 03:55:30 by psprawka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "zappy.h"

void			server_message(int fd, char *message)
{
	int				len;

	strcpy(g_server.buff, "smg ");
	strcat(g_server.buff, message);
	strcat(g_server.buff, "\n");
	len = ft_strlen(g_server.buff);
	if (send(fd, g_server.buff, len, 0) == -1)
		error(0, "Send [g: smg]", true);
}
