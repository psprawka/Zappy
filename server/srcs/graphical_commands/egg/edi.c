/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   edi.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psprawka <psprawka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/16 18:01:33 by tle-huu-          #+#    #+#             */
/*   Updated: 2018/06/19 04:23:00 by psprawka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "zappy.h"

void	notify_starve_egg(int fd, t_egg *egg)
{
	int		len;

	strcpy(g_server.buff, "edi ");
	strcat(g_server.buff, ft_itoa(egg->number));
	strcat(g_server.buff, "\n");
	len = strlen(g_server.buff);
	if (g_server.graphic_fd && send(fd, g_server.buff, len, 0) == -1)
		error(0, "Send [g: edi]", true);
}
