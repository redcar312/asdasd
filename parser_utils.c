/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhurtamo <mhurtamo@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 19:05:32 by mhurtamo          #+#    #+#             */
/*   Updated: 2025/03/01 19:05:35 by mhurtamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void    print_error(char *str)
{
    size_t  i;

    i = 0;
    if (!str)
        exit(1);
    while(str[i])
    {
        write(2, &str[i], 1);
        i++;
    }
    exit(1);
}

int ft_strncmp(char *a, char *b, size_t n)
{
    size_t  i;

    if (!a || !b || n == 0)
        return (0);
    i = 0;
    while((a[i] || b[i]) && i < n)
    {
        if (a[i] != b[i])
            return(0);
        i++;
    }
    return (1);
}

int is_digit(int c)
{
    return()
}

double ft_atof(char *str)
{
    long   integer;
    double  fraction;
    double  multi;
    int sign_val;

    multi = 1;
    integer = 0;
    sign_val = 1;
    if (*str == '-')
        sign_val *= -1;
    while (is_digit(*str))
        integer = (integer * 10) + (*str++ - 48);
    if (*str == '.')
        str++;
    while (*str)
    {
        multi /= 10;
        if (!is_digit(*str))
            print_error("Invalid coordinate");
        fraction += (s++ - 48) * multi;
    }
    return ((integer + fraction) * sign_val);
}