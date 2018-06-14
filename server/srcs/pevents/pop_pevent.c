/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pop_pevent.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psprawka <psprawka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/12 14:11:54 by psprawka          #+#    #+#             */
/*   Updated: 2018/06/13 20:08:07 by psprawka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "zappy.h"

t_pevent	*pop_pevent(t_pevent **head)
{
	t_pevent *tmp;

	if (!(*head))
		return (NULL);

	tmp = *head;
	*head = (*head)->next;
	return (tmp);
}
