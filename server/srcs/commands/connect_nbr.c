/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   connect_nbr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asyed <asyed@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/29 21:51:06 by psprawka          #+#    #+#             */
/*   Updated: 2018/06/02 20:44:27 by asyed            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "zappy.h"

int		command_connect_nbr(t_player *player, t_server *serv)
{
	char	*msg;
	char	*tmp;

	if (!(tmp = ft_itoa(6 - player->team->players)))
		return (EXIT_FAILURE);
	if (!(msg = ft_strjoin(tmp, "\n", false)))
	{
		free(tmp);
		return (EXIT_FAILURE);
	}
	send(player->fd, msg, ft_strlen(msg), 0);
	free(msg);
	free(tmp);
	return (EXIT_SUCCESS);
}
