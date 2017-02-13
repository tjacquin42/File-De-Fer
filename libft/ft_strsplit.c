/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjacquin <tjacquin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/28 09:36:53 by tjacquin          #+#    #+#             */
/*   Updated: 2016/03/04 15:15:30 by tjacquin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_size(char const *s, char c)
{
	int		i;
	int		size;

	i = 0;
	size = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c)
			i++;
		if (s[i] != c)
			if (s[i + 1] == c || s[i + 1] == '\0')
				size++;
		i++;
	}
	return (size);
}

static size_t	ft_length(char const *s, char c, int i)
{
	size_t	len;

	len = 0;
	while (s[i] != c && s[i] != '\0')
	{
		len++;
		i++;
	}
	return (len);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**res;
	int		i;
	int		j;

	if (!s)
		return (NULL);
	i = 0;
	j = 0;
	res = (char **)malloc(sizeof(char *) * ft_size(s, c));
	if (res == NULL)
		return (res);
	while (s[i] != '\0')
	{
		if (s[i] != c)
		{
			res[j] = ft_strsub(s, i, ft_length(s, c, i));
			j++;
			while (s[i] != c && s[i] != '\0')
				i++;
		}
		else
			i++;
	}
	res[j] = NULL;
	return (res);
}
