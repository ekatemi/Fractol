#include "fractol.h"

static void data_init(t_fractal *fractal)
{
    //for hooks
    if (!ft_strncmp(fractal->name, "julia", 5))
        fractal->move_x = 0.0;
    else
        fractal->move_x = -0.5;
    fractal->move_y = 0.0;
    fractal->julia_x = -1.261;
    fractal->julia_y = -0.025;
    fractal->zoom = 1.0;
    // iter
    fractal->max_iter = 100;
    //color
    fractal->red = 255;
    fractal->green = 0;
    fractal->blue = 0;
    fractal->zoom_factor = 1.0;
}

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
    //define pixel
    fractal->img.pixel_ptr = mlx_get_data_addr(fractal->img.img_ptr, &fractal->img.bpp, &fractal->img.line_len, &fractal->img.endian);
    data_init(fractal);
    //event_init(fractal);
}

int clean_exit(t_fractal *data)
{
    mlx_destroy_window(data->mlx_connection, data->mlx_window);
    free(data->mlx_connection); //innecessary maybe
    exit(EXIT_SUCCESS);
}

void event_init(t_fractal *fractal)
{
    mlx_key_hook(fractal->mlx_window, handle_keypress, fractal);
    mlx_hook(fractal->mlx_window, ON_DESTROY, 0, clean_exit, fractal);
    mlx_mouse_hook(fractal->mlx_window, handle_mouse_zoom, fractal);
}