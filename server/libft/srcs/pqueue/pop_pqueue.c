/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pop_pqueue.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psprawka <psprawka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/12 09:21:31 by psprawka          #+#    #+#             */
/*   Updated: 2018/06/12 09:27:42 by psprawka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_pqueue	*pop_pqueue(t_pqueue **head)
{
	t_pqueue *tmp;

	if (!(*head))
		return (NULL);

	tmp = *head;
	*head = (*head)->next;
	return (tmp);
}
