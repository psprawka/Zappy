/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-huu- <tle-huu-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/17 11:49:17 by tle-huu-          #+#    #+#             */
/*   Updated: 2018/06/14 12:38:59 by tle-huu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef list_H
# define list_H

# include "libft.h"
# include <string.h>
# include <stdio.h>

typedef struct		s_list
{
	void			*content;
	long long int	content_size;
	struct s_list	*next;
}					t_list;

void				ft_lstadd(t_list **alst, t_list *nw);
void				ft_lstadd_end(t_list **alst, t_list *new);
int					ft_lstlength(t_list *list);
t_list				*ft_lstnew(void const *content, long long int content_size);
t_list				*ft_lst_pop(t_list **list);

#endif
