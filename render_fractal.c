#include "fractol.h"

static void    set_pixel_color(struct t_img *img, int x, int y, int color)
{
    int offset;

    offset = (y * img->len) + (x * (img->bpp / 8));
    *(unsigned int *)(img->pixels + offset) = color;
}

static double map_pixels(double unscaled_value, double new_min, double new_max, double old_min, double old_max)
{
    double  res;

    res = (new_max - new_min) * (unscaled_value - old_min) / (old_max - old_min) + new_min;
    return (res);
}

static void    init_complex_nums(struct t_fractal *fractal, t_complex_num *z, t_complex_num *c)
{
    if(strncmp(fractal->title, "Julia", 5))
    {
        z->x_real = map_pixels(x, (-2 * fractal->zoom_value), (2 * fractal->zoom_value), 0, 500);
        z->y_imaginary = map_pixels(y, (2 * fractal->zoom_value), (-2 * fractal->zoom_value), 0, 500);
        c->x_real = fractal->j_x;
        c->y_imaginary = fractal->j_y;
    }
    else
    {
        z->x_real = 0.0;
        z->y_imaginary = 0.0;
        c.x_real = map_pixels(x, (-2 * fractal->zoom_value), (2 * fractal->zoom_value), 0, 500);
        c.y_imaginary = map_pixels(y, (2 * fractal->zoom_value), (-2 * fractal->zoom_value), 0, 500);

    }
}
7
static void    draw_pixel(int x, int y, struct t_fractal *fractal)
{
    t_complex_num z;
    t_complex_num c;
    int i;

    i = 0;
    init_complex_nums(fractal, z, c);
    while (i < 150)
    {
        z = sum_complex_num(square_complex(z), c);
        if ((z.x_real * z.x_real) + (z.y_imaginary * z.y_imaginary) > 4)
        {
            set_pixel_color(&fractal->img, x, y, 000000);
            return ;
        }
        set_pixel_color(&fractal->img, x, y, "ff00ff");
        i++;
    }

}

void    render_fractal(struct t_fractal *fractal)
{
    int y;
    int x;

    y = -1;
    while (++y < 500)
    {
        x = -1;
        while (++x < 500)
            draw_pixel(x, y, fractal);
        y++;
    }
    mlx_put_image_to_window(fractal->connection, fractal->window, fractal->img.mlx_img, 0, 0);
}