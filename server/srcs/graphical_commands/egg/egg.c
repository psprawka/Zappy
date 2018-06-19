/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   egg.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asyed <asyed@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/08 14:05:15 by asyed             #+#    #+#             */
/*   Updated: 2018/06/16 18:02:31 by tle-huu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "zappy.h"
//
// void	notify_layegg(t_player *player, t_server *server)
// {
// 	int				len;
// 	t_graphic_list	*node;
//
// 	strcpy(g_server.buff, "pfk #");
// 	strcat(g_server.buff, ft_itoa(player->fd));
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
// void	notify_hatchegg(t_player *player, t_server *server)
// {
// 	int		len;
// 	t_graphic_list	*node;
//
// 	strcpy(g_server.buff, "eht #");
// 	strcat(g_server.buff, ft_itoa(player->fd));
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
// void	notify_connectegg(t_player *player, t_server *server)
// {
// 	int		len;
// 	t_graphic_list	*node;
//
// 	strcpy(g_server.buff, "eht #");
// 	strcat(g_server.buff, ft_itoa(player->fd));
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
