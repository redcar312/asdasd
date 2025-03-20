/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia_calcs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhurtamo <mhurtamo@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 19:00:48 by mhurtamo          #+#    #+#             */
/*   Updated: 2025/03/01 19:00:51 by mhurtamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

double mod2(struct t_fractal *t_fractal fractal)
{
	double	res;

	res = fractal->x + fractal->x * fractal->y + fractal->y;
	return (res);
}

double	calc_real(struct *t_fractal fractal)
{
	double	res;
	
	res = fractal->x - fractal->x * fractal->y - fractal->y;
	return (res);

}

double	calc_imaginary(struct *t_fractal fractal)
{
	double res;

	res = 2.0 * fractal->x - fractal->y;
	return (res);

}

