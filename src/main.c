/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguillon <mguillon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/07 15:19:32 by mguillon          #+#    #+#             */
/*   Updated: 2015/11/17 12:41:27 by mguillon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		fractol(t_env *e)
{
	fill_image(e);
	mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);
}

static void	ft_image(t_env *e)
{
	if (e->fractype == 2)
	{
		e->c.c_r = 0.285;
		e->c.c_i = 0.01;
	}
	fractol(e);
	mlx_mouse_hook(e->win, mouse_hook, e);
	mlx_hook(e->win, 6, (1L << 6), move_mouse, e);
	mlx_key_hook(e->win, key_hook, e);
	mlx_expose_hook(e->win, expose_hook, e);
	mlx_loop(e->mlx);
	ft_putendl_fd("post_mlx_loop", 2);
	mlx_destroy_image(e->mlx, e->img);
}

static void	ft_initialize(t_env *e)
{
	e->zoom = 1.0 / 256;
	e->x = -0.5;
	e->y = 0;
	e->c.c_r = 0;
	e->c.c_i = 0;
	e->old_x = 0;
	e->old_y = 0;
	e->hwwidth = WIN_WIDTH / 2;
	e->hwheight = WIN_HEIGHT / 2;
	e->c.iter_max = ITERATION_MAX;
	new_image(e);
}

int			main(int argc, char **argv)
{
	t_env	e;
	int		i;
	int		j;

	i = 1;
	j = 0;
	if (argc > 1)
	{
		while (isfractal(argv[i], &e))
		{
			e.mlx = mlx_init();
			e.win = mlx_new_window(e.mlx, WIN_WIDTH, WIN_HEIGHT, argv[1]);
			ft_initialize(&e);
			color_map(&e);
			ft_image(&e);
			ft_putendl_fd("post ft_image", 2);
			j++;
		}
		if (j == 0)
			ft_putendl("Utilisation : ./fractol [mandelbrot] [julia] [douady]");
	}
	else
		ft_putendl("Utilisation : ./fractol [mandelbrot] [julia] [douady]");
	return (0);
}
