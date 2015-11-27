/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_image.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguillon <mguillon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/07 15:18:13 by mguillon          #+#    #+#             */
/*   Updated: 2015/10/29 18:22:13 by mguillon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		fill_image(t_env *e)
{
	int x;
	int y;

	x = 0;
	y = 0;
	if (e->fractype == 1)
	{
		mandelbrot(e, x, y);
		return (1);
	}
	else if (e->fractype == 2)
	{
		julia(e, x, y);
		return (1);
	}
	else if (e->fractype == 3)
	{
		douady(e, x, y);
		return (1);
	}
	else
		return (0);
}
