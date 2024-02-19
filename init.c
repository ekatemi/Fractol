#include "fractol.h"

void fractal_init(t_fractal *fractal)
{
    fractal->mlx_connection = mlx_init();
        if (fractal->mlx_connection == NULL);
            perror("Malloc failed");
    fractal->mlx_window = mlx_new_window(fractal->mlx_connection, WIDTH, HEIGHT, fractal->name);
    if (fractal->mlx_window == NULL)
    {
        mlx_destroy_window(fractal->mlx_connection, fractal->mlx_window);///different
        free(fractal->mlx_connection);
        perror("Malloc failed");
    }
    fractal->img.img_ptr = mlx_new_image(fractal->mlx_connection, WIDTH, HEIGHT);
    if (fractal->img.img_ptr == NULL)
    {
        mlx_destroy_window(fractal->mlx_connection, fractal->mlx_window);
        free(fractal->mlx_connection);
        perror("Malloc failed");
    }
}