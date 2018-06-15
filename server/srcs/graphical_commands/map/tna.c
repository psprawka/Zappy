/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tna.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-huu- <tle-huu-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/13 16:55:29 by tle-huu-          #+#    #+#             */
/*   Updated: 2018/06/14 15:04:46 by tle-huu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	send_teams(t_player *gclient, t_server *server)
{
	int					i;
	int					len;
	t_graphic_list		*node;

	i = 0;
	while (server->teams && server->teams[i])
	{
		strcpy(server->buff, "tna ");
		strcat(server->buff, server->teams[i]->name);
		strcat(server->buff, "\n");
		len = strlen(server->buff) + 1;
		if (!(node = server->graph_list))
			return ;
		i++;
		if (gclient)
		{
			send(gclient->fd, server->buff, len, 0);
			continue ;
		}
		while (node)
		{
			send(node->fd, server->buff, len, 0);
			node = node->next;
		}
	}
}
