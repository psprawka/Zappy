/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_to_octal.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psprawka <psprawka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/10 15:36:46 by psprawka          #+#    #+#             */
/*   Updated: 2018/04/10 15:36:48 by psprawka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_convert_octal(unsigned long int nb)
{
	char	*print;
	int		i;

	i = 0;
	print = ft_memalloc(22);
	if (nb == 0)
		print[i++] = '0';
	while (nb != 0)
	{
		print[i++] = (nb % 8) + 48;
		nb /= 8;
	}
	print[i] = '\0';
	return (ft_strrev(print));
}
