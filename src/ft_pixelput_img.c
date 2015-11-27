/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pixelput_img.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguillon <mguillon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/07 15:19:16 by mguillon          #+#    #+#             */
/*   Updated: 2015/11/17 12:44:55 by mguillon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_pixelput_img(t_env *e, int x, int y, t_color color)
{
	int	quart_de_pixel;

	quart_de_pixel = y * e->sizeline + x * (e->bpp / 8);
	e->data[quart_de_pixel + 0] = color.b;
	e->data[quart_de_pixel + 1] = color.g;
	e->data[quart_de_pixel + 2] = color.r;
}
