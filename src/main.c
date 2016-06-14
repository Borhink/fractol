/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhonore <qhonore@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/11 11:49:57 by qhonore           #+#    #+#             */
/*   Updated: 2016/05/04 17:28:44 by qhonore          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	init_fractols(t_data *data, char *name)
{
	if (!ft_strcmp(name, "mandelbrot"))
		init_mandelbrot(data);
	else if (!ft_strcmp(name, "celtic"))
		init_celtic(data);
	else if (!ft_strcmp(name, "burningship"))
		init_burningship(data);
	else if (!ft_strcmp(name, "julia"))
		init_julia(data);
	else if (!ft_strcmp(name, "mandelbar"))
		init_mandelbar(data);
	else if (!ft_strcmp(name, "similitree"))
		init_similitree(data);
	else if (!ft_strcmp(name, "unknow"))
		init_unknow(data);
	else if (!ft_strcmp(name, "birdofprey"))
		init_birdofprey(data);
}

static void	launch_fractol(t_data *data, char *name)
{
	data->phase = 0;
	data->lum = 1;
	data->shade = 1;
	data->txt = 1;
	data->move = 0;
	init_fractols(data, name);
	mlx_key_hook(data->win, key_hook, (void*)data);
	mlx_hook(data->win, MOTION_NOTIFY, MOTION_MASK, motion_hook, (void*)data);
	mlx_mouse_hook(data->win, mouse_hook, (void*)data);
	mlx_expose_hook(data->win, expose_hook, (void*)data);
	mlx_loop(data->mlx);
}

int			main(int ac, char **av)
{
	t_data	data;

	if (ac != 2)
	{
		ft_putendl("Usage : ./fractol [name]");
		ft_putendl("Fractals list : mandelbrot, julia, celtic, burningship\
, mandelbar, similitree, unknow, birdofprey");
	}
	else if (ac == 2 && ft_strcmp(av[1], "mandelbrot")
			&& ft_strcmp(av[1], "celtic") && ft_strcmp(av[1], "burningship")
			&& ft_strcmp(av[1], "julia") && ft_strcmp(av[1], "mandelbar")
			&& ft_strcmp(av[1], "similitree") && ft_strcmp(av[1], "unknow")
			&& ft_strcmp(av[1], "birdofprey"))
		ft_putendl("Fractals list : mandelbrot, julia, celtic, burningship\
, mandelbar, similitree, unknow, birdofprey");
	else if (!(data.mlx = mlx_init()))
		ft_putendl("Initialization of mlx failed.");
	else if (!(data.win = mlx_new_window(data.mlx, WIN_W, WIN_H, "Fractol")))
		ft_putendl("Creation of the window failed.");
	else if (!(init_img(&data, &(data.img))))
		ft_putendl("Creation of the image failed.");
	else
		launch_fractol(&data, av[1]);
	return (0);
}
