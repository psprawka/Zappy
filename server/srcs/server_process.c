/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_process.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psprawka <psprawka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/20 17:26:09 by psprawka          #+#    #+#             */
/*   Updated: 2018/05/26 19:11:17 by psprawka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "zappy_server.h"




void	process_data(int currfd, int sockfd, fd_set *client_fds)
{
	int		ret;
	char	buff[BUFF_SIZE];
	int 	i;

	if ((ret = recv(currfd, buff, BUFF_SIZE, 0)) > 0)
	{
		i = 0;
		while (i < FD_SETSIZE)
		{
			if (FD_ISSET(i, client_fds))
			{
				if (i != sockfd)
				{
					if (send(i, buff, ret, 0) == -1)
							ft_printf("Sending unsuccessful\n");
					
				}
			}
			i++;
		}
		ft_bzero(buff, BUFF_SIZE);
	}
	else
	{
		ret == 0 ? ft_printf("Player [%d] quit\n", currfd) : ft_printf("Error recv\n");
		FD_CLR(currfd, client_fds);
		close(currfd);
	}
}