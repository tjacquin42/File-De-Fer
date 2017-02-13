/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjacquin <tjacquin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/30 14:54:38 by tjacquin          #+#    #+#             */
/*   Updated: 2016/03/30 14:55:13 by tjacquin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	size_t	i;
	size_t	limit;

	i = 0;
	limit = ft_strlen(src);
	while (i < len)
	{
		dst[i] = src[i];
		if (limit < len && i >= limit)
			dst[i] = '\0';
		i++;
	}
	return (dst);
}
