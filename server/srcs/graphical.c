/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphical.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psprawka <psprawka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/21 04:48:18 by psprawka          #+#    #+#             */
/*   Updated: 2018/06/21 07:08:37 by psprawka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "zappy.h"

int		notify_graphics(int fd)
{
	t_list	*tmp;
	int		len;

	len = strlen(g_server.buff);
	if (fd)
	{
		if (send(fd, g_server.buff, len, 0) == -1)
			return (EXIT_FAILURE);
		return (EXIT_SUCCESS);
	}
	tmp = g_server.graphics;
	while (tmp)
	{
		if (send(tmp->key, g_server.buff, len, 0) == -1)
			return (EXIT_FAILURE);
		tmp = tmp->next;
	}
	return (EXIT_SUCCESS);
}
