/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjacquin <tjacquin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/30 14:57:02 by tjacquin          #+#    #+#             */
/*   Updated: 2016/03/30 14:57:39 by tjacquin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t	i;
	int		j;

	i = 0;
	j = 0;
	while (i < n && s1[i] != '\0' && s2[j] != '\0')
	{
		if (s1[i] == s2[j])
			j++;
		else
		{
			i -= j;
			j = 0;
		}
		i++;
	}
	if (s2[j] == '\0')
		return ((char *)&s1[i - j]);
	return (NULL);
}
