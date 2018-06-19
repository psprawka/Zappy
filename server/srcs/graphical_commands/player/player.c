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
// 	if (!(node = g_server.graph_list))
// 		return ;
// 	strcpy(g_server.buff, "pnw ");
// 	strcat(g_server.buff, "#");
// 	strcat(g_server.buff, ft_itoa(player->fd));
// 	strcat(g_server.buff, " ");
// 	strcat(g_server.buff, ft_itoa(player->position->x));
// 	strcat(g_server.buff, " ");
// 	strcat(g_server.buff, ft_itoa(player->position->y));
// 	strcat(g_server.buff, " ");
// 	strcat(g_server.buff, ft_itoa(player->direction));
// 	strcat(g_server.buff, " ");
// 	strcat(g_server.buff, ft_itoa(player->level));
// 	strcat(g_server.buff, " ");
// 	strcat(g_server.buff, player->team->name);
// 	strcat(g_server.buff, "\n");
// 	len = ft_strlen(g_server.buff);
// 	while (node)
// 	{
// 		send(node->fd, g_server.buff, len, 0);
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
// 	if (!(node = g_server.graph_list))
// 		return ;
// 	strcpy(g_server.buff, "plv #");
// 	strcat(g_server.buff, ft_itoa(player->fd));
// 	strcat(g_server.buff, " ");
// 	strcat(g_server.buff, ft_itoa(player->level));
// 	strcat(g_server.buff, "\n");
// 	len = ft_strlen(g_server.buff);
// 	while (node)
// 	{
// 		send(node->fd, g_server.buff, len, 0);
// 		node = node->next;
// 	}
// }
//
// void	send_inventory(t_player *player, t_server *server)
// {
// 	int		len;
// 	t_graphic_list	*node;
//
// 	strcpy(g_server.buff, "pin #");
// 	strcat(g_server.buff, ft_itoa(player->fd));
// 	strcat(g_server.buff, " ");
// 	strcat(g_server.buff, ft_itoa(player->position->x));
// 	strcat(g_server.buff, " ");
// 	strcat(g_server.buff, ft_itoa(player->position->y));
// 	strcat(g_server.buff, " ");
// 	strcat(g_server.buff, ft_itoa(player->inv.food));
// 	strcat(g_server.buff, " ");
// 	strcat(g_server.buff, ft_itoa(player->inv.linemate));
// 	strcat(g_server.buff, " ");
// 	strcat(g_server.buff, ft_itoa(player->inv.deraumere));
// 	strcat(g_server.buff, " ");
// 	strcat(g_server.buff, ft_itoa(player->inv.sibur));
// 	strcat(g_server.buff, " ");
// 	strcat(g_server.buff, ft_itoa(player->inv.mendiane));
// 	strcat(g_server.buff, " ");
// 	strcat(g_server.buff, ft_itoa(player->inv.phiras));
// 	strcat(g_server.buff, " ");
// 	strcat(g_server.buff, ft_itoa(player->inv.thystame));
// 	strcat(g_server.buff, "\n");
// 	len = ft_strlen(g_server.buff);
// 	if (!(node = g_server.graph_list))
// 		return ;
// 	while (node)
// 	{
// 		send(((t_graphic *)(node->content))->fd, g_server.buff, len, 0);
// 		node = node->next;
// 	}
// }
//
// void	notify_kick(t_player *player, t_server *server)
// {
// 	int		len;
// 	t_graphic_list	*node;
//
// 	strcpy(g_server.buff, "pex #");
// 	strcat(g_server.buff, ft_itoa(player->fd));
// 	len = ft_strlen(g_server.buff);
// 	if (!(node = g_server.graph_list))
// 		return ;
// 	while (node)
// 	{
// 		send(((t_graphic *)(node->content))->fd, g_server.buff, len, 0);
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
// 	strcpy(g_server.buff, "pbc #");
// 	strcat(g_server.buff, ft_itoa(player->fd));
// 	strcat(g_server.buff, " ");
// 	strcat(g_server.buff, msg);
// 	strcat(g_server.buff, "\n");
// 	len = ft_strlen(g_server.buff);
// 	if (!(node = g_server.graph_list))
// 		return ;
// 	while (node)
// 	{
// 		send(((t_graphic *)(node->content))->fd, g_server.buff, len, 0);
// 		node = node->next;
// 	}
// }
//
// void	notify_starve(t_player *player, t_server *server)
// {
// 	int		len;
// 	t_graphic_list	*node;
//
// 	strcpy(g_server.buff, "pdi #");
// 	strcat(g_server.buff, ft_itoa(player->fd));
// 	strcat(g_server.buff, "\n");
// 	len = ft_strlen(g_server.buff);
// 	if (!(node = g_server.graph_list))
// 		return ;
// 	while (node)
// 	{
// 		send(((t_graphic *)(node->content))->fd, g_server.buff, len, 0);
// 		node = node->next;
// 	}
// }
//
// void	resource_drop(t_player *player, uint8_t resource, t_server *server)
// {
// 	int		len;
// 	t_graphic_list	*node;
//
// 	strcpy(g_server.buff, "pdr #");
// 	strcat(g_server.buff, ft_itoa(player->fd));
// 	strcat(g_server.buff, " ");
// 	strcat(g_server.buff, ft_itoa(resource));
// 	strcat(g_server.buff, "\n");
// 	len = ft_strlen(g_server.buff);
// 	if (!(node = g_server.graph_list))
// 		return ;
// 	while (node)
// 	{
// 		send(node->fd, g_server.buff, len, 0);
// 		node = node->next;
// 	}
// }
//
// void	resource_pickup(t_player *player, t_server *server)
// {
// 	int		len;
// 	t_graphic_list	*node;
//
// 	strcpy(g_server.buff, "pgt #");
// 	strcat(g_server.buff, ft_itoa(client->fd));
// 	strcat(g_server.buff, " ");
// 	// strcat(g_server.buff, ft_itoa(resource));
// 	strcat(g_server.buff, "\n");
// 	len = ft_strlen(g_server.buff);
// 	if (!(node = g_server.graph_list))
// 		return ;
// 	while (node)
// 	{
// 		send(node->fd, g_server.buff, len, 0);
// 		node = node->next;
// 	}
// }
