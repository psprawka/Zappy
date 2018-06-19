/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   suc.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psprawka <psprawka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/13 17:49:53 by tle-huu-          #+#    #+#             */
/*   Updated: 2018/06/19 04:23:31 by psprawka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "zappy.h"

void			unknown_command(int fd)
{
	int				len;

	strcpy(g_server.buff, "suc");
	strcat(g_server.buff, "\n");
	len = ft_strlen(g_server.buff);
	if (g_server.graphic_fd && send(fd, g_server.buff, len, 0) == -1)
		error(0, "Send [g: suc]", true);
}
