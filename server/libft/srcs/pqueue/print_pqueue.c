/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_pqueue.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psprawka <psprawka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/12 09:22:13 by psprawka          #+#    #+#             */
/*   Updated: 2018/06/12 11:47:36 by psprawka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		print_pqueue(t_pqueue *head)
{
	int			i;
	t_pqueue	*tmp;

	i = 1;
	tmp = head;
	ft_printf("\n%s", YELLOW);
	while (tmp)
	{
		ft_printf("%d. p: [%d], D: [%s]\n", i++, tmp->priority, tmp->data);
		tmp = tmp->next;
	}
	ft_printf("%s\n", NORMAL);
}
