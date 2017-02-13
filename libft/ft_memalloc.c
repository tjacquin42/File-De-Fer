/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjacquin <tjacquin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/29 18:09:31 by tjacquin          #+#    #+#             */
/*   Updated: 2016/04/01 18:43:39 by tjacquin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void	*str;
	int		i;

	i = 0;
	if (size == 0)
		return (NULL);
	str = malloc(size);
	if (str)
		ft_bzero(str, size);
	return (str);
}
