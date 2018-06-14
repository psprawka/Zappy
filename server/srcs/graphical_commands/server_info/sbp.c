/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sbp.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-huu- <tle-huu-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/13 17:49:53 by tle-huu-          #+#    #+#             */
/*   Updated: 2018/06/13 17:52:17 by tle-huu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "zappy.h"

void			unknown_parameter(void)
{
	int				len;
	t_graphic_list	*node;

	strcpy(server->buff, "sbp");
	strcat(server->buff, "\n");
	len = ft_strlen(server->buff) + 1;
	if (!(node = server->graph_list))
		return ;
	while (node)
	{
		send(node->fd, server->buff, len, 0);
		node = node->next;
	}
}