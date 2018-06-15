/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asyed <asyed@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/08 11:28:47 by asyed             #+#    #+#             */
/*   Updated: 2018/06/13 17:42:30 by tle-huu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//
// #include "zappy.h"
//
// void	notify_new_player(t_player *player, t_server *server)
// {
// 	t_graphic_list	*node;
// 	int				len;
//
// 	if (!(node = server->graph_list))
// 		return ;
// 	strcpy(server->buff, "pnw ");
// 	strcat(server->buff, "#");
// 	strcat(server->buff, ft_itoa(player->fd));
// 	strcat(server->buff, " ");
// 	strcat(server->buff, ft_itoa(player->position->x));
// 	strcat(server->buff, " ");
// 	strcat(server->buff, ft_itoa(player->position->y));
// 	strcat(server->buff, " ");
// 	strcat(server->buff, ft_itoa(player->direction));
// 	strcat(server->buff, " ");
// 	strcat(server->buff, ft_itoa(player->level));
// 	strcat(server->buff, " ");
// 	strcat(server->buff, player->team->name);
// 	strcat(server->buff, "\n");
// 	len = ft_strlen(server->buff) + 1;
// 	while (node)
// 	{
// 		send(node->fd, server->buff, len, 0);
// 		node = node->next;
// 	}
// }
//
//
// void	player_level(t_player *player, t_server *server)
// {
// 	t_graphic_list	*node;
// 	int				len;
//
// 	if (!(node = server->graph_list))
// 		return ;
// 	strcpy(server->buff, "plv #");
// 	strcat(server->buff, ft_itoa(player->fd));
// 	strcat(server->buff, " ");
// 	strcat(server->buff, ft_itoa(player->level));
// 	strcat(server->buff, "\n");
// 	len = ft_strlen(server->buff) + 1;
// 	while (node)
// 	{
// 		send(node->fd, server->buff, len, 0);
// 		node = node->next;
// 	}
// }
//
// void	send_inventory(t_player *player, t_server *server)
// {
// 	int		len;
// 	t_graphic_list	*node;
//
// 	strcpy(server->buff, "pin #");
// 	strcat(server->buff, ft_itoa(player->fd));
// 	strcat(server->buff, " ");
// 	strcat(server->buff, ft_itoa(player->position->x));
// 	strcat(server->buff, " ");
// 	strcat(server->buff, ft_itoa(player->position->y));
// 	strcat(server->buff, " ");
// 	strcat(server->buff, ft_itoa(player->inv.food));
// 	strcat(server->buff, " ");
// 	strcat(server->buff, ft_itoa(player->inv.linemate));
// 	strcat(server->buff, " ");
// 	strcat(server->buff, ft_itoa(player->inv.deraumere));
// 	strcat(server->buff, " ");
// 	strcat(server->buff, ft_itoa(player->inv.sibur));
// 	strcat(server->buff, " ");
// 	strcat(server->buff, ft_itoa(player->inv.mendiane));
// 	strcat(server->buff, " ");
// 	strcat(server->buff, ft_itoa(player->inv.phiras));
// 	strcat(server->buff, " ");
// 	strcat(server->buff, ft_itoa(player->inv.thystame));
// 	strcat(server->buff, "\n");
// 	len = ft_strlen(server->buff) + 1;
// 	if (!(node = server->graph_list))
// 		return ;
// 	while (node)
// 	{
// 		send(((t_graphic *)(node->content))->fd, server->buff, len, 0);
// 		node = node->next;
// 	}
// }
//
// void	notify_kick(t_player *player, t_server *server)
// {
// 	int		len;
// 	t_graphic_list	*node;
//
// 	strcpy(server->buff, "pex #");
// 	strcat(server->buff, ft_itoa(player->fd));
// 	len = ft_strlen(server->buff) + 1;
// 	if (!(node = server->graph_list))
// 		return ;
// 	while (node)
// 	{
// 		send(((t_graphic *)(node->content))->fd, server->buff, len, 0);
// 		node = node->next;
// 	}
// }
//
// /*
// ** Hook function - not callable unless you pass it msg!
// ** Haven't decided if msg should be a stack or heap string.
// */
//
// void	notify_broadcast(t_player *player, char *msg, t_server *server)
// {
// 	int		len;
// 	t_graphic_list	*node;
//
// 	strcpy(server->buff, "pbc #");
// 	strcat(server->buff, ft_itoa(player->fd));
// 	strcat(server->buff, " ");
// 	strcat(server->buff, msg);
// 	strcat(server->buff, "\n");
// 	len = ft_strlen(server->buff) + 1;
// 	if (!(node = server->graph_list))
// 		return ;
// 	while (node)
// 	{
// 		send(((t_graphic *)(node->content))->fd, server->buff, len, 0);
// 		node = node->next;
// 	}
// }
//
// void	notify_starve(t_player *player, t_server *server)
// {
// 	int		len;
// 	t_graphic_list	*node;
//
// 	strcpy(server->buff, "pdi #");
// 	strcat(server->buff, ft_itoa(player->fd));
// 	strcat(server->buff, "\n");
// 	len = ft_strlen(server->buff) + 1;
// 	if (!(node = server->graph_list))
// 		return ;
// 	while (node)
// 	{
// 		send(((t_graphic *)(node->content))->fd, server->buff, len, 0);
// 		node = node->next;
// 	}
// }
//
// void	resource_drop(t_player *player, uint8_t resource, t_server *server)
// {
// 	int		len;
// 	t_graphic_list	*node;
//
// 	strcpy(server->buff, "pdr #");
// 	strcat(server->buff, ft_itoa(player->fd));
// 	strcat(server->buff, " ");
// 	strcat(server->buff, ft_itoa(resource));
// 	strcat(server->buff, "\n");
// 	len = ft_strlen(server->buff) + 1;
// 	if (!(node = server->graph_list))
// 		return ;
// 	while (node)
// 	{
// 		send(node->fd, server->buff, len, 0);
// 		node = node->next;
// 	}
// }
//
// void	resource_pickup(t_player *player, t_server *server)
// {
// 	int		len;
// 	t_graphic_list	*node;
//
// 	strcpy(server->buff, "pgt #");
// 	strcat(server->buff, ft_itoa(client->fd));
// 	strcat(server->buff, " ");
// 	// strcat(server->buff, ft_itoa(resource));
// 	strcat(server->buff, "\n");
// 	len = ft_strlen(server->buff) + 1;
// 	if (!(node = server->graph_list))
// 		return ;
// 	while (node)
// 	{
// 		send(node->fd, server->buff, len, 0);
// 		node = node->next;
// 	}
// }
