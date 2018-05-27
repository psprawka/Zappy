/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psprawka <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/03 19:18:27 by psprawka          #+#    #+#             */
/*   Updated: 2017/07/03 19:18:30 by psprawka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *str, int size)
{
	char	*new;
	int		i;

	i = 0;
	new = ft_strnew(size + 1);
	while (i < size)
	{
		new[i] = str[i];
		i++;
	}
	return (new);
}
