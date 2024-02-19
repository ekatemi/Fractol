#include "fractol.h"

// int main(void)
// {
//     void *mlx;
 
//     mlx = mlx_init();
//     if (!mlx)
//     {
//     // Handle the error.
//         return (1);
//     }
//     // Do some cool graphical stuff here…
//     // Clean up before exiting. The Display struct and the xvar struct
//     mlx_destroy_display(mlx);
//     free(mlx);
//     return (0);
// }

//input mandelbrot
//input julia <arg1> <arg2>
int main(int argc, char **argv)
{
    t_fractal fractal;
    if ((argc == 2 && !ft_strncmp(argv[1], "mandelbrot", 10)) 
        || (argc == 4 && !ft_strncmp(argv[1], "julia", 5)))
    {
        printf("START");//to check if it is correct, del later
        fractal.name = argv[1];
        fractal_init(&fractal);
        fractal_render(&fractal);
        mlx_loop(fractal.mlx_connection);
    }
    else
    {
        ft_putstr_fd(ERR_MSG, STDERR_FILENO);
        exit(EXIT_FAILURE);
    }
}