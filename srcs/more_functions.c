/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   more_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjacquin <tjacquin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/09 16:04:30 by tjacquin          #+#    #+#             */
/*   Updated: 2017/02/10 19:40:07 by tjacquin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	map_tester(t_fdf *stk, char *path)
{
	int		saver;
	int		fd_bis;
	char	*buff_bis;
	int		ret_bis;

	fd_bis = open(path, O_RDONLY);
	ret_bis = get_next_line(fd_bis, &buff_bis);
	saver = nbrlen(buff_bis);
	if (ret_bis < 1)
		map_error(stk);
	while (ret_bis > 0)
	{
		ret_bis = get_next_line(fd_bis, &buff_bis);
		if (saver != nbrlen(buff_bis) && ret_bis)
			map_error(stk);
		saver = nbrlen(buff_bis);
	}
}

int		xymax(t_fdf *stk)
{
	if (stk->xmax > stk->ymax)
		return (stk->xmax);
	if (stk->ymax > stk->xmax)
		return (stk->ymax);
	return (stk->xmax);
}

int		xymin(t_fdf *stk)
{
	if (stk->xmax > stk->ymax)
		return (stk->ymax);
	if (stk->ymax > stk->xmax)
		return (stk->xmax);
	return (stk->xmax);
}

void	init(t_fdf *stk)
{
	if (stk->xmax == 0)
		map_error(stk);
	stk->color = 16777215;
	stk->hi = 1;
	stk->rx = 45;
	stk->ry = -30;
	stk->rz = 10;
	stk->swin = 1000;
	stk->calx = 0;
	stk->caly = 0;
	stk->zo = stk->swin / (xymax(stk) + xymin(stk) + 1);
}

int		get_center(t_fdf *stk)
{
	int point;

	point = stk->swin / 4;
	return (point);
}
