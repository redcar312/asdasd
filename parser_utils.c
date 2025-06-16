/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhurtamo <mhurtamo@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 19:05:32 by mhurtamo          #+#    #+#             */
/*   Updated: 2025/03/20 20:04:42 by mhurtamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	print_error(char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		exit(1);
	while (str[i])
	{
		write(2, &str[i], 1);
		i++;
	}
	exit(1);
}

int	ft_strncmp(char *a, char *b, size_t n)
{
	size_t	i;

	if (!a || !b || n == 0)
		return (0);
	i = 0;
	while ((a[i] || b[i]) && i < n)
	{
		if (a[i] != b[i])
			return (0);
		i++;
	}
	return (1);
}

static int	is_digit(int c)
{
	return ((c >= '0' && c <= '9'));
}

static	int	check_sign(char c)
{
	if (c == '-')
	{
		return (-1);
	}
	else if (c == '+' || is_digit(c))
		return (1);
	print_error("invalid arg\n");
	return (1);
}

double	ft_atof(char *str)
{
	long	integer;
	double	fraction;
	double	multi;
	int		sign_val;

	multi = 1;
	integer = 0;
	sign_val = check_sign(*str);
	fraction = 0.0;
	if (!is_digit(*str))
		str++;
	while (is_digit(*str))
		integer = (integer * 10) + (*str++ - 48);
	if (*str == '.')
		str++;
	check_int((long double)integer);
	while (*str)
	{
		multi /= 10;
		if (!is_digit(*str))
			print_error("Invalid coordinate\n");
		fraction += (*str++ - 48) * multi;
	}
	return (((double)integer + fraction) * sign_val);
}
