/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-huu- <tle-huu-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/17 11:49:17 by tle-huu-          #+#    #+#             */
/*   Updated: 2018/06/14 12:35:28 by tle-huu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef QUEUE_H
# define QUEUE_H

# include "list.h"
# include <stdlib.h>

typedef struct		s_queue
{
	t_list		*head;
	t_list		*tail;
}					t_queue;

t_queue				*new_queue(void);
void				enqueue(t_queue *queue, t_list *node);
t_list				*queue_pop(t_queue *queue);
int					queue_empty(t_queue *queue);

#endif
