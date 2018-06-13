/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psprawka <psprawka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/13 15:25:38 by psprawka          #+#    #+#             */
/*   Updated: 2018/06/13 15:45:55 by psprawka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "zappy.h"

// t_node	*create_node(int graphicfd)
// {
// 	t_node *new;

// 	if (!(new = ft_memalloc(sizeof(t_node))))
// 		return (NULL);
// 	new->fd = graphicfd;
// 	new->next = NULL;
// 	return (new);
// }

// t_queue	*create_queue(void)
// {
// 	t_queue *queue;

// 	if (!(new = ft_memalloc(sizeof(t_queue))))
// 		return (NULL);
// 	queue->first = NULL;
// 	queue->last = NULL;
// 	return (queue);
// }

// int		push_queue(t_queue **head, int graphicfd)
// {
// 	t_queue	*tmp;
// 		*new;

// 	if (!(new = create_node(graphicfd)))
// 		return (EXIT_FAILURE);
	 
// 	if (!(*head))
// 		*head = new;
// 	else
// 	{
// 		tmp = *head;
// 		while (tmp->next)
// 			tmp = tmp->next;
// 		tmp->next = new;
// 	}
// 	return (EXIT_SUCCESS);
// }

// t_queue	*pop_queue(t_queue **head)
// {
// 	t_queue *tmp;

// 	if (!(*head))
// 		return (NULL);

// 	tmp = *head;
// 	*head = (*head)->next;
// 	return (tmp);
// }

// void		print_queue(t_queue *head)
// {
// 	int		i;
// 	t_queue	*tmp;

// 	i = 1;
// 	tmp = head;
// 	ft_printf("\n%s", YELLOW);
// 	while (tmp)
// 	{
// 		ft_printf("%d. k: [%d]\n", i++, tmp->fd);
// 		tmp = tmp->next;
// 	}
// 	ft_printf("%s\n", NORMAL);
// }


