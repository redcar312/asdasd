/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhurtamo <mhurtamo@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 19:01:24 by mhurtamo          #+#    #+#             */
/*   Updated: 2025/03/01 19:01:26 by mhurtamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <unistd.h>
# include <stdlib.h>
# include <math.h>
# include <X11/X.h>
# include <X11/keysym.h>
# include "minilibx-linux/mlx.h"
# include <limits.h>

typedef struct t_img
{
	void	*mlx_img;
	char	*pixels;
	int		line_len;
	int		bpp;
	int		endian;
}	t_img;

typedef struct t_complex_num
{
	double	x_real;
	double	y_imaginary;

}	t_complex_num;

typedef struct t_fractal
{
	void	*connection;
	void	*window;
	char	*title;
	double	j_x;
	double	j_y;
	double	zoom_value;
	t_img	img;
}	t_fractal;

int				close_window(struct t_fractal *fractal);
int				h_z(int button, int x, int y, struct t_fractal *fractal);
int				handle_event(int keysym, struct t_fractal *fractal);
void			init_fractal(struct t_fractal *fractal);
t_complex_num	sum_complex_nums(struct t_complex_num z1,
					struct t_complex_num z2);
t_complex_num	square_complex_num(struct t_complex_num z);
double			ft_atof(char *str);
int				ft_strncmp(char *a, char *b, size_t n);
void			print_error(char *str);
void			render_fractal(struct t_fractal *fractal);
void			check_int(long double i);
unsigned int	get_color(int iterations);
#endif
