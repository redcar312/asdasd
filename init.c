/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhurtamo <mhurtamo@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 20:04:07 by mhurtamo          #+#    #+#             */
/*   Updated: 2025/03/20 20:04:10 by mhurtamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	init_hooks(struct t_fractal *fractal)
{
	mlx_hook(fractal->window, KeyPress,
		KeyPressMask, handle_event, fractal);
	mlx_hook(fractal->window, ButtonPress,
		ButtonPressMask, h_z, fractal);
	mlx_hook(fractal->window, DestroyNotify,
		StructureNotifyMask, close_window, fractal);
}

static void	init_connection(struct t_fractal *fractal)
{
	fractal->connection = mlx_init();
	if (!fractal->connection)
		print_error("memory allocation error\n");
}

static inline void	init_zoom(struct t_fractal *fractal)
{
	fractal->zoom_value = 2.0;
}

void	init_fractal(struct t_fractal *fractal)
{
	init_connection(fractal);
	fractal->window = mlx_new_window(fractal->connection,
			175, 175, fractal->title);
	if (!fractal->window)
	{
		mlx_destroy_display(fractal->connection);
		free(fractal->connection);
		print_error("memory allocation error\n");
	}
	fractal->img.mlx_img = mlx_new_image(fractal->connection, 175, 175);
	if (!fractal->img.mlx_img)
	{
		mlx_destroy_window(fractal->connection, fractal->window);
		mlx_destroy_display(fractal->connection);
		free(fractal->connection);
		print_error("memory allocation error\n");
	}
	fractal->img.pixels = mlx_get_data_addr(fractal->img.mlx_img,
			&fractal->img.bpp, &fractal->img.line_len, &fractal->img.endian);
	init_zoom(fractal);
	init_hooks(fractal);
}
