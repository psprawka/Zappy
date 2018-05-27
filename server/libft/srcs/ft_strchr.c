/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psprawka <psprawka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/27 23:23:57 by psprawka          #+#    #+#             */
/*   Updated: 2018/04/27 23:24:00 by psprawka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strchr(char *str, char to_find)
{
	int i;
	
	i = 0;
	while (str[i] && str[i] != to_find)
		i++;
	if (str[i] == to_find)
		return (str);
	else
		return ((char *)'\0');
}
