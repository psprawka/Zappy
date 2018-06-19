/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psprawka <psprawka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/15 05:34:17 by psprawka          #+#    #+#             */
/*   Updated: 2018/06/16 04:48:12 by psprawka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <stdio.h>
# include <sys/socket.h>
# include <netinet/in.h>
# include <netdb.h>
# include <arpa/inet.h>
# include <string.h>
# include <stdbool.h>
# include <sys/time.h>
# include <errno.h>
# include <term.h>
# include <curses.h>
# include "../../includes/libft.h"
# include <string.h>

# define NORMAL			"\x1B[0m"
# define RED			"\x1B[31m"
# define GREEN			"\x1B[32m"
# define YELLOW			"\x1B[33m"
# define BLUE			"\x1B[34m"
# define MAGNETA		"\x1B[35m"
# define CYAN			"\x1B[36m"
# define PINK			"\033[38;5;200m"
# define ORANGE			"\033[38;5;208m"
# define PURPLE			"\033[38;5;55m"
# define MAROON			"\033[38;5;88m"
# define GREY			"\033[38;5;246m"

typedef struct	s_node
{
	void			*data;
	size_t			dsize;
	struct s_node	*next;
	
}				t_node;

typedef struct	s_queue
{
	t_node		*first;
	t_node		*last;
	
}				t_queue;

typedef struct	s_event
{
	struct timeval		*event_time;
	char				*msg;
}				t_event;


// ---------- help ---------

// void	*ft_memdup(void *mem, int size)
// { 
// 	void	*out = malloc(size);

// 	if (out != NULL)
// 		memcpy(out, mem, size);
// 	return (out);
// }

// void	*ft_memalloc(size_t size)
// {
// 	void	*new;

// 	if (!(new = (void *)malloc(size)))
// 		return (NULL);
// 	memset(new, '\0', size);
// 	return (new);
// }


// // ---------- event ------------

// struct timeval	*rand_time(void)
// {
// 	struct timeval	*ret;

// 	ret = ft_memalloc(sizeof(struct timeval));
// 	ret->tv_sec = rand() % 10;
// 	ret->tv_usec = rand() % 1000;
// 	return (ret);
// }

// int		time_compare_event(t_node *first, t_node *second)
// {
// 	t_event		*first_event;
// 	t_event		*second_event;

// 	first_event = (t_event *)first->data;
// 	second_event = (t_event *)second->data;

// 	if (first_event->event_time->tv_sec != second_event->event_time->tv_sec)
// 		return (first_event->event_time->tv_sec > second_event->event_time->tv_sec);
// 	return (first_event->event_time->tv_usec > second_event->event_time->tv_usec);
// }

// t_event		*create_event(struct timeval *time, char *msg)
// {
// 	t_event	*new;

// 	if (!(new = ft_memalloc(sizeof(t_event))))
// 		return (NULL);

// 	new->event_time = time;
// 	new->msg = strdup(msg);
// 	return (new);
// }


// ---------- node ------------

// t_node		*init_node(void *data, size_t dsize)
// {
// 	t_node	*new;

// 	if (!(new = ft_memalloc(sizeof(t_node))))
// 		return (NULL);

// 	new->data = data;
// 	new->dsize = dsize;
// 	new->next = NULL;
// 	return (new);
// }

// ---------- queue create ------------

// t_queue		*init_queue(void)
// {
// 	t_queue *queue;

// 	if (!(queue = ft_memalloc(sizeof(t_queue))))
// 		return (NULL);
// 	queue->first = NULL;
// 	queue->last = NULL;
// 	return (queue);
// }

// ---------- queue actions ------------

// void		*top_queue(t_queue *head)
// {
// 	if (head && head->first)
// 		return (head->first->data);
// 	return (NULL);	
// }

// t_node	*pop_queue(t_queue **queue)
// {
// 	t_node *tmp;

// 	if (!(*queue) || !(*queue)->first)
// 		return (NULL);

// 	tmp = (*queue)->first;
// 	(*queue)->first = tmp->next;
// 	return (tmp);
// }

// void		push_pqueue(t_queue **head, t_node *new, int (*fct)(t_node *, t_node *))
// {
// 	t_node 	*tmp;
	
// 	if (!(*head) || !new)
// 		return ;
// 	tmp = (*head)->first;

// 	if (!tmp || !tmp->data || fct(tmp, new))
// 	{
// 		new->next = tmp;
// 		(*head)->first = new;
// 	}
// 	else
// 	{
// 		while (tmp->next && !(fct(tmp->next, new)))
// 			tmp = tmp->next;
// 		new->next = tmp->next;
// 		tmp->next = new;
// 	}
// 	// new->data->player->requests_nb++; // remove from here
// }
// ---------- queue print ------------

// void		print_queue(t_queue *head, char *color)
// {
// 	int		i;
// 	t_node	*tmp;
// 	t_event *event;

// 	i = 1;
// 	if (!head)
// 		return ;
// 	tmp = head->first;
// 	printf("\n%s", color);
// 	while (tmp)
// 	{
// 		event = (t_event *)tmp->data;
// 		if (event)
// 			printf("%d. message: [%s] ", i++, event->msg);
// 		if (event && event->event_time)
// 			printf("time: [%lu][%d]", event->event_time->tv_sec, event->event_time->tv_usec);
// 		printf("\n");
// 		tmp = tmp->next;
// 	}
// 	printf("%s\n", NORMAL);
// }

// void	add_queue(t_queue *myqueue, char *msg)
// {
// 	static int i = 1;
	
// 	t_event	*event;
// 	t_node 	*node;
	
// 	printf("pushing...");
// 	event = create_event(rand_time(), msg);
// 	node = create_node(event, sizeof(t_event));
// 	push_pqueue(&myqueue, node, time_compare_event);
// 	print_queue(myqueue, ORANGE);
// }

// void	remove_queue(t_queue *myqueue)
// {
// 	printf("popping...");
// 	pop_queue(&myqueue);
// 	print_queue(myqueue, CYAN);
// }

// void	get_top(t_queue *myqueue)
// {
// 	t_event	*event;

// 	event = (t_event *)top_queue(myqueue);
// 	printf("getting the top... message [%s] time [%lu][%d]", event->msg, event->event_time->tv_sec, event->event_time->tv_usec);
// 	print_queue(myqueue, YELLOW);
// }

int main(void)
{
	t_queue	*myqueue;

	int		i = 1;

	// srand(time(NULL));
	// myqueue = create_queue();
	// add_queue(myqueue, "kick");
	// add_queue(myqueue, "see");
	// add_queue(myqueue, "inventory");
	// remove_queue(myqueue);
	// get_top(myqueue);
	// remove_queue(myqueue);
	// add_queue(myqueue, "right");
	// get_top(myqueue);
	// add_queue(myqueue, "left");
	// add_queue(myqueue, "advance");
	// remove_queue(myqueue);
	// remove_queue(myqueue);
	// add_queue(myqueue, "kick2");
	// add_queue(myqueue, "see2");
	// get_top(myqueue);
	// add_queue(myqueue, "inventory2");
	// remove_queue(myqueue);
}