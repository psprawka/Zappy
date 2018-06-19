/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calcul_square.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psprawka <psprawka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/13 22:08:23 by tle-huu-          #+#    #+#             */
/*   Updated: 2018/06/19 02:45:26 by psprawka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "zappy.h"

static int	absol(int a)
{
	return (a < 0 ? -a : a);
}

int			calcul_square(t_vector *direction)
{
	int		square;
	int		x;
	int		y;

	x = direction->x;
	y = direction->y;
	if (!x && !y)
		return (0);
	else if (x >= 0 && x == y)
		return (8);
	else if ((x >= 0 && y >= 0 && y > x) || (x <= 0 && y >= 0 && absol(y) > absol(x)))
		return (1);
	else if ((x >= 0 && y >= 0 && y < x) || (x >= 0 && y <= 0 && absol(x) > absol(y)))
		return (7);
	else if ((x >= 0 && y <= 0 && absol(y) > absol(x)) || (x <= 0 && y <= 0 && absol(y) > absol(x)))
		return (5);
	else if (x >= 0 && y <= 0 && absol(y) == absol(x))
		return (6);
	else if (x <= 0 && y <= 0 && absol(y) == absol(x))
		return (4);
	else if (x <= 0 && y >= 0 && absol(y) == absol(x))
		return (2);
	else if ((x <= 0 && y <= 0 && absol(y) < absol(x)) || (x <= 0 && y >= 0 && absol(x) > absol(y)))
		return (3);
	else
		return (-1);
	return (EXIT_SUCCESS);
}
