#include "fractol.h"

void fractal_init(t_fractal *fractal)
{
    //connection with x server
    fractal->mlx_connection = mlx_init();
        if (fractal->mlx_connection == NULL)
            perror("Malloc failed");
    //create window
    fractal->mlx_window = mlx_new_window(fractal->mlx_connection, WIDTH, HEIGHT, fractal->name);
    if (fractal->mlx_window == NULL)
    {
        mlx_destroy_window(fractal->mlx_connection, fractal->mlx_window);///different
        free(fractal->mlx_connection);
        perror("Malloc failed");
    }
    //create image
    fractal->img.img_ptr = mlx_new_image(fractal->mlx_connection, WIDTH, HEIGHT);
    if (fractal->img.img_ptr == NULL)
    {
        mlx_destroy_window(fractal->mlx_connection, fractal->mlx_window);
        free(fractal->mlx_connection);
        perror("Malloc failed");
    }
    //define pixel??
    fractal->img.pixel_ptr = mlx_get_data_addr(fractal->img.img_ptr, &fractal->img.bpp, &fractal->img.line_len, &fractal->img.endian);
    set_minmax(fractal);
}
