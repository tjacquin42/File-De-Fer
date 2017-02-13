/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events_script.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjacquin <tjacquin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/05 23:26:57 by tjacquin          #+#    #+#             */
/*   Updated: 2017/02/13 04:03:31 by tjacquin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

float				d_r(float deg)
{
	float i;

	i = PI * deg / 180;
	return (i);
}

static void			print_img(t_fdf *stk)
{
	mlx_destroy_image(stk->mlx, stk->img);
	stk->img = mlx_new_image(stk->mlx, 1000, 1000);
	stk->gda = mlx_get_data_addr(stk->img, &stk->bpx, &stk->szl, &stk->endl);
	map_trace(stk);
	mlx_put_image_to_window(stk->mlx, stk->win, stk->img, 0, 0);
}

static void			num_pad_event(int keycode, t_fdf *stk)
{
	stk->hi = ((keycode == 85) ? (stk->hi += 0.5) : (stk->hi));
	if (stk->hi > 1)
		stk->hi = ((keycode == 83) ? (stk->hi -= 0.5) : (stk->hi));
	stk->zo = ((keycode == 69) ? (stk->zo += 5) : (stk->zo));
	if (stk->zo >= 6)
		stk->zo = ((keycode == 78) ? (stk->zo -= 5) : (stk->zo));
	stk->rx = ((keycode == 91) ? (stk->rx += 5) : (stk->rx));
	stk->rx = ((keycode == 84) ? (stk->rx -= 5) : (stk->rx));
	stk->ry = ((keycode == 88) ? (stk->ry += 5) : (stk->ry));
	stk->ry = ((keycode == 86) ? (stk->ry -= 5) : (stk->ry));
	stk->rz = ((keycode == 92) ? (stk->rz += 5) : (stk->rz));
	stk->rz = ((keycode == 89) ? (stk->rz -= 5) : (stk->rz));
}

static void			pos_and_color_event(int keycode, t_fdf *stk)
{
	if (keycode == 8)
		stk->color = 16777215;
	stk->color = ((keycode == 47) ? (stk->color += 20000) : (stk->color));
	if (stk->color > 16777215)
		stk->color = 20000;
	stk->color = ((keycode == 43) ? (stk->color -= 20000) : (stk->color));
	if (stk->color < 20000)
		stk->color = 16777215;
	stk->calx = ((keycode == 124) ? (stk->calx += 20) : (stk->calx));
	stk->calx = ((keycode == 123) ? (stk->calx -= 20) : (stk->calx));
	stk->caly = ((keycode == 125) ? (stk->caly += 20) : (stk->caly));
	stk->caly = ((keycode == 126) ? (stk->caly -= 20) : (stk->caly));
}

int					event(int keycode, t_fdf *stk)
{
	if (keycode == 53)
		fdf_exit(stk);
	if ((keycode >= 83 && keycode <= 92) || keycode == 69 || keycode == 78)
		num_pad_event(keycode, stk);
	if ((keycode >= 123 && keycode <= 126) || keycode == 43 || keycode == 47 ||
			keycode == 8)
		pos_and_color_event(keycode, stk);
	print_img(stk);
	return (0);
}
