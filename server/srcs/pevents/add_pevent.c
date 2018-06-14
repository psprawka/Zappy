/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_pevent.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psprawka <psprawka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/12 13:55:59 by psprawka          #+#    #+#             */
/*   Updated: 2018/06/13 20:53:41 by psprawka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "zappy.h"

void		print_pevent(t_pevent *head)
{
	int			i;
	t_pevent	*tmp;

	i = 1;
	tmp = head;
	ft_printf("\n%s", YELLOW);
	while (tmp)
	{
		ft_printf("%d. player: [%d], message: [%s]\n",
			i++, tmp->player->fd, tmp->msg);
		tmp = tmp->next;
	}
	ft_printf("%s\n", NORMAL);
}

int		add_pevent(t_server *serv, t_player *player, int itable, char *msg)
{
	struct timeval	*last_request;
	struct timeval	curr;
	t_pevent		*new;

	if (gettimeofday(&(curr), NULL) == EXIT_FAILURE)
		return (error(0, "Gettimeofday", true));
	
	last_request = &player->last_request;
	
	if (!last_request || !time_compare(last_request, &curr))
		last_request = &curr;
	
	last_request->tv_sec += g_commands[itable].delay * serv->time.tv_sec;
	last_request->tv_usec += g_commands[itable].delay * serv->time.tv_usec;
	
	if (!(new = create_pevent(player, last_request, itable, msg)))
		return (EXIT_FAILURE);
	
	if (player->requests_nb == MAX_REQUEST_NB ||
		push_pevent(&(serv->events), new))
		return (EXIT_FAILURE);
	
	print_pevent(serv->events);
	return (EXIT_SUCCESS);
}