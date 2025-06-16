/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_fractal.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhurtamo <mhurtamo@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 20:04:52 by mhurtamo          #+#    #+#             */
/*   Updated: 2025/03/20 20:04:54 by mhurtamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static inline void	set_pixel_color(struct t_img *img, int x, int y, int color)
{
	unsigned int	*p;

	p = (unsigned int *)(img->pixels
			+ (y * img->line_len) + (x * (img->bpp / 8)));
	*p = color;
}

static inline double	map_pixel(double u_v, double n_min,
	double n_max, double o_max)
{
	double	res;

	res = (n_max - n_min) * u_v / o_max + n_min;
	return (res);
}

static inline void	i_c_n(t_fractal *fractal, t_complex_num *z,
	t_complex_num *c)
{
	z->x_real = c->x_real;
	z->y_imaginary = c->y_imaginary;
	c->x_real = fractal->j_x;
	c->y_imaginary = fractal->j_y;
}

static void	draw_pixel(int x, int y, struct t_fractal *fractal, int is_julia)
{
	t_complex_num	z;
	t_complex_num	c;
	int				i;
	double			zoom;

	i = 0;
	zoom = fractal->zoom_value;
	z.x_real = 0.0;
	z.y_imaginary = 0.0;
	c.x_real = map_pixel((double)x, -zoom, zoom, 175);
	c.y_imaginary = map_pixel((double)y, zoom, -zoom, 175);
	if (is_julia)
		i_c_n(fractal, &z, &c);
	while (i < 50000)
	{
		z = sum_complex_nums(square_complex_num(z), c);
		if ((z.x_real * z.x_real) + (z.y_imaginary * z.y_imaginary) > 4.0)
		{
			set_pixel_color(&fractal->img, x, y, (int)get_color(i));
			return ;
		}
		set_pixel_color(&fractal->img, x, y, 0);
		i++;
	}
}

void	render_fractal(struct t_fractal *fractal)
{
	int	y;
	int	x;
	int	is_julia;

	y = -1;
	is_julia = ft_strncmp(fractal->title, "julia", 5);
	while (++y < 175)
	{
		x = -1;
		while (++x < 175)
			draw_pixel(x, y, fractal, is_julia);
	}
	mlx_put_image_to_window(fractal->connection, fractal->window,
		fractal->img.mlx_img, 0, 0);
}
