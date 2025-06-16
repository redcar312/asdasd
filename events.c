/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhurtamo <mhurtamo@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 20:03:45 by mhurtamo          #+#    #+#             */
/*   Updated: 2025/03/20 20:03:48 by mhurtamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	close_window(struct t_fractal *fractal)
{
	mlx_destroy_image(fractal->connection, fractal->img.mlx_img);
	mlx_destroy_window(fractal->connection, fractal->window);
	mlx_destroy_display(fractal->connection);
	free(fractal->connection);
	exit(0);
}

int	h_z(int button, int x, int y, struct t_fractal *fractal)
{
	(void)x;
	(void)y;
	if (button == Button4)
	{
		fractal->zoom_value *= 0.90;
		render_fractal(fractal);
	}
	if (button == Button5)
	{
		fractal->zoom_value *= 1.1;
		render_fractal(fractal);
	}
	return (0);
}

int	handle_event(int keysym, struct t_fractal *fractal)
{
	if (keysym == XK_Escape)
	{
		close_window(fractal);
	}
	return (0);
}
