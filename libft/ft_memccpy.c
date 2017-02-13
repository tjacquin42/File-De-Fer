/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjacquin <tjacquin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/18 19:46:16 by tjacquin          #+#    #+#             */
/*   Updated: 2016/04/09 18:18:17 by tjacquin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t		i;
	char		*ptr_dst;
	const char	*ptr_src;

	i = 0;
	ptr_dst = (char *)dst;
	ptr_src = (const char *)src;
	while (i < n)
	{
		ptr_dst[i] = ptr_src[i];
		if (ptr_src[i] == c)
			return (void *)&(ptr_dst[i + 1]);
		i++;
	}
	return (0);
}
