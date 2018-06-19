/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zappy_define.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psprawka <psprawka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/15 03:47:42 by psprawka          #+#    #+#             */
/*   Updated: 2018/06/18 03:51:28 by psprawka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef ZAPPY_DEFINE_H
# define ZAPPY_DEFINE_H

# define	SERV_BUFF_SIZE	2048
# define	RECV_BUFF_SIZE	512

# define	MSG_WELCOME		"WELCOME\n"
# define	MSG_NOCOMMAND	"This command doesn't exist!\n"
# define	MSG_FULLTEAM	"0\n"
# define	MSG_NOTEAM		"This team doesn't exist. Reenter your team name.\n"
# define	MSG_OK			"ok\n"
# define	MSG_KO			"ko\n"
# define	MSG_DEATH		"death\n"
# define	MSG_EVALUATION	"evaluation in progress\n"

# define 	T_NONDEF		0
# define 	T_PLAYER		1
# define 	T_GRAPHIC		2
# define	T_EGG			3

# define	P_ENTITY		((t_player *)entity)
# define	G_ENTITY		((t_gui *)entity) // however to store it // i dont think we need it 
# define	E_ENTITY		((t_egg *)entity)

# define	MAX_REQUEST_NB	10
# define	MAX_INCANTATION	10

# define	NORTH			1
# define	EAST			2
# define	SOUTH			4
# define	WEST			8

# define	FOOD			0
# define	LINEMATE		1
# define	DERAUMERE		2
# define	SIBUR			3
# define	MENDIANE		4
# define	PHIRAS			5
# define	THYSTAME		6

#endif
