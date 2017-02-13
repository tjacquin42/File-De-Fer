/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjacquin <tjacquin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/22 18:42:42 by tjacquin          #+#    #+#             */
/*   Updated: 2016/03/04 14:15:52 by tjacquin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char *res;

	res = (char*)malloc(sizeof(char) * (ft_strlen((char *)(s1)) + 1));
	if (!res)
		return (NULL);
	res = ft_strcpy(res, s1);
	return (res);
}
