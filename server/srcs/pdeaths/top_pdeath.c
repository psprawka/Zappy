/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   top_pdeath.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psprawka <psprawka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/13 20:13:18 by psprawka          #+#    #+#             */
/*   Updated: 2018/06/13 21:04:12 by psprawka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "zappy.h"

struct timeval	*top_pdeath(t_pdeath *head)
{
	if (head)
		return (head->death_time);
	return (NULL);	
}

