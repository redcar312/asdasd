
#include "fractol.h"

static void init_hooks(struct t_fractal *fractal)
{
    mlx_hook(fractal->window, Keypress, KeyPressMask, handle_event, fractal);
    mlx_hook(fractal->window, ButtonPress, ButtonPressMask, handle_zoom, fractal);
    mlx_hook(fractal->window, DestroyNotify, StructureNotifyMask, close_window, fractal)
}

static void    init_connection(struct t_fractal *fractal)
{
    fractal->connection = mlx_init();
    if (!fractal->connection)
        print_error("memory allocation error");
}

void init_fractal(struct t_fractal *fractal) 
{
    init_connection(fractal);
    fractal->window = mlx_new_window(fractal->connection, 500, 500, fractal->title);
    if (!fractal->window)
    {
        mlx_destroy_display(fractal->connection);
        free(fractal->connection);
        print_error("memory allocation error");
    };
    fractal->img.mlx_img = mlx_new_image(fractal->connection, 500, 500);
    if (!fractal->img.mlx_img)
    {
        mlx_destroy_window(fractal->window);
        mlx_destroy_display(fractal->connection);
        free(fractal->connection);
        print_error("memory allocation error");

    }
    fractal->img.pixels = mlx_get_data_addr(fractal->img.mlx_img, fractal->img.bpp, fractal->img.line_len, fractal->img.endian)
}