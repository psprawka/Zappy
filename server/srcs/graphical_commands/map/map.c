// #include "zappy.h"
//
// void		map_size(t_server *server)
// {
// 	t_graphic_list		*node;
// 	int					len;
//
// 	strcpy(server->buff, "msz ");
// 	strcat(server->buff, ft_itoa(server->map->width));
// 	strcpy(server->buff, " ");
// 	strcat(server->buff, ft_itoa(server->map->height));
// 	strcpy(server->buff, "\n");
// 	len = ft_strlen(server->buff);
// 	while (node)
// 	{
// 		send(node->fd, server->buff, len, 0);
// 		node = node->next;
// 	}
// }
//
// void	send_block_contents(int x, int y, t_player *player, t_server *server)
// {
// 	int		len;
// 	t_graphic_list	*node;
//
// 	strcpy(server->buff, "bct ");
// 	strcat(server->buff, ft_itoa(x));
// 	strcat(server->buff, " ");
// 	strcat(server->buff, ft_itoa(y));
// 	strcat(server->buff, " ");
// 	strcat(server->buff, ft_itoa(server->map->squares[x][y].food));
// 	strcat(server->buff, " ");
// 	strcat(server->buff, ft_itoa(server->map->squares[x][y].linemate));
// 	strcat(server->buff, " ");
// 	strcat(server->buff, ft_itoa(server->map->squares[x][y].deraumere));
// 	strcat(server->buff, " ");
// 	strcat(server->buff, ft_itoa(server->map->squares[x][y].sibur));
// 	strcat(server->buff, " ");
// 	strcat(server->buff, ft_itoa(server->map->squares[x][y].mendiane));
// 	strcat(server->buff, " ");
// 	strcat(server->buff, ft_itoa(server->map->squares[x][y].phiras));
// 	strcat(server->buff, " ");
// 	strcat(server->buff, ft_itoa(server->map->squares[x][y].thystame));
// 	strcat(server->buff, "\n");
// 	len = ft_strlen(server->buff);
// 	if (!(node = server->graph_list))
// 		return ;
// 	while (node)
// 	{
// 		send(node->fd, server->buff, len, 0);
// 		node = node->next;
// 	}
// }
//
// void	send_mapcontents(t_player *player, t_server *server)
// {
// 	int	i;
// 	int	j;
//
// 	i = 0;
// 	while (i < server->map->width)
// 	{
// 		j = 0;
// 		while (j < server->map->height)
// 		{
// 			send_block_contents(i, j, client, server);
// 			j++;
// 		}
// 		i++;
// 	}
// }
