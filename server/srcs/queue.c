/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-huu- <tle-huu-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/17 11:48:49 by tle-huu-          #+#    #+#             */
/*   Updated: 2018/06/14 12:19:15 by tle-huu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "queue.h"

t_queue			*new_queue(void)
{
	t_queue		*queue;

	if (!(queue = (t_queue *)ft_memalloc(sizeof(t_queue))))
	{
		printf("Error malloc new queue\n");
		return (NULL);
	}
	queue->head = NULL;
	queue->tail = NULL;
	return (queue);
}

void			enqueue(t_queue *queue, t_list *node)
{
	if (queue && node)
	{
		if (!(queue->head))
		{
			queue->head = node;
			queue->tail = node;
		}
		else if (!((queue->head)->next))
		{
			queue->tail = node;
			queue->head->next = queue->tail;
		}
		else
		{
			queue->tail->next = node;
			queue->tail = node;
		}
	}
	else
		printf("No queue pointer or NULL node in trying to enqueuing\n");
}

t_list			*queue_pop(t_queue *queue)
{
	t_list		*head;

	if (queue && queue->head)
	{
		head = queue->head;
		queue->head = head->next;
		if (!head->next)
			queue->tail = NULL;
		return (head);
	}
	printf("Error while poping\n");
	return (NULL);
}

int				queue_empty(t_queue *queue)
{
	if (queue)
		return (!(queue->head));
	printf("Error queue pointer null\n");
	return (-2);
}
