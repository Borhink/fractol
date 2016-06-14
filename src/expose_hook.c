/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expose_hook.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhonore <qhonore@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/05 00:56:03 by qhonore           #+#    #+#             */
/*   Updated: 2016/06/14 18:24:08 by qhonore          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	clear_img(t_img *i)
{
	t_vect2i	p;
	int			pos;

	p.y = -1;
	while (++p.y < WIN_H)
	{
		p.x = -1;
		while (++p.x < WIN_W)
		{
			pos = (p.y * i->sl) + (p.x * i->bpp / 8);
			i->d[pos + 0] = 0;
			i->d[pos + 1] = 0;
			i->d[pos + 2] = 0;
		}
	}
}

void		display(t_data *d)
{
	mlx_clear_window(d->mlx, d->win);
	mlx_put_image_to_window(d->mlx, d->win, d->img.i, 0, 0);
	if (!d->txt)
		return ;
	mlx_string_put(d->mlx, d->win, 5, 5, 0xffffff, "Zoom : mouse 1, 2, wheel");
	mlx_string_put(d->mlx, d->win, 5, 22, 0xffffff, "Movement : arrows");
	mlx_string_put(d->mlx, d->win, 5, 39, 0xffffff, "Fractal : 1(!) to 8(*)");
	mlx_string_put(d->mlx, d->win, 5, 56, 0xffffff, "Luminosity : 9 / 6");
	mlx_string_put(d->mlx, d->win, 5, 73, 0xffffff, "Shade : 8 / 5");
	mlx_string_put(d->mlx, d->win, 5, 90, 0xffffff, "Color rotate : 7 / 4");
	mlx_string_put(d->mlx, d->win, 5, 107, 0xffffff, "Iteration : + / -");
	mlx_string_put(d->mlx, d->win, 5, 124, 0xffffff, "Infos : mouse 3");
	mlx_string_put(d->mlx, d->win, 5, 141, 0xffffff, "Motion hook : *");
	mlx_string_put(d->mlx, d->win, 5, 175, 0xffffff, "Cur zoom :");
	mlx_string_put(d->mlx, d->win, 110, 175, 0xffffff, ft_ltoa(d->f.zoom));
	mlx_string_put(d->mlx, d->win, 5, 192, 0xffffff, "Cur iteration :");
	mlx_string_put(d->mlx, d->win, 160, 192, 0xffffff, ft_itoa(d->f.imax));
	mlx_string_put(d->mlx, d->win, 5, 209, 0xffffff, "Cur x1 :");
	mlx_string_put(d->mlx, d->win, 90, 209, 0xffffff, ft_dtoa(d->f.x1, 8));
	mlx_string_put(d->mlx, d->win, 5, 226, 0xffffff, "Cur x2 :");
	mlx_string_put(d->mlx, d->win, 90, 226, 0xffffff, ft_dtoa(d->f.x2, 8));
	mlx_string_put(d->mlx, d->win, 5, 243, 0xffffff, "Cur y1 :");
	mlx_string_put(d->mlx, d->win, 90, 243, 0xffffff, ft_dtoa(d->f.y1, 8));
	mlx_string_put(d->mlx, d->win, 5, 260, 0xffffff, "Cur y2 :");
	mlx_string_put(d->mlx, d->win, 90, 260, 0xffffff, ft_dtoa(d->f.y2, 8));
}

int			expose_hook(void *data)
{
	t_data	*d;

	d = (t_data*)data;
	clear_img(&(d->img));
	if (d->type == 1)
		mandelbrot(d, &(d->f), &(d->img));
	else if (d->type == 2)
		celtic(d, &(d->f), &(d->img));
	else if (d->type == 3)
		burningship(d, &(d->f), &(d->img));
	else if (d->type == 4)
		julia(d, &(d->f), &(d->img));
	else if (d->type == 5)
		mandelbar(d, &(d->f), &(d->img));
	else if (d->type == 6)
		similitree(d, &(d->f), &(d->img));
	else if (d->type == 7)
		unknow(d, &(d->f), &(d->img));
	else if (d->type == 8)
		birdofprey(d, &(d->f), &(d->img));
	display(d);
	return (1);
}
