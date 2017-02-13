/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjacquin <tjacquin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/02 16:04:18 by tjacquin          #+#    #+#             */
/*   Updated: 2017/02/13 14:52:48 by tjacquin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include ".././includes/fdf.h"

int						nbrlen(char *ln)
{
	int		i;
	int		nb;
	int		len;

	if (!ln)
		return (0);
	len = ft_strlen(ln);
	i = 0;
	nb = 0;
	while (i < len && ln[i] != '\0')
	{
		if (ln[i] >= '0' && ln[i] <= '9' && ln[i] != '\0')
		{
			while (ln[i] != ' ' && ln[i] != '\0')
				i++;
			nb++;
		}
		else
		{
			while ((ln[i] < '0' || ln[i] > '9') && ln[i] != '\0')
				i++;
		}
	}
	return (nb);
}

static int				next_int_pos(char *buff)
{
	int		i;

	i = 0;
	while (buff[i] != ' ' && buff[i])
		i++;
	while (buff[i] == ' ' && buff[i])
		i++;
	return (i);
}

static void				line_atoi(char *buff, int r, t_fdf *stk)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (nbrlen(buff) != stk->xmax)
		map_error(stk);
	if (!(stk->map[r] = (int *)malloc(sizeof(int) * stk->xmax)))
		malloc_error(stk);
	while (buff[i])
	{
		if ((buff[i] <= '9' && buff[i] >= '0') || buff[i] == '-')
			stk->map[r][j++] = ft_atoi(&buff[i]);
		i = i + next_int_pos(&buff[i]);
	}
}

static void				input_use(char *path, t_fdf *stk)
{
	int		ret;
	int		i;
	int		fd;
	char	*buff;

	map_tester(stk, path);
	fd = open(path, O_RDONLY);
	ret = get_next_line(fd, &buff);
	stk->xmax = nbrlen(buff);
	while (ret > 0)
	{
		ret = get_next_line(fd, &buff);
		stk->ymax++;
	}
	if (!(stk->map = (int **)malloc(sizeof(int *) * stk->ymax)))
		malloc_error(stk);
	fd = open(path, O_RDONLY);
	i = 0;
	ret = stk->ymax;
	while (ret-- != 0)
	{
		get_next_line(fd, &buff);
		line_atoi(buff, i, stk);
		i++;
	}
}

int						main(int argc, char **argv)
{
	t_fdf	*stk;

	if (!(stk = (t_fdf *)malloc(sizeof(t_fdf))))
		malloc_error(stk);
	if (argc > 2 || argc < 2)
		((argc > 2) ? argv_error(2, stk) : argv_error(1, stk));
	stk->ymax = 0;
	input_use(argv[1], stk);
	init(stk);
	stk->mlx = mlx_init();
	stk->win = mlx_new_window(stk->mlx, stk->swin, stk->swin - 200, "FdF");
	stk->img = mlx_new_image(stk->mlx, stk->swin, stk->swin);
	stk->gda = mlx_get_data_addr(stk->img, &stk->bpx, &stk->szl, &stk->endl);
	map_trace(stk);
	display();
	ft_putnbr(stk->xmax);
	mlx_hook(stk->win, 2, 3, event, stk);
	mlx_put_image_to_window(stk->mlx, stk->win, stk->img, 0, 0);
	mlx_loop(stk->mlx);
	return (0);
}
