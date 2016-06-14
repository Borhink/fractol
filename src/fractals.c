/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhonore <qhonore@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/13 17:19:45 by qhonore           #+#    #+#             */
/*   Updated: 2016/05/27 22:04:13 by qhonore          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	init_mandelbrot(t_data *d)
{
	d->type = 1;
	d->f.zoom = 400;
	d->f.imax = 30;
	d->f.x1 = -2.0;
	d->f.x2 = 0.7;
	d->f.y1 = -1.2;
	d->f.y2 = 1.2;
	expose_hook((void*)d);
}

void	init_celtic(t_data *d)
{
	d->type = 2;
	d->f.zoom = 300;
	d->f.imax = 30;
	d->f.x1 = -1.7;
	d->f.x2 = 1;
	d->f.y1 = -2.2;
	d->f.y2 = 0.4;
	expose_hook((void*)d);
}

void	mandelbrot(t_data *d, t_fractal *f, t_img *i)
{
	f->p.y = -1;
	while (++f->p.y < WIN_H)
	{
		f->p.x = -1;
		while (++f->p.x < WIN_W)
		{
			f->cr = (double)f->p.x / f->zoom + f->x1;
			f->ci = (double)f->p.y / f->zoom + f->y1;
			f->zr = 0;
			f->zi = 0;
			f->i = 0;
			while (f->zr * f->zr + f->zi * f->zi < 4 && f->i < f->imax)
			{
				f->tmp = f->zr * f->zr - f->zi * f->zi;
				f->zi = 2 * f->zi * f->zr + f->ci;
				f->zr = f->tmp + f->cr;
				++f->i;
			}
			if (f->i < f->imax)
				img_put_pixel(d, i, f->p, rainbow(d));
		}
	}
}

void	celtic(t_data *d, t_fractal *f, t_img *i)
{
	f->p.y = -1;
	while (++f->p.y < WIN_H)
	{
		f->p.x = -1;
		while (++f->p.x < WIN_W)
		{
			f->cr = (double)f->p.x / f->zoom + f->x1;
			f->ci = (double)f->p.y / f->zoom + f->y1;
			f->zr = 0;
			f->zi = 0;
			f->i = 0;
			while (f->zr * f->zr + f->zi * f->zi < 4 && f->i < f->imax)
			{
				f->tmp = ft_dabs(f->zr * f->zr - f->zi * f->zi);
				f->zi = 2 * f->zi * f->zr + f->cr;
				f->zr = f->tmp + f->ci;
				++f->i;
			}
			if (f->i < f->imax)
				img_put_pixel(d, i, f->p, rainbow(d));
		}
	}
}
