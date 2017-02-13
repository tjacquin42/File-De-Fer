/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjacquin <tjacquin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/25 12:27:07 by tjacquin          #+#    #+#             */
/*   Updated: 2016/02/25 12:39:22 by tjacquin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	count;
	char	*str;

	i = start;
	count = 0;
	if (s)
	{
		str = (char *)malloc(sizeof(char) * len + 1);
		if (!str)
			return (NULL);
		while (count < len)
		{
			str[count] = s[i];
			i++;
			count++;
		}
		str[count] = '\0';
		return (str);
	}
	else
		return (NULL);
}
