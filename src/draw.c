/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhonore <qhonore@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/16 10:19:00 by qhonore           #+#    #+#             */
/*   Updated: 2016/03/14 01:47:26 by qhonore          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	img_put_pixel(t_data *d, t_img *i, t_vect2i p, t_rgb c)
{
	int		pos;
	int		size;

	size = ((WIN_H - 1) * d->img.sl) + (WIN_W * d->img.bpp / 8);
	pos = (p.y * i->sl) + (p.x * i->bpp / 8);
	if (pos > 0 && pos + 2 < size && p.x >= 0
		&& (p.x * d->img.bpp / 8) < d->img.sl)
	{
		if (i->edn)
		{
			i->d[pos] = mlx_get_color_value(d->mlx, c.r);
			i->d[pos + 1] = mlx_get_color_value(d->mlx, c.g);
			i->d[pos + 2] = mlx_get_color_value(d->mlx, c.b);
		}
		else
		{
			i->d[pos] = mlx_get_color_value(d->mlx, c.b);
			i->d[pos + 1] = mlx_get_color_value(d->mlx, c.g);
			i->d[pos + 2] = mlx_get_color_value(d->mlx, c.r);
		}
	}
}
