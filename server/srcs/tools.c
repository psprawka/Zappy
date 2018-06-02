/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asyed <asyed@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/31 13:23:45 by psprawka          #+#    #+#             */
/*   Updated: 2018/06/02 16:08:29 by asyed            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "zappy.h"

void	tools_world_dimensions(t_player *player, t_server *server)
{
	char	*msg;
	char	*tmp;

	if (!(tmp = ft_strjoin(ft_itoa(server->map->width), " ", 0)))
		return ;
	if (!(msg = ft_strjoin(tmp, ft_itoa(server->map->height), 0)))
	{
		free(tmp);
		return ;
	}
	send(player->fd, msg, ft_strlen(msg), 0);
	free(msg);
	free(tmp);
}
