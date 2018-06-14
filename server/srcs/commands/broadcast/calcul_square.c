/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calcul_square.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-huu- <tle-huu-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/13 22:08:23 by tle-huu-          #+#    #+#             */
/*   Updated: 2018/06/13 22:25:19 by tle-huu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "zappy.h"

static	int		absol(int a)
{
	return (a < 0 ? -a : a);
}

int				calcul_square(t_vector *direction)
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
	else if (x >= 0 && y >= 0 && y > x)
		return (1);
	else if (x >= 0 && y >= 0 && y < x)
		return (7);
	else if (x >= 0 && y <= 0 && absol(y) > absol(x))
		return (5);
	else if (x >= 0 && y <= 0 && absol(y) == absol(x))
		return (6);
	else if (x <= 0 && y <= 0 && absol(y) == absol(x))
		return (4);
	else if (x <= 0 && y >= 0 && absol(y) == absol(x))
		return (2);
	else if (x <= 0 && y <= 0 && absol(y) < absol(x))
		return (3);
	else
		return (-1);
}
