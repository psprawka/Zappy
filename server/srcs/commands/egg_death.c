/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   egg_death.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psprawka <psprawka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/17 08:09:30 by psprawka          #+#    #+#             */
/*   Updated: 2018/06/21 05:34:27 by psprawka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "zappy.h"

int		command_egg_death(void *entity, char *msg)
{
	t_node	*prev_egg_node;
	t_node	*egg_node;
	t_egg	*egg;

	if (!entity)
		return (EXIT_FAILURE);
	egg_node = E_ENTITY->team->egg_queue->first;
	prev_egg_node = NULL;
	while (egg_node)
	{
		egg = (t_egg *)egg_node->data;
		if (egg && egg == entity)
		{
			notify_starve_egg(egg);
			E_ENTITY->team->allowed_eggs--;
			remove_node(&E_ENTITY->team->egg_queue, prev_egg_node, egg_node);
			return (EXIT_SUCCESS);
		}
		prev_egg_node = egg_node;
		egg_node = egg_node->next;
	}
	return (EXIT_SUCCESS);
}
