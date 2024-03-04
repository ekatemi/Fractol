#include "fractol.h"

int handle_keypress(int keycode, t_fractal *data)
{
    if (keycode == 53 || keycode == ON_DESTROY)
    {
        clean_exit(data);
        // mlx_destroy_window(data->mlx_connection, data->mlx_window);
        // free(data->mlx_connection);
        // exit(1);
    }
    else if (keycode == 126)
        data->move_y += 0.5 * data->zoom;
    else if (keycode == 125)
        data->move_y -= 0.5 * data->zoom;
    else if (keycode == 123)
        data->move_x += 0.5 * data->zoom;
    else if (keycode == 124)
        data->move_x -=0.5 * data->zoom;
    else if (keycode == 24)
        data->max_iter += 25;
    else if (keycode == 27)
        data->max_iter -= 25;
    //printf("Keypress: %d, move_x %f, move_y %f\n", keycode, data->move_x, data->move_y);
    if (!ft_strncmp(data->name, "mandelbrot", 10))
        mandelbrot_render(data);
    else if (!ft_strncmp(data->name, "julia", 5))
        julia_render(data);
    return (0);
}
//int (*f)(int button, int x, int y, void *param)
int handle_mouse(int button, int x, int y, t_fractal *fractal) //need to do someting with x and y
{
    (void)x;
    (void)y; 
    if (button == 5)
    {
        fractal->zoom *= 0.9;
    }
    else if (button == 4)
        fractal->zoom *= 1.1;
    else if (button == 2 && !ft_strncmp(fractal->name, "julia", 5))
         julia_shift(x, y, fractal);
    if (!ft_strncmp(fractal->name, "julia", 5))
        mandelbrot_render(fractal);
    else if (!ft_strncmp(fractal->name, "julia", 5))
        julia_render(fractal);
    return 0;
}