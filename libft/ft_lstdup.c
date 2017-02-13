/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjacquin <tjacquin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/09 18:24:50 by tjacquin          #+#    #+#             */
/*   Updated: 2016/04/09 18:25:41 by tjacquin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstdup(t_list **alst)
{
	t_list	*new;
	t_list	*temp;
	t_list	*temp2;

	if (alst == NULL)
		return (NULL);
	temp = *alst;
	new = (t_list *)malloc(sizeof(t_list));
	if (new == NULL)
		return (NULL);
	new = temp;
	temp2 = new;
	while (temp->next != NULL)
	{
		temp2 = (t_list *)malloc(sizeof(t_list *));
		if (temp2 == NULL)
			return (NULL);
		temp2 = temp;
		temp = temp->next;
		temp2 = temp2->next;
	}
	return (new);
}
