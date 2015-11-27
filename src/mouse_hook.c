/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_hook.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguillon <mguillon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/07 15:19:41 by mguillon          #+#    #+#             */
/*   Updated: 2015/10/29 18:18:16 by mguillon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double	ft_fabs(double a)
{
	if (a < 0)
		return (-a);
	return (a);
}

int		move_mouse(int x, int y, t_env *e)
{
	if (e->fractype == 2)
	{
		if (x - e->old_x > 10)
		{
			e->c.c_r += 1.0 / 100;
			e->old_x = x;
		}
		else if (x - e->old_x < -10)
		{
			e->c.c_r -= 1.0 / 100;
			e->old_x = x;
		}
		else if (y - e->old_y > 10)
		{
			e->c.c_i += 1.0 / 100;
			e->old_y = y;
		}
		else if (y - e->old_y < -10)
		{
			e->c.c_i -= 1.0 / 100;
			e->old_y = y;
		}
		fractol(e);
	}
	return (0);
}

int		mouse_hook(int button, int x, int y, t_env *e)
{
	e->x += (x - e->hwwidth) * e->zoom;
	e->y += (y - e->hwheight) * e->zoom;
	if (button == 4)
	{
		if (e->zoom > ft_fabs(x) * 1e-16 && e->zoom > ft_fabs(y) * 1e-16)
			e->zoom /= 2;
	}
	if (button == 5)
		e->zoom *= 2;
	fractol(e);
	return (0);
}
