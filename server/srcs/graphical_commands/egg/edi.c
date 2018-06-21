/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   edi.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psprawka <psprawka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/16 18:01:33 by tle-huu-          #+#    #+#             */
/*   Updated: 2018/06/21 06:02:38 by psprawka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "zappy.h"

void	notify_starve_egg(t_egg *egg)
{
	strcpy(g_server.buff, "edi ");
	strcat(g_server.buff, ft_itoa(egg->number));
	strcat(g_server.buff, "\n");
	if (notify_graphics(0) == EXIT_FAILURE)
		error(0, "Send [g: edi]", true);
}
