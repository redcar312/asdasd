/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhurtamo <mhurtamo@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 17:22:12 by mhurtamo          #+#    #+#             */
/*   Updated: 2025/03/01 17:29:10 by mhurtamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void    setup_julia_xy(char **argv, struct t_fractal *fractal)
{
    if(argv[2] && argv[3])
        {
            fractal->j_x = ft_atof(argv[2]);
            fractal->j_y = ft_atof(argv[3]);
            return ;
        }
        print_error("empty argument");
}

int	main(int argc, char **argv)
{
    t_fractal   fractal;

    if ((argc == 2 && ft_strncmp(argv[1], "mandelbrot", 10))
        || (argc == 4 && (ft_strncmp(argv[1], "julia", 5)))
    {
        if(ft_strncmp(argv[1], "julia", 5))
            setup_julia_xy(argv, &fractal);
        init_fractal(&fractal);
        render_fractal(&fractal);
        mlx_loop(&fractal.connection);
    }
    else
    {
        print_error("Invalid arguments correct args mandelbrot or julia <real> <i>");
    }
}


