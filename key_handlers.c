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
    {
        if (data->max_iter > 25)
        {
            data->max_iter -= 25;
            printf("max iter %d\n", data->max_iter);
        }
    }
    else if (keycode == 15)
    {
        data->red += 4;
        data->red %= 256;

    }
    else if (keycode == 5)
    {
        data->green += 4;
        data->green %= 256;

    }
    else if (keycode == 11)
    {
        data->blue += 4;
        data->blue %= 256;
    }

    printf("Keypress: %d\n", keycode);
    fractal_render(data);
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
    fractal_render(fractal);
    return 0;
}

void	julia_shift(int x, int y, t_fractal *fractal)
{
	fractal->julia_x = fractal->min_r + (double)x * (fractal->max_r - fractal->min_i) / WIDTH;
	fractal->julia_y = fractal->max_i + (double)y * (fractal->min_i - fractal->max_i) / HEIGHT;
	printf("New Julia Parameters: x = %d, y = %d\n", x, y);
}