/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguillon <mguillon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/11 16:45:47 by mguillon          #+#    #+#             */
/*   Updated: 2015/11/17 12:42:31 by mguillon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		color_map(t_env *e)
{
	int		i;

	i = 0;
	while (i < 256)
	{
		e->c.tab[i].r = 0;
		e->c.tab[i].g = 0;
		e->c.tab[i].b = i;
		e->c.tab[i + 256].r = i;
		e->c.tab[i + 256].g = i;
		e->c.tab[i + 256].b = 255 - i;
		e->c.tab[i + 512].r = 255;
		e->c.tab[i + 512].g = 255;
		e->c.tab[i + 512].b = i;
		e->c.tab[i + 768].r = 255;
		e->c.tab[i + 768].g = 255;
		e->c.tab[i + 768].b = 255 - i;
		e->c.tab[i + 1024].r = 255 - i;
		e->c.tab[i + 1024].g = 255 - i;
		e->c.tab[i + 1024].b = i;
		e->c.tab[i + 1280].r = 0;
		e->c.tab[i + 1280].g = 0;
		e->c.tab[i + 1280].b = 255 - i;
		i++;
	}
}

t_color		ft_fract_color(t_env *e, int iter)
{
	double	nu;

	if (iter < e->c.iter_max && iter >= 0)
	{
		nu = e->c.z_r * e->c.z_r + e->c.z_i * e->c.z_i;
		nu = log(log(sqrt(nu))) / log(2);
		nu = iter - nu;
		nu = ((N_COLORS - 1) * nu) / e->c.iter_max;
		if ((int)nu < 0 || (int)nu > N_COLORS - 1)
			return (e->c.tab[0]);
		else
			return (e->c.tab[(int)nu]);
	}
	else
		return (e->c.tab[0]);
}
