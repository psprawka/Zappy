/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_in_buffer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psprawka <psprawka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/17 19:16:15 by tle-huu-          #+#    #+#             */
/*   Updated: 2018/06/19 00:05:36 by psprawka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "zappy.h"

void		put_player_buffer(int nbr_players, int *first)
{
	int		i;

	i = 0;
	while (i < nbr_players)
	{
		if (*first)
			strcat(g_server.buff, " ");
		*first = 1;
		strcat(g_server.buff, "player");
		i++;
	}
}

void		put_ressources_buffer(t_square *square, int nbr_players, int first)
{
	int		i;
	int		k;

	k = 0;
	while (g_ressources[k])
	{
		i = 0;
		while (i < square->ressources[k])
		{
			if (first)
				strcat(g_server.buff, " ");
			else
				first = 1;
			strcat(g_server.buff, g_ressources[k]);
			i++;
		}
		k++;
	}
}
