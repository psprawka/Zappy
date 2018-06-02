/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asyed <asyed@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/18 13:44:57 by asyed             #+#    #+#             */
/*   Updated: 2018/06/02 03:56:43 by asyed            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char	*save;
	size_t	i;

	save = NULL;
	i = 0;
	if (dest < src)
	{
		save = dest;
		while (i < n)
		{
			*(char *)dest++ = *(char *)src++;
			i++;
		}
		return (save);
	}
	else
	{
		save = dest;
		ft_memcpy(dest, src, n);
	}
	return (save);
}
