/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psprawka <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/04 11:19:50 by psprawka          #+#    #+#             */
/*   Updated: 2017/07/04 11:19:55 by psprawka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_strstr(char *str, char *to_find)
{
	int		begin;
	int		i;
	int		j;

	i = 0;
	begin = 0;
	while (str[i])
	{
		j = 0;
		begin = i;
		while (str[i] && str[i++] == to_find[j++])
			;
		if (to_find[j] == '\0')
			return (1);
		if (str[i] == '\0')
			return (0);
		i = begin + 1;
	}
	return (0);
}
