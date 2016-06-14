/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhonore <qhonore@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/11 13:36:56 by qhonore           #+#    #+#             */
/*   Updated: 2016/03/22 14:33:02 by qhonore          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	zoom_in(int x, int y, t_data *d)
{
	t_vect2d	p;
	double		tmp_x;
	double		tmp_y;

	d->f.zoom *= 2;
	p.x = d->f.x1 + (double)x * (d->f.x2 - d->f.x1) / WIN_W;
	p.y = d->f.y1 + (double)y * (d->f.y2 - d->f.y1) / WIN_H;
	tmp_x = d->f.x1;
	tmp_y = d->f.y1;
	d->f.x1 = p.x - (d->f.x2 - d->f.x1) / 4;
	d->f.x2 = p.x + (d->f.x2 - tmp_x) / 4;
	d->f.y1 = p.y - (d->f.y2 - d->f.y1) / 4;
	d->f.y2 = p.y + (d->f.y2 - tmp_y) / 4;
	expose_hook((void*)d);
}

void	zoom_out(int x, int y, t_data *d)
{
	t_vect2d	p;
	double		tmp_x;
	double		tmp_y;

	d->f.zoom /= 2;
	p.x = d->f.x1 + (double)x * (d->f.x2 - d->f.x1) / WIN_W;
	p.y = d->f.y1 + (double)y * (d->f.y2 - d->f.y1) / WIN_W;
	tmp_x = d->f.x1;
	tmp_y = d->f.y1;
	d->f.x1 = p.x - (d->f.x2 - d->f.x1);
	d->f.x2 = p.x + (d->f.x2 - tmp_x);
	d->f.y1 = p.y - (d->f.y2 - d->f.y1);
	d->f.y2 = p.y + (d->f.y2 - tmp_y);
	expose_hook((void*)d);
}

void	ft_move(t_data *d, int key)
{
	if (key == 123)
	{
		d->f.x1 += 40.0 / d->f.zoom;
		d->f.x2 += 40.0 / d->f.zoom;
	}
	else if (key == 124)
	{
		d->f.x1 -= 40.0 / d->f.zoom;
		d->f.x2 -= 40.0 / d->f.zoom;
	}
	else if (key == 125)
	{
		d->f.y1 -= 40.0 / d->f.zoom;
		d->f.y2 -= 40.0 / d->f.zoom;
	}
	else if (key == 126)
	{
		d->f.y1 += 40.0 / d->f.zoom;
		d->f.y2 += 40.0 / d->f.zoom;
	}
	expose_hook((void*)d);
}

void	change_color(t_data *d, int key)
{
	if (key == 89)
	{
		d->phase = (d->phase < 254 ? d->phase + 5 : 0);
		expose_hook((void*)d);
	}
	else if (key == 86)
	{
		d->phase = (d->phase > 1 ? d->phase - 5 : 255);
		expose_hook((void*)d);
	}
	else if ((key == 92 && d->lum < 1.0) || (key == 88 && d->lum > 0.1))
	{
		d->lum += (key == 92 ? 0.1 : -0.1);
		expose_hook((void*)d);
	}
	else if ((key == 91 && d->shade < 5.0) || (key == 87 && d->shade > 1.0))
	{
		d->shade += (key == 91 ? 0.1 : -0.1);
		expose_hook((void*)d);
	}
}

void	change_fractal(t_data *d, int key)
{
	if (key == 18 && d->type != 1)
		init_mandelbrot(d);
	else if (key == 19 && d->type != 4)
		init_julia(d);
	else if (key == 20 && d->type != 3)
		init_burningship(d);
	else if (key == 21 && d->type != 2)
		init_celtic(d);
	else if (key == 22 && d->type != 6)
		init_similitree(d);
	else if (key == 23 && d->type != 5)
		init_mandelbar(d);
	else if (key == 26 && d->type != 7)
		init_unknow(d);
	else if (key == 28 && d->type != 8)
		init_birdofprey(d);
}
