/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhurtamo <mhurtamo@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 17:22:12 by mhurtamo          #+#    #+#             */
/*   Updated: 2025/03/20 20:03:57 by mhurtamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

unsigned int	get_color(int iterations)
{
	unsigned int	red;
	unsigned int	blue;
	unsigned int	green;

	red = (iterations * 5) % 256;
	blue = (iterations * 10) % 256;
	green = (iterations * 15) % 256;
	return ((red << 16) | (green << 8) | blue);
}

void	check_int(long double i)
{
	if (i > INT_MAX || i < INT_MIN)
		print_error("too large or too small argument\n");
}

static void	setup_julia_xy(char **argv, struct t_fractal *fractal)
{
	if (argv[2] && argv[3])
	{
		fractal->j_x = ft_atof(argv[2]);
		fractal->j_y = ft_atof(argv[3]);
		return ;
	}
	print_error("empty argument\n");
}

int	main(int argc, char **argv)
{
	t_fractal	fractal;

	if ((argc == 2 && ft_strncmp(argv[1], "mandelbrot", 10))
		|| (argc == 4 && ft_strncmp(argv[1], "julia", 5)))
	{
		if (ft_strncmp(argv[1], "julia", 5))
			setup_julia_xy(argv, &fractal);
		fractal.title = argv[1];
		init_fractal(&fractal);
		render_fractal(&fractal);
		mlx_loop(fractal.connection);
	}
	else
	{
		print_error("Invalid args use mandelbrot or julia <real> <i>\n");
	}
}
