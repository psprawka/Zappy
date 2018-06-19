/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   suc.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-huu- <tle-huu-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/13 17:49:53 by tle-huu-          #+#    #+#             */
/*   Updated: 2018/06/18 00:35:19 by tle-huu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "zappy.h"

void			unknown_command(int fd)
{
	int				len;

	strcpy(g_server.buff, "suc");
	strcat(g_server.buff, "\n");
	len = ft_strlen(g_server.buff);
	send(fd, g_server.buff, len, 0);
}
