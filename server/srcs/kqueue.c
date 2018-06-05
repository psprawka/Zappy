/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kqueue.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psprawka <psprawka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/04 14:55:47 by psprawka          #+#    #+#             */
/*   Updated: 2018/06/04 15:32:06 by psprawka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "zappy.h"

void	check_queue(t_server *server)
{
	struct timeval	curr;
	t_node			*tmp;
	void			*content;

	if (gettimeofday(&curr, NULL) == -1)
	{
		error(6, "gettimeofday() failed", false);
		return ;
	}
	if (server->events)
		tmp = server->events->first;
	while (tmp)
	{
		if (((t_event *)tmp->content)->delaytime.tv_usec >= curr.tv_usec)
		{
			tmp = tmp->next;
			if (!(content = ft_depqueue(server->events)))
				error(6, "Failed to ft_depqueue", false);
			((t_event *)content)->fct(((t_event *)content)->player, server);
			free(content);
		}
		break ;
	}
}

int	    init_kqueue(int server_fd, t_server *server)
{
	int 			kfd;
	struct kevent	evSet;

	if ((kfd = kqueue()) == -1)
		return (EXIT_FAILURE);
	server->socket_fd = server_fd;
	EV_SET(&evSet, server_fd, EVFILT_READ, EV_ADD | EV_EOF, 0, 0, NULL);
	if (kevent(kfd, &evSet, 1, NULL, 0, NULL) == -1 || evSet.flags & EV_ERROR)
	{
		printf("Error: \"%s\"\n", strerror(errno));
		return (EXIT_FAILURE);
	}
	ft_bzero(&evSet, sizeof(struct kevent));
	EV_SET(&evSet, -1, EVFILT_TIMER, EV_ADD, NOTE_USECONDS, server->time.tv_usec, NULL);
	printf("%d microseconds\n", server->time.tv_usec);
	if (kevent(kfd, &evSet, 1, NULL, 0, NULL) == -1 || evSet.flags & EV_ERROR)
	{
		printf("Error: \"%s\"\n", strerror(errno));
		return (EXIT_FAILURE);
	}
	server->kfd = kfd;
	return (EXIT_SUCCESS);
}
