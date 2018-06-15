/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psprawka <psprawka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/13 17:32:33 by psprawka          #+#    #+#             */
/*   Updated: 2018/06/13 20:47:11 by psprawka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "zappy.h"

//0 if first is less
//0 if theyre the same 
//1 if first is bigger

int		time_compare(struct timeval *first, struct timeval *second)
{
	if (first->tv_sec != second->tv_sec)
		return (first->tv_sec > second->tv_sec);
	
	return (first->tv_usec > second->tv_usec);
}

