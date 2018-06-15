/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eggqueue.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-huu- <tle-huu-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/14 11:21:00 by tle-huu-          #+#    #+#             */
/*   Updated: 2018/06/14 12:39:35 by tle-huu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "zappy.h"

t_egg		*new_egg(t_team *team, int x, int y)
{
	t_egg		*egg;

	if (!(egg = (t_egg *)ft_memalloc(sizeof(t_egg))))
		return (NULL);
	if (!team)
		return (NULL);
	egg->team = team;
	egg->x = x;
	egg->y = y;
	return (egg);
}
