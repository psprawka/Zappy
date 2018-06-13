/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_pnode.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psprawka <psprawka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/12 09:23:23 by psprawka          #+#    #+#             */
/*   Updated: 2018/06/12 09:27:37 by psprawka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		free_pnode(t_pqueue *pnode)
{
	if (!pnode)
		return ;
	if (pnode->data)
		free(pnode->data);
	free(pnode);
}
