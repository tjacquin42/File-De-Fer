/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjacquin <tjacquin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/24 19:34:15 by tjacquin          #+#    #+#             */
/*   Updated: 2016/03/17 18:36:16 by tjacquin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(char *str, char *to_find)
{
	char *ans;
	char *tmp;
	char *aim;

	if (!*to_find)
		return (str);
	tmp = str;
	while (*tmp)
	{
		ans = tmp;
		aim = to_find;
		while (*tmp && *aim && *tmp == *aim)
		{
			++tmp;
			++aim;
		}
		if (!*aim)
			return (ans);
		tmp = ans + 1;
	}
	return (0);
}
