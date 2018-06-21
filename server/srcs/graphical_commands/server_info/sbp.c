/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sbp.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psprawka <psprawka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/13 17:49:53 by tle-huu-          #+#    #+#             */
/*   Updated: 2018/06/21 06:06:20 by psprawka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "zappy.h"

void	notify_unknown_parameter(void)
{
	strcpy(g_server.buff, "sbp");
	strcat(g_server.buff, "\n");
	if (notify_graphics(0) == EXIT_FAILURE)
		error(0, "Send [g: sbp]", true);
}
