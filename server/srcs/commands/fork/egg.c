/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   egg.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psprawka <psprawka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/16 12:25:34 by tle-huu-          #+#    #+#             */
/*   Updated: 2018/06/21 05:31:52 by psprawka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "zappy.h"

static t_egg	*new_egg(t_player *player)
{
	t_egg		*egg;

	egg = NULL;
	if (!player || !(egg = ft_memalloc(sizeof(t_egg))))
		return (NULL);
	egg->team = player->team;
	egg->x = player->x;
	egg->y = player->y;
	egg->hatched = 0;
	egg->father_fd = player->fd;
	egg->number = g_server.number_egg + 1;
	g_server.number_egg++;
	return (egg);
}

static int		add_egg_team(t_egg *egg, t_team *team)
{
	t_node		*node;

	if (!team || !egg)
		return (EXIT_FAILURE);
	if (!team->egg_queue)
		team->egg_queue = ft_init_queue();
	node = ft_init_node(egg, sizeof(egg));
	ft_push_queue(&(team->egg_queue), node);
	return (EXIT_SUCCESS);
}

int				handle_egg(t_player *player)
{
	t_egg		*egg;

	if (!player || !(egg = new_egg(player)))
		return (EXIT_FAILURE);
	if (add_egg_team(egg, player->team) ||
		add_event(egg, T_EGG, 12, "hatch") ||
		add_event(egg, T_EGG, 14, "egg_death"))
		return (EXIT_FAILURE);
	notify_egg_laid(player, egg);
	return (EXIT_SUCCESS);
}
