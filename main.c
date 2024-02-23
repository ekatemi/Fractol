#include "fractol.h"





//input mandelbrot
//input julia <arg1> <arg2>
int main(int argc, char **argv)
{
    t_fractal fractal;

    if ((argc == 2 && !ft_strncmp(argv[1], "mandelbrot", 10)) 
        || (argc == 4 && !ft_strncmp(argv[1], "julia", 5)))
    {
        fractal.name = argv[1];
        fractal_init(&fractal); //inicia window y image
        //fractal_render(&fractal); //modifica image
            /* Put a red pixel in the middle of the window */
        int middle_x = WIDTH / 2;
        int middle_y = HEIGHT / 2;
        int color = 0x00FF0000;
        mlx_pixel_put(fractal.mlx_connection, fractal.mlx_window, middle_x, middle_y, color);
        /* Display the image in the window */
        //mlx_put_image_to_window(fractal.mlx_connection, fractal.mlx_window, fractal.img.img_ptr, 0, 0);
        
        mlx_key_hook(fractal.mlx_window, &handle_keypress, &fractal);
    
        mlx_loop(fractal.mlx_connection); //infinite loop to keep modifying
       // mlx_destroy_window(fractal.mlx_connection, fractal.mlx_window);
        //free(fractal.mlx_connection);
    }
    else
    {
        ft_putstr_fd(ERR_MSG, STDERR_FILENO);
        exit(EXIT_FAILURE);
    }
    return (0);
}