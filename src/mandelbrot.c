/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguillon <mguillon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/07 15:18:48 by mguillon          #+#    #+#             */
/*   Updated: 2015/11/17 12:43:07 by mguillon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_color		mandelbrot2(t_complx *c, t_env *e)
{
	int		i;
	double	tmp;
	double	sqrzr;
	double	sqrzi;

	c->z_r = 0;
	c->z_i = 0;
	i = 0;
	sqrzr = c->z_r * c->z_r;
	sqrzi = c->z_i * c->z_i;
	while (((sqrzr + sqrzi) < 4) && (i++ < e->c.iter_max))
	{
		tmp = c->z_r;
		c->z_r = sqrzr - sqrzi + c->c_r;
		c->z_i = (tmp + tmp) * c->z_i + c->c_i;
		sqrzr = c->z_r * c->z_r;
		sqrzi = c->z_i * c->z_i;
	}
	return (ft_fract_color(e, i));
}

int			mandelbrot(t_env *e, int x, int y)
{
	x = 0;
	while (x < WIN_WIDTH)
	{
		e->c.c_r = (x - e->hwwidth) * e->zoom + e->x;
		y = 0;
		while (y < WIN_HEIGHT)
		{
			e->c.c_i = (y - e->hwheight) * e->zoom + e->y;
			ft_pixelput_img(e, x, y, mandelbrot2(&e->c, e));
			y++;
		}
		x++;
	}
	return (1);
}
