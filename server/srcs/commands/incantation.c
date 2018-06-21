/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   incantation.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psprawka <psprawka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/29 21:50:35 by psprawka          #+#    #+#             */
/*   Updated: 2018/06/21 05:28:29 by psprawka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "zappy.h"

t_level		g_level[] =
{
	{0, 0, {0, 0, 0, 0, 0, 0, 0}},
	{1, 1, {0, 1, 0, 0, 0, 0, 0}},
	{2, 2, {0, 1, 1, 1, 0, 0, 0}},
	{3, 2, {0, 2, 0, 1, 0, 2, 0}},
	{4, 4, {0, 1, 1, 2, 0, 1, 0}},
	{5, 4, {0, 1, 2, 1, 3, 0, 0}},
	{6, 6, {0, 1, 2, 3, 0, 1, 0}},
	{7, 6, {0, 2, 2, 2, 2, 2, 1}},
	{0, 0, {0, 0, 0, 0, 0, 0, 0}},
};

static int	require_players(void *entity, int *players_required)
{
	int		i;
	int		itable;

	i = 0;
	itable = 0;
	while (i < FD_SETSIZE)
	{
		if (g_client_type[i] == T_PLAYER &&
			((t_player *)g_entity[i])->level == P_ENTITY->level  &&
			((t_player *)g_entity[i])->x == P_ENTITY->x &&
			((t_player *)g_entity[i])->y == P_ENTITY->y &&
			((t_player *)g_entity[i])->incantation == false)
			players_required[itable++] = i;
		i++;
	}
	return (itable >= g_level[P_ENTITY->level].players_nb ? EXIT_SUCCESS : EXIT_FAILURE);
}

// static int	require_resources(void *entity, int *players_required)
// {
// 	int		itable;
// 	int		iresource;
// 	int		allowed_players;
// 	t_level	level;

// 	itable = 0;
// 	level = g_level[P_ENTITY->level];
// 	allowed_players = 0;
// 	while (itable < MAX_INCANTATION)
// 	{
// 		iresource = 0;
// 		while (players_required[itable] && iresource < 7)
// 		{
// 			if (((t_player *)g_entity[players_required[itable]])->inventory[iresource] < level.resources[iresource])
// 			{
// 				players_required[itable] = 0;
// 				break ;
// 			}
// 			iresource++;
// 		}
// 		allowed_players++;
// 		itable++;
// 	}
// 	return (allowed_players < level.players_nb ? EXIT_FAILURE : EXIT_SUCCESS);
// }

int		command_incantation(void *entity, char *msg)
{
	int		players_required[MAX_INCANTATION];
	int		i;

	i = 0;
    printf("%sPlayer [%d] -> [incantation]%s\n", CYAN, P_ENTITY->fd, NORMAL);
	ft_bzero(players_required, sizeof(players_required));
	if (send(P_ENTITY->fd, MSG_EVALUATION, ft_strlen(MSG_EVALUATION), 0) < 0 ||
		P_ENTITY->level > 7 ||
		require_players(entity, players_required) == EXIT_FAILURE)// ||
		// require_resources(entity, players_required) == EXIT_FAILURE)
		{
			ft_strcpy(g_server.buff, "current level: ");
			ft_strcat(g_server.buff, ft_itoa(P_ENTITY->level));
			ft_strcat(g_server.buff, "\n");
			if (send(P_ENTITY->fd, g_server.buff, ft_strlen(g_server.buff), 0) == -1)
				error(0, "Send [incantation]", true);
			return (EXIT_FAILURE);
		}
	while (i < MAX_INCANTATION)
	{
		if (players_required[i])
		{
			if (players_required[i] == P_ENTITY->fd)
				add_event(g_entity[players_required[i]], T_PLAYER, 15, "levelup");
			else
				add_event(g_entity[players_required[i]], T_NONDEF, 15, "levelup");
			((t_player *)g_entity[players_required[i]])->requests_nb++;
			((t_player *)g_entity[players_required[i]])->incantation = true;
		}
		i++;
	}
	notify_start_incantation(P_ENTITY);
	return (EXIT_FAILURE);
}