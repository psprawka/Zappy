/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generator.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psprawka <psprawka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/02 01:46:46 by psprawka          #+#    #+#             */
/*   Updated: 2018/06/19 08:26:51 by psprawka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "zappy.h"

void		generate_ressource(int ressource)
{
	int		x;
	int		y;

	if (ressource < 0 || ressource > 6)
	{
		printf("Coder, you are retarded (generate ressource)\n");
		return ;
	}
	x = rand() % g_server.map->width;
	y = rand() % g_server.map->height;
	((g_server.map->squares[x][y])->ressources[ressource])++;
}