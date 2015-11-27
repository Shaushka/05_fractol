/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   douady.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguillon <mguillon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/07 15:18:00 by mguillon          #+#    #+#             */
/*   Updated: 2015/10/29 18:21:33 by mguillon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_color	douady2(t_complx *c, t_env *e)
{
	int		i;
	double	tmp;

	c->c_r = -0.123;
	c->c_i = 0.745;
	i = 0;
	while (((c->z_r * c->z_r + c->z_i * c->z_i) < 4) && (i++ < ITERATION_MAX))
	{
		tmp = c->z_r;
		c->z_r = c->z_r * c->z_r - c->z_i * c->z_i + c->c_r;
		c->z_i = 2 * tmp * c->z_i + c->c_i;
	}
	return (ft_fract_color(e, i));
}

int		douady(t_env *e, int x, int y)
{
	x = 0;
	while (x < WIN_WIDTH)
	{
		y = 0;
		while (y < WIN_HEIGHT)
		{
			e->c.z_r = (x - e->hwwidth) * e->zoom + e->x;
			e->c.z_i = (y - e->hwheight) * e->zoom + e->y;
			ft_pixelput_img(e, x, y, douady2(&e->c, e));
			y++;
		}
		x++;
	}
	return (1);
}
