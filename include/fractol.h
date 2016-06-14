/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhonore <qhonore@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/03 00:17:17 by qhonore           #+#    #+#             */
/*   Updated: 2016/03/17 06:07:31 by qhonore          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdlib.h>
# include <math.h>
# include "libft.h"
# include "mlx.h"

# define WIN_W 1000
# define WIN_H 1000

# define MOTION_MASK (1L<<6)
# define MOTION_NOTIFY 6

typedef struct s_vect2d		t_vect2d;
typedef struct s_vect2i		t_vect2i;
typedef struct s_rgb		t_rgb;
typedef struct s_img		t_img;
typedef struct s_data		t_data;
typedef struct s_fractal	t_fractal;

struct		s_vect2d
{
	double	x;
	double	y;
};

struct		s_vect2i
{
	int		x;
	int		y;
};

struct		s_rgb
{
	int		r;
	int		g;
	int		b;
};

struct		s_img
{
	void	*i;
	char	*d;
	int		bpp;
	int		sl;
	int		edn;
};

struct		s_fractal
{
	double		x1;
	double		y1;
	t_vect2i	p;
	double		x2;
	double		y2;
	long		zoom;
	int			imax;
	double		cr;
	double		ci;
	double		zr;
	double		zi;
	int			i;
	double		tmp;
};

struct		s_data
{
	void		*mlx;
	void		*win;
	t_img		img;
	t_fractal	f;
	int			type;
	double		lum;
	double		phase;
	double		shade;
	int			txt;
	int			move;
};

t_vect2d	set_vect2d(double x, double y);
t_vect2i	set_vect2i(int x, int y);
t_rgb		set_rgb(int r, int g, int b);
t_rgb		rainbow(t_data *d);
int			init_img(t_data *data, t_img *img);
void		img_put_pixel(t_data *d, t_img *i, t_vect2i p, t_rgb c);
int			key_hook(int key, void *data);
int			mouse_hook(int button, int x, int y, void *data);
int			expose_hook(void *data);
int			motion_hook(int x, int y, void *data);
void		display(t_data *d);
void		zoom_in(int x, int y, t_data *d);
void		zoom_out(int x, int y, t_data *d);
void		ft_move(t_data *d, int key);
void		change_color(t_data *d, int key);
void		change_fractal(t_data *d, int key);
void		init_mandelbrot(t_data *d);
void		init_celtic(t_data *d);
void		init_burningship(t_data *d);
void		init_julia(t_data *d);
void		init_mandelbar(t_data *d);
void		init_unknow(t_data *d);
void		init_birdofprey(t_data *d);
void		mandelbrot(t_data *d, t_fractal *f, t_img *i);
void		celtic(t_data *d, t_fractal *f, t_img *i);
void		burningship(t_data *d, t_fractal *f, t_img *i);
void		julia(t_data *d, t_fractal *f, t_img *i);
void		mandelbar(t_data *d, t_fractal *f, t_img *i);
void		init_similitree(t_data *d);
void		similitree(t_data *d, t_fractal *f, t_img *i);
void		unknow(t_data *d, t_fractal *f, t_img *i);
void		birdofprey(t_data *d, t_fractal *f, t_img *i);

#endif
