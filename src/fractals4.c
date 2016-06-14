/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals4.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhonore <qhonore@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/13 17:21:30 by qhonore           #+#    #+#             */
/*   Updated: 2016/03/22 14:32:42 by qhonore          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	init_unknow(t_data *d)
{
	d->type = 7;
	d->f.cr = 0.285;
	d->f.ci = 0.01;
	d->f.zoom = 400;
	d->f.imax = 30;
	d->f.x1 = -1.3;
	d->f.x2 = 1.4;
	d->f.y1 = -1.2;
	d->f.y2 = 1.2;
	expose_hook((void*)d);
}

void	init_birdofprey(t_data *d)
{
	d->type = 8;
	d->f.zoom = 400;
	d->f.imax = 30;
	d->f.x1 = -1.4;
	d->f.x2 = 1.3;
	d->f.y1 = -1.2;
	d->f.y2 = 1.2;
	expose_hook((void*)d);
}

void	unknow(t_data *d, t_fractal *f, t_img *i)
{
	f->p.y = -1;
	while (++f->p.y < WIN_H)
	{
		f->p.x = -1;
		while (++f->p.x < WIN_W)
		{
			f->zr = (double)f->p.x / f->zoom + f->x1;
			f->zi = (double)f->p.y / f->zoom + f->y1;
			f->i = 0;
			while (f->zr * f->zr + f->zi * f->zi < 4 && f->i < f->imax)
			{
				f->tmp = f->zr * f->zr - f->zi * f->zi;
				f->zi = ft_dabs(2 * f->zi * f->zr) + f->ci;
				f->zr = f->tmp + f->cr;
				++f->i;
			}
			if (f->i < f->imax)
				img_put_pixel(d, i, f->p, rainbow(d));
		}
	}
}

void	birdofprey(t_data *d, t_fractal *f, t_img *i)
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
				f->tmp = f->zi * f->zi;
				f->zi = ((3 * f->zr * f->zr) - f->tmp) * ft_dabs(f->zi) + f->ci;
				f->zr = (f->zr * f->zr - (f->tmp * 3)) * ft_dabs(f->zr) + f->cr;
				++f->i;
			}
			if (f->i < f->imax)
				img_put_pixel(d, i, f->p, rainbow(d));
		}
	}
}
