#include "fractol.h"

static void	julia_shift(int x, int y, t_fractal *fractal)
{
	fractal->julia_x = fractal->min_r + (double)x * (fractal->max_r - fractal->min_i) / WIDTH;
	fractal->julia_y = fractal->max_i + (double)y * (fractal->min_i - fractal->max_i) / HEIGHT;
}

static int handle_color(int keycode, t_fractal *data)
{
    if (keycode == 15)
    {
        data->red += 5;
        data->red %= 256;
    }
    else if (keycode == 5)
    {
        data->green += 5;
        data->green %= 256;
    }
    else if (keycode == 11)
    {
        data->blue += 5;
        data->blue %= 256;
    }
    //render_fractal(data);
    return (0);
}

static int handle_movements(int keycode, t_fractal *data)
{
    if (keycode == 126)
        data->move_y -= 0.5 * data->zoom;
    else if (keycode == 125)
        data->move_y += 0.5 * data->zoom;
    else if (keycode == 123)
        data->move_x += 0.5 * data->zoom;
    else if (keycode == 124)
        data->move_x -=0.5 * data->zoom;
    return (0);
}

int handle_keypress(int keycode, t_fractal *data)
{
    if (keycode == 53)
        clean_exit(data);
    else if (keycode == 24)
        data->max_iter += 25;
    else if (keycode == 27)
    {
        if (data->max_iter > 25)
            data->max_iter -= 25;
    }
    handle_color(keycode, data);
    handle_movements(keycode, data);
    render_fractal(data);
    return (0);
}

int handle_mouse_zoom(int button, int x, int y, t_fractal *fractal)
{
    double mouse_real = linear_extr(x, 'r', fractal);
    double mouse_imag = linear_extr(y, 'i', fractal);

    if (button == 5) // Zoom Out
        fractal->zoom_factor = 0.8;
    else if (button == 4) // Zoom In
        fractal->zoom_factor = 1.1;
    else if (button == 2 && !ft_strncmp(fractal->name, "julia", 5))
        julia_shift(x, y, fractal);
    else
        return 0; 

    // Calculate the distance from the mouse point to the center of the fractal
    double distance_x = mouse_real - fractal->move_x;
    double distance_y = mouse_imag - fractal->move_y;

    // Update zoom level
    fractal->zoom *= fractal->zoom_factor;

    // Adjust move_x and move_y to center the fractal on the mouse point
    fractal->move_x = mouse_real - distance_x * fractal->zoom_factor;
    fractal->move_y = mouse_imag - distance_y * fractal->zoom_factor;
    render_fractal(fractal);
    return 0;
}
