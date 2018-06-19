/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psprawka <psprawka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/20 17:26:09 by psprawka          #+#    #+#             */
/*   Updated: 2018/06/19 03:49:55 by psprawka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "zappy.h"

/*
**	Function handle_recv gets a message and first it checks if recv is valid
**	(grater than 0). If recv is:
**	-> valid - function goes to if statement and determines where to parse
**		a message based on client's type (NONDEF is notdefined, PLAYER is AI
**		and GRAPHIC is GUI) and then executes this function;
**	-> invalid - function goes to else part. There it checks value of recv
**		message: if (ret == 0) client quit, otherwise error occured and
**		error messgae is sent.
*/

int		handle_recv(int fd)
{
	int		ret;
	char	buff[RECV_BUFF_SIZE];

	if ((ret = recv(fd, buff, RECV_BUFF_SIZE, 0)) > 0)
	{
		buff[ret] = '\0';
		if (buff[ret - 1] == '\n')
			buff[ret - 1] = '\0';
		if (g_client_type[fd] == T_NONDEF)
			handle_nondef(fd, buff);
		else if (g_client_type[fd] == T_PLAYER)
			handle_ai(fd, buff);
		else if (g_client_type[fd] == T_GRAPHIC)
			handle_graphic(fd, buff);
	}
	else
		ret == 0 ? client_death(fd) : error(0, "Ret [handle_recv]", false);
	return (EXIT_SUCCESS);
}
