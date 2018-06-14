/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plv.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-huu- <tle-huu-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/13 16:55:08 by tle-huu-          #+#    #+#             */
/*   Updated: 2018/06/13 16:55:09 by tle-huu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	player_level(t_player *player, t_server *server)
{
	t_graphic_list	*node;
	int				len;

	if (!(node = server->graph_list))
		return ;
	strcpy(server->buff, "plv #");
	strcat(server->buff, ft_itoa(player->fd));
	strcat(server->buff, " ");
	strcat(server->buff, ft_itoa(player->level));
	strcat(server->buff, "\n");
	len = ft_strlen(server->buff) + 1;
	while (node)
	{
		send(node->fd, server->buff, len, 0);
		node = node->next;
	}
}
