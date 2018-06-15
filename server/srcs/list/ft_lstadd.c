/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-huu- <tle-huu-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/24 17:37:14 by tle-huu-          #+#    #+#             */
/*   Updated: 2018/06/14 12:18:08 by tle-huu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

void	ft_lstadd(t_list **alst, t_list *new)
{
	if (alst)
	{
		if (!new)
			return ;
		new->next = *alst;
		*alst = new;
	}
}

void	ft_lstadd_end(t_list **alst, t_list *new)
{
	t_list	*tmp;

	if (alst)
	{
		if (!new)
			return ;
		if (!(tmp = *alst))
		{
			*alst = new;
			return ;
		}
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
	}
}
