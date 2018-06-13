/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_pnode.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psprawka <psprawka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/12 09:24:05 by psprawka          #+#    #+#             */
/*   Updated: 2018/06/13 15:31:01 by psprawka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_pqueue	*create_pnode(void *data, int priority)
{
	t_pqueue *new;

	if (!(new = ft_memalloc(sizeof(t_pqueue))))
		return (NULL);
	new->data = data;
	new->priority = priority;
	new->next = NULL;
	return (new);
}
