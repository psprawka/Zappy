/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphical.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psprawka <psprawka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/07 16:55:24 by asyed             #+#    #+#             */
/*   Updated: 2018/06/13 15:17:56 by psprawka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "zappy.h"

int		if_graphical(t_server *server, t_player *player, char *msg)
{
	if (player->type == T_NONDEF && ft_strcmp(msg, "GRAPHICAL\n"))
		return (EXIT_FAILURE);

	if (player->type == T_NONDEF)
	{
		
		return (EXIT_SUCCESS);
	}

	
}