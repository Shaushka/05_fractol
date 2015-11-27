/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguillon <mguillon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/07 15:18:37 by mguillon          #+#    #+#             */
/*   Updated: 2015/10/29 18:04:20 by mguillon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	move_around(int keycode, t_env *e)
{
	if (keycode == 124)
	{
		e->x -= 1.0 / 100;
		fractol(e);
	}
	if (keycode == 123)
	{
		e->x += 1.0 / 100;
		fractol(e);
	}
	if (keycode == 125)
	{
		e->y -= 1.0 / 100;
		fractol(e);
	}
	if (keycode == 126)
	{
		e->y += 1.0 / 100;
		fractol(e);
	}
}

int			key_hook(int keycode, t_env *e)
{
	if (keycode == 53)
		exit(0);
	if (keycode == 69)
	{
		e->zoom /= 1.5;
		fractol(e);
	}
	if (keycode == 78)
	{
		e->zoom *= 1.5;
		fractol(e);
	}
	if (keycode == 123 || keycode == 124)
		move_around(keycode, e);
	if (keycode == 125 || keycode == 126)
		move_around(keycode, e);
	return (0);
}
