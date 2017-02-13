/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   send_to_trace.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjacquin <tjacquin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/04 21:40:59 by tjacquin          #+#    #+#             */
/*   Updated: 2017/02/13 14:51:52 by tjacquin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void		matricial(t_fdf *stk, int x, int y, int z)
{
	float	xp;
	float	yp;
	float	zp;
	int		i;

	i = stk->i;
	stk->x_p[i] = x;
	stk->y_p[i] = cos(d_r(stk->rx)) * y - sin(d_r(stk->rx)) * z;
	stk->z_p[i] = sin(d_r(stk->rx)) * y + cos(d_r(stk->rx)) * z;
	xp = cos(d_r(stk->ry)) * stk->x_p[i] + sin(d_r(stk->ry)) * stk->z_p[i];
	yp = stk->y_p[i];
	zp = -(sin(d_r(stk->ry))) * stk->x_p[i] + cos(d_r(stk->ry)) * stk->z_p[i];
	stk->x_p[i] = cos(d_r(stk->rz)) * xp - sin(d_r(stk->rz)) * yp;
	stk->y_p[i] = sin(d_r(stk->rz)) * xp + cos(d_r(stk->rz)) * yp;
	stk->z_p[i] = zp;
}

void		stock_create(t_fdf *stk)
{
	int x;
	int y;

	stk->i = 0;
	y = 0;
	if (!(stk->x_p = (float *)malloc(sizeof(float) * (stk->xmax * stk->ymax))))
		malloc_error(stk);
	if (!(stk->y_p = (float *)malloc(sizeof(float) * (stk->xmax * stk->ymax))))
		malloc_error(stk);
	if (!(stk->z_p = (float *)malloc(sizeof(float) * (stk->xmax * stk->ymax))))
		malloc_error(stk);
	while (y < stk->ymax)
	{
		x = 0;
		while (x < stk->xmax)
		{
			matricial(stk, (x + 1), (y + 1), (stk->map[y][x] * stk->hi));
			x++;
			stk->i++;
		}
		y++;
	}
}

void		trace_vertical(t_fdf *stk)
{
	int x;
	int y;
	int i;
	int point;

	i = 0;
	y = 0;
	point = get_center(stk);
	while (y++ < (stk->ymax - 1))
	{
		x = 0;
		while (x++ < stk->xmax)
		{
			stk->x1 = stk->x_p[i] * stk->zo + point + stk->calx;
			stk->x2 = stk->x_p[i + stk->xmax] * stk->zo + point + stk->calx;
			stk->y1 = stk->y_p[i] * stk->zo + point + stk->caly;
			stk->y2 = stk->y_p[i++ + stk->xmax] * stk->zo + point + stk->caly;
			segment_tracer(stk);
		}
	}
}

void		trace_horizontal(t_fdf *stk)
{
	int x;
	int y;
	int i;
	int point;

	i = 0;
	y = 0;
	point = get_center(stk);
	while (y++ < stk->ymax)
	{
		x = 0;
		while (x++ < (stk->xmax - 1))
		{
			stk->x1 = stk->x_p[i] * stk->zo + point + stk->calx;
			stk->x2 = stk->x_p[i + 1] * stk->zo + point + stk->calx;
			stk->y1 = stk->y_p[i] * stk->zo + point + stk->caly;
			stk->y2 = stk->y_p[i++ + 1] * stk->zo + point + stk->caly;
			segment_tracer(stk);
		}
		i++;
	}
}

void		map_trace(t_fdf *stk)
{
	if (stk->x_p)
		free(stk->x_p);
	if (stk->y_p)
		free(stk->y_p);
	if (stk->z_p)
		free(stk->z_p);
	stock_create(stk);
	trace_vertical(stk);
	trace_horizontal(stk);
}
