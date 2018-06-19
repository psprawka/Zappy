/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smg.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-huu- <tle-huu-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/13 17:49:53 by tle-huu-          #+#    #+#             */
/*   Updated: 2018/06/18 00:35:17 by tle-huu-         ###   ########.fr       */
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
	send(fd, g_server.buff, len, 0);
}
