/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   top_pevent.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psprawka <psprawka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/13 17:22:54 by psprawka          #+#    #+#             */
/*   Updated: 2018/06/13 20:39:10 by psprawka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "zappy.h"

struct timeval	*top_pevent(t_pevent *head)
{
	if (head)
		return (head->event_time);
	return (NULL);	
}
