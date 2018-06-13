/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psprawka <psprawka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/07 16:11:15 by asyed             #+#    #+#             */
/*   Updated: 2018/06/12 23:31:37 by psprawka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "zappy.h"

void		send_timeunit(t_graphic *client, t_server *server)
{
	static char	timeunit[12] = "\0";
	t_node		*node;
	int			len;

	if (!timeunit[0])
		ft_strcpy(timeunit, ft_itoa(server->timeunit));
	ft_strcpy(server->buff, "sgt ");
	ft_strcat(server->buff, timeunit);
	ft_strcat(server->buff, "\n");
	len = ft_strlen(server->buff) + 1;
	if (!(node = server->graphics->first))
		return ;
	while (node)
	{
		send(((t_graphic *)(node->content))->fd, server->buff, len, 0);
		node = node->next;
	}
}