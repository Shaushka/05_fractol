/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isfractal.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguillon <mguillon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/07 15:18:26 by mguillon          #+#    #+#             */
/*   Updated: 2015/08/11 13:29:15 by mguillon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	isfractal(char *argv, t_env *e)
{
	if (!ft_strcmp(argv, "mandelbrot"))
	{
		e->fractype = 1;
		return (1);
	}
	else if (!ft_strcmp(argv, "julia"))
	{
		e->fractype = 2;
		return (1);
	}
	else if (!ft_strcmp(argv, "douady"))
	{
		e->fractype = 3;
		return (1);
	}
	else
	{
		return (0);
	}
}
