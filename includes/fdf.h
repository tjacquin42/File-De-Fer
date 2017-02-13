/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjacquin <tjacquin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/09 16:05:31 by tjacquin          #+#    #+#             */
/*   Updated: 2017/02/13 06:47:00 by tjacquin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <mlx.h>
# include <fcntl.h>
# include <math.h>
# include <stdlib.h>
# include <string.h>
# include ".././libft/libft.h"

# define PI 3.1415926535898
# define ROTX 1
# define ROTY 2
# define ROTZ 3

typedef struct		s_fdf
{
	void			*win;
	void			*mlx;
	void			*gda;
	void			*img;
	int				ln;
	int				color;
	int				**map;
	int				zo;
	int				xmax;
	int				ymax;
	float			hi;
	float			*x_p;
	float			*y_p;
	float			*z_p;
	float			rx;
	float			ry;
	float			rz;
	int				x1;
	int				x2;
	int				y1;
	int				y2;
	int				x1cp;
	int				y1cp;
	int				x2cp;
	int				y2cp;
	int				bpx;
	int				szl;
	int				endl;
	int				swin;
	int				calx;
	int				caly;
	int				i;
}					t_fdf;

void				map_trace(t_fdf *stk);
void				segment_tracer(t_fdf *stk);
float				d_r(float deg);
int					event(int keycode, t_fdf *stk);
int					nbrlen(char *ln);
void				display(void);
void				init(t_fdf *stk);
int					get_center(t_fdf *stk);
void				map_tester(t_fdf *stk, char *path);
void				fdf_exit(t_fdf *stk);
void				malloc_error(t_fdf *stk);
void				map_error(t_fdf *stk);
void				argv_error(int arg, t_fdf *stk);

#endif
