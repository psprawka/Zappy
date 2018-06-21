/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msz.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psprawka <psprawka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/13 17:53:27 by tle-huu-          #+#    #+#             */
/*   Updated: 2018/06/21 06:03:04 by psprawka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "zappy.h"

void	map_size(int fd)
{
	int		len;

	strcpy(g_server.buff, "msz ");
	strcat(g_server.buff, ft_itoa(g_server.map->width));
	strcat(g_server.buff, " ");
	strcat(g_server.buff, ft_itoa(g_server.map->height));
	strcat(g_server.buff, "\n");
	len = strlen(g_server.buff);
	if (notify_graphics(fd) == EXIT_FAILURE)
		error(0, "Send [g: msz]", true);
}
