#include "fractol.h"

int handle_keypress(int keycode, t_fractal *data)
{
    if (keycode == ON_EXIT)
    {
        mlx_destroy_window(data->mlx_connection, data->mlx_window);
        free(data->mlx_connection);
        exit(1);
    }
    printf("Keypress: %d\n", keycode);
    return (0);
}

