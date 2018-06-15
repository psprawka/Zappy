/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_pdeath.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psprawka <psprawka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/13 20:13:08 by psprawka          #+#    #+#             */
/*   Updated: 2018/06/14 13:15:51 by tle-huu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "zappy.h"

t_pdeath	*create_pdeath(void *object, struct timeval *death_time)
{
	t_pdeath *new;

	if (!object || !(new = ft_memalloc(sizeof(t_pdeath))))
	{
		error(0, "Create pdeath", true);
		return (NULL);
	}
	new->object = object;
	new->death_time = death_time;
	new->next = NULL;
	return (new);
}

int			push_pdeath(t_pdeath **head, void *object, struct timeval *death_time)
{
	t_pdeath	*tmp;
	t_pdeath	*new;

	if (!(new = create_pdeath(object, death_time)))
		return (EXIT_FAILURE);
	if (!(*head) || time_compare((*head)->death_time, new->death_time))
	{
		new->next = *head;
		*head = new;
	}
	else
	{
		tmp = *head;
		while (tmp->next && !(time_compare((*head)->death_time, new->death_time)))
			tmp = tmp->next;
		new->next = tmp->next;
		tmp->next = new;
	}
	return (EXIT_SUCCESS);
}
