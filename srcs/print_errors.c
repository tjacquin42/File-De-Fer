/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjacquin <tjacquin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/09 16:04:35 by tjacquin          #+#    #+#             */
/*   Updated: 2017/02/13 03:23:56 by tjacquin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void		free_all(t_fdf *stk)
{
	int i;

	i = 0;
	if (stk->map)
	{
		while (i < stk->ymax)
		{
			if (stk->map[i])
			{
				free(stk->map[i]);
				stk->map[i] = NULL;
			}
			i++;
		}
		free(stk->map);
		stk->map = NULL;
	}
	if (stk->x_p)
		free(stk->x_p);
	if (stk->y_p)
		free(stk->y_p);
	if (stk->z_p)
		free(stk->z_p);
	if (stk)
		free(stk);
}

void		fdf_exit(t_fdf *stk)
{
	free_all(stk);
	exit(1);
}

void		malloc_error(t_fdf *stk)
{
	ft_putstr_fd("malloc has been burst >_<\n", 2);
	fdf_exit(stk);
}

void		map_error(t_fdf *stk)
{
	ft_putstr_fd("Usage: ./fdf [path]\n", 2);
	fdf_exit(stk);
}

void		argv_error(int arg, t_fdf *stk)
{
	if (arg == 2)
		ft_putstr("Too many arguments !\nUsage : ./fdf [path]\n");
	if (arg == 1)
		ft_putstr("Not enough arguments !\nUsage : ./fdf [path]\n");
	fdf_exit(stk);
}
