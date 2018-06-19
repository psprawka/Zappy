/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ebo.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psprawka <psprawka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/13 17:01:08 by tle-huu-          #+#    #+#             */
/*   Updated: 2018/06/19 04:22:58 by psprawka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "zappy.h"

void	notify_connectegg(int fd, t_egg *egg)
{
	int		len;

	strcpy(g_server.buff, "ebo ");
	strcat(g_server.buff, ft_itoa(egg->number));
	strcat(g_server.buff, "\n");
	len = strlen(g_server.buff);
	if (g_server.graphic_fd && send(fd, g_server.buff, len, 0) == -1)
		error(0, "Send [g: ebo]", true);
}
