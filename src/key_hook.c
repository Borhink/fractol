/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhonore <qhonore@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/04 22:27:54 by qhonore           #+#    #+#             */
/*   Updated: 2016/03/17 04:44:36 by qhonore          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	free_datas_and_quit(t_data *d)
{
	mlx_destroy_image(d->mlx, d->img.i);
	mlx_destroy_window(d->mlx, d->win);
	exit(1);
}

int			key_hook(int key, void *data)
{
	t_data *d;

	d = (t_data*)data;
	if (key == 53)
		free_datas_and_quit(d);
	else if (key == 67)
		d->move = (d->move + 1) % 2;
	else if (key == 69 && d->f.imax < 300)
	{
		d->f.imax += 10;
		expose_hook(data);
	}
	else if (key == 78 && d->f.imax > 10)
	{
		d->f.imax -= 10;
		expose_hook(data);
	}
	else if (key >= 18 && key <= 28)
		change_fractal(d, key);
	else if (key == 123 || key == 124 || key == 125 || key == 126)
		ft_move(d, key);
	else if (key == 86 || key == 89 || key == 88
			|| key == 92 || key == 91 || key == 87)
		change_color(d, key);
	return (1);
}

int			mouse_hook(int button, int x, int y, void *data)
{
	t_data		*d;

	d = (t_data*)data;
	if ((button == 4 || button == 1) && d->f.zoom < 30000000000000000)
		zoom_in(x, y, d);
	else if ((button == 5 || button == 2) && d->f.zoom > 200)
		zoom_out(x, y, d);
	else if (button == 3)
	{
		d->txt = (d->txt + 1) % 2;
		display(d);
	}
	return (1);
}

int			motion_hook(int x, int y, void *data)
{
	t_data		*d;

	d = (t_data*)data;
	if (d->move && (d->type == 4 || d->type == 6 || d->type == 7))
	{
		d->f.cr = ((double)x - (WIN_W / 2)) / (WIN_W / 2);
		d->f.ci = ((double)y - (WIN_H / 2)) / (WIN_H / 2);
		expose_hook(data);
	}
	return (1);
}
