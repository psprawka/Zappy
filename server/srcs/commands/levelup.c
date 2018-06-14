/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   levelup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psprawka <psprawka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/29 21:50:35 by psprawka          #+#    #+#             */
/*   Updated: 2018/06/14 11:05:40 by tle-huu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "zappy.h"

int		command_levelup(t_player *player, t_server *serv, t_action_arg *arg)
{
	int		len;

	printf("Player %d might level up\n", player->fd);
	if (player->level < 8 && player->level > 0)
	{
		printf("%d -> %d\n", player->level, player->level + 1);
		player->level++;
		strcpy(serv->buff, "current level : ");
		strcat(serv->buff, ft_itoa(player->level));
		len = strlen(serv->buff + 1);
		send(player->fd, serv->buff, len, 0);
		return (EXIT_SUCCESS);
	}
	printf("Error level up\n");
	arg = (void *)arg;
	return (EXIT_FAILURE);
}

//not even started
