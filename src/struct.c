/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhonore <qhonore@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/16 12:15:31 by qhonore           #+#    #+#             */
/*   Updated: 2016/05/29 14:39:13 by qhonore          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_vect2i	set_vect2i(int x, int y)
{
	t_vect2i	vect2i;

	vect2i.x = x;
	vect2i.y = y;
	return (vect2i);
}

t_vect2d	set_vect2d(double x, double y)
{
	t_vect2d	vect2d;

	vect2d.x = x;
	vect2d.y = y;
	return (vect2d);
}

t_rgb		set_rgb(int r, int g, int b)
{
	t_rgb	rgb;

	rgb.r = r;
	rgb.g = g;
	rgb.b = b;
	return (rgb);
}

t_rgb		rainbow(t_data *d)
{
	int		center;
	int		width;
	double	freq;
	t_rgb	rgb;

	center = 128;
	width = 127;
	freq = M_PI * 2 / d->f.imax;
	rgb.r = d->lum * ((int)(d->shade *
		(sin(freq * (double)d->f.i + 2.0 + d->phase) * width + center)));
	rgb.g = d->lum * ((int)(d->shade *
		(sin(freq * (double)d->f.i + d->phase) * width + center)));
	rgb.b = d->lum * ((int)(d->shade *
		(sin(freq * (double)d->f.i + 4.0 + d->phase) * width + center)));
	return (rgb);
}

int			init_img(t_data *data, t_img *img)
{
	if (!(img->i = mlx_new_image(data->mlx, WIN_W, WIN_H)))
		return (0);
	img->d = mlx_get_data_addr(img->i, &(img->bpp), &(img->sl), &(img->edn));
	return (1);
}
