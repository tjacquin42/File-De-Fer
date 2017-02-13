/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjacquin <tjacquin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/25 12:39:41 by tjacquin          #+#    #+#             */
/*   Updated: 2016/02/25 13:05:16 by tjacquin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	size_t	size;

	if (s1 && s2)
	{
		size = ft_strlen(s1) + ft_strlen(s2) + 1;
		str = (char *)malloc(sizeof(char) * size);
		if (!str)
			return (NULL);
		str = ft_strcpy(str, s1);
		str = ft_strcat(str, s2);
		return (str);
	}
	else
		return (NULL);
}
