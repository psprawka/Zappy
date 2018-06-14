/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zappy_graphic_queue.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-huu- <tle-huu-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/13 16:20:32 by tle-huu-          #+#    #+#             */
/*   Updated: 2018/06/13 16:25:04 by tle-huu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZAPPY_GRAPHIC_QUEUE_H
# define ZAPPY_GRAPHIC_QUEUE_H


typedef struct		s_graphic_list
{
	int				fd;
	struct s_list	*next;
}					t_graphic_list;



t_graphic_list		*glist_new(int fd);
void				glist_add(t_graphic_list **alst, t_graphic_list *nw);
void				glist_add_end(t_graphic_list **alst, t_graphic_list *nw);
int					glist_length(t_graphic_list *list);
