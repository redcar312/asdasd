#include "fractol.h"

t_complex_num   sum_complex_nums(struct t_complex_num z1, struct t_complex_num z2)
{
    t_complex_num   res;

    res.x = z1.x + z2.x;
    res.y = z1.y + z2.y;

    return (res);
}

t_complex_num   square_complex_num(strcut t_complex_num z)
{
    t_complex_num   res;

    res.x = (z.x * z.x) - (z.y * z.y);
    res.y = 2 * x * y;
    return (res);
}