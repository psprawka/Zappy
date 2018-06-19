/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psprawka <psprawka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/29 21:54:33 by psprawka          #+#    #+#             */
/*   Updated: 2018/06/19 03:40:23 by psprawka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "zappy.h"

int		command_fork(void *entity, char *msg)
{
	printf("%sPlayer [%d] -> [fork]%s\n", CYAN, P_ENTITY->fd, NORMAL);
	handle_egg(entity);
	if (send(P_ENTITY->fd, MSG_OK, ft_strlen(MSG_OK), 0) == -1)
		return (error(0, "Send [fork]", false));
	P_ENTITY->requests_nb--;
	return (EXIT_SUCCESS);
}
