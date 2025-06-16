/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mathops.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhurtamo <mhurtamo@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 20:04:25 by mhurtamo          #+#    #+#             */
/*   Updated: 2025/03/20 20:04:28 by mhurtamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_complex_num	sum_complex_nums(struct t_complex_num z1,
	struct t_complex_num z2)
{
	t_complex_num	res;

	res.x_real = z1.x_real + z2.x_real;
	res.y_imaginary = z1.y_imaginary + z2.y_imaginary;
	return (res);
}

t_complex_num	square_complex_num(struct t_complex_num z)
{
	t_complex_num	res;

	res.x_real = (z.x_real * z.x_real) - (z.y_imaginary * z.y_imaginary);
	res.y_imaginary = 2 * z.x_real * z.y_imaginary;
	return (res);
}
