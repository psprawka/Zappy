/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   broadcast.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psprawka <psprawka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/29 18:04:46 by psprawka          #+#    #+#             */
/*   Updated: 2018/06/01 23:39:07 by psprawka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//something similar in broadcast

// void	process_data(t_player *player, int sockfd, fd_set *client_fds)
// {
// 	int		ret;
// 	char	buff[BUFF_SIZE];
// 	int 	i;

// 	if ((ret = recv(player->fd, buff, BUFF_SIZE, 0)) > 0)
// 	{
// 		i = 0;
// 		while (i < FD_SETSIZE)
// 		{
// 			if (FD_ISSET(i, client_fds))
// 			{
// 				if (i != sockfd)
// 				{
// 					if (send(i, buff, ret, 0) == -1)
// 							ft_printf("Sending unsuccessful\n");
					
// 				}
// 			}
// 			i++;
// 		}
// 		ft_bzero(buff, BUFF_SIZE);
// 	}
// 	}
// }
#include "zappy.h"

int		command_broadcast(t_player *player, t_server *serv)
{
	ft_printf("broadcast!\n");
	return (1);
}