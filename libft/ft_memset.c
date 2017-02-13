/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjacquin <tjacquin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/18 18:49:32 by tjacquin          #+#    #+#             */
/*   Updated: 2016/02/22 18:32:49 by tjacquin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			i;
	unsigned char	*c_bis;

	i = 0;
	c_bis = (unsigned char *)b;
	while (i < len)
	{
		c_bis[i] = (unsigned char)c;
		i++;
	}
	return (b);
}
