/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguillon <mguillon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/07 15:17:13 by mguillon          #+#    #+#             */
/*   Updated: 2015/10/29 18:06:22 by mguillon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# define WIN_WIDTH 1000
# define WIN_HEIGHT 1000
# define ITERATION_MAX 100
# define N_COLORS 1536
# include <mlx.h>
# include <math.h>
# include "libft.h"

typedef struct		s_color
{
	int				r;
	int				g;
	int				b;
}					t_color;

typedef struct		s_complx
{
	long double		c_r;
	long double		c_i;
	long double		z_r;
	long double		z_i;
	double			iter_max;
	t_color			tab[N_COLORS];
}					t_complx;

typedef struct		s_env
{
	void			*mlx;
	void			*win;
	void			*img;
	char			*data;
	int				bpp;
	int				sizeline;
	int				endian;
	int				fractype;
	int				hwwidth;
	int				hwheight;
	int				mid_imaginaire;
	int				mid_reel;
	long double		zoom;
	long double		x;
	long double		y;
	long double		old_x;
	long double		old_y;
	t_complx		c;
}					t_env;

void				color_map(t_env *e);
t_color				ft_fract_color(t_env *e, int iter);
void				ft_pixelput_img(t_env *e, int x, int y, t_color color);
int					isfractal(char *argv, t_env *e);
int					mouse_hook(int button, int x, int y, t_env *e);
int					move_mouse(int x, int y, t_env *e);
void				fractol(t_env *e);
int					fill_image(t_env *e);
void				new_image(t_env *e);
int					key_hook(int keycode, t_env *e);
int					expose_hook(t_env *e);
int					mandelbrot(t_env *e, int x, int y);
int					julia(t_env *e, int x, int y);
int					douady(t_env *e, int x, int y);

#endif
