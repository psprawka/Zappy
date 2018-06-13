/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   top_pqueue.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psprawka <psprawka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/12 09:22:42 by psprawka          #+#    #+#             */
/*   Updated: 2018/06/12 09:27:59 by psprawka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*top_pqueue(t_pqueue *head)
{
	return (head ? head->data : NULL);
}