#include "zappy.h"

void	send_block_contents(int x, int y, t_graphic *client, t_server *server)
{
	int		len;
	t_node	*node;

	ft_strcpy(server->buff, "bct ");
	ft_strcat(server->buff, ft_itoa(x));
	ft_strcat(server->buff, " ");
	ft_strcat(server->buff, ft_itoa(y));
	ft_strcat(server->buff, " ");
	ft_strcat(server->buff, ft_itoa(server->map->squares[x][y].food));
	ft_strcat(server->buff, " ");
	ft_strcat(server->buff, ft_itoa(server->map->squares[x][y].linemate));
	ft_strcat(server->buff, " ");
	ft_strcat(server->buff, ft_itoa(server->map->squares[x][y].deraumere));
	ft_strcat(server->buff, " ");
	ft_strcat(server->buff, ft_itoa(server->map->squares[x][y].sibur));
	ft_strcat(server->buff, " ");
	ft_strcat(server->buff, ft_itoa(server->map->squares[x][y].mendiane));
	ft_strcat(server->buff, " ");
	ft_strcat(server->buff, ft_itoa(server->map->squares[x][y].phiras));
	ft_strcat(server->buff, " ");
	ft_strcat(server->buff, ft_itoa(server->map->squares[x][y].thystame));
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

void	send_mapcontents(t_graphic *client, t_server *server)
{
	int	i;
	int	j;

	i = 0;
	while (i < server->map->width)
	{
		j = 0;
		while (j < server->map->height)
		{
			send_block_contents(i, j, client, server);
			j++;
		}
		i++;
	}
}


void	resource_drop(t_player *player, uint8_t resource, t_server *server)
{
	int		len;
	t_node	*node;

	ft_strcpy(server->buff, "pdr #");
	ft_strcat(server->buff, ft_itoa(player->fd));
	ft_strcat(server->buff, " ");
	ft_strcat(server->buff, ft_itoa(resource));
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

void	resource_pickup(t_graphic *client, t_server *server)
{
	int		len;
	t_node	*node;

	ft_strcpy(server->buff, "pgt #");
	ft_strcat(server->buff, ft_itoa(client->fd));
	ft_strcat(server->buff, " ");
	// ft_strcat(server->buff, ft_itoa(resource));
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
