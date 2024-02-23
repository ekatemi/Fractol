#include "fractol.h"

int handle_keypress(int keysym, t_fractal *data)
{
    if (keysym == ON_DESTROY)
    {
        mlx_destroy_window(data->mlx_connection, data->mlx_window);
        free(data->mlx_connection);
        exit(1);
    }
    printf("Keypress: %d\n", keysym);
    return (0);
}

///why the program doesnt stop? loop is still going