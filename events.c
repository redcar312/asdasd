#include "fractol.h"

int   close_window(struct t_fractal *fractal)
{
    mlx_destroy_image(fractal->connection, fractal->img.mlx_img)
    mlx_destroy_window(fractal->connection, fractal->window);
    mlx_destroy_display(fractal->connection);
    free(fractal->connection);
    exit(0);
}

int handle_zoom(int button, struct t_fractal *fractal)
{
    if (button == Button5)
        fractal->zoom_value *= 0.99;
    if (button == Button4)
        fractal->zoom_value *= 1.01;
    render_fracal(fractal);
    return (0);
}

int handle_event(int keysym, struct t_fractal *fractal)
{
    if (keysym == XK_ESCAPE)
        close_window(fractal);
}
