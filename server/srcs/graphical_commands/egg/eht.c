/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eht.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psprawka <psprawka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/13 17:44:53 by tle-huu-          #+#    #+#             */
/*   Updated: 2018/06/19 03:54:28 by psprawka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "zappy.h"

void	notify_hatchegg(int fd, t_egg *egg)
{
	int		len;

	strcpy(g_server.buff, "eht ");
	strcat(g_server.buff, ft_itoa(egg->number));
	strcat(g_server.buff, "\n");
	len = ft_strlen(g_server.buff);
	if (send(fd, g_server.buff, len, 0) == -1)
		error(0, "Send [g: eht]", true);

}
