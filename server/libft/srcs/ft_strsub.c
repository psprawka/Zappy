/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psprawka <psprawka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/21 19:33:53 by psprawka          #+#    #+#             */
/*   Updated: 2018/05/21 16:06:40 by psprawka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char *s, unsigned int start, size_t len)
{
	char	*fresh;
	int		i;
	
	if (!s)
		return (NULL);
	if ((fresh = ft_strnew(len)) == NULL)
		return (NULL);
	i = 0;
	while (len--)
		fresh[i++] = s[start++];
	return (fresh);
}
