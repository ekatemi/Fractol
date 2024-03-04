#include "fractol.h"

//input mandelbrot
//input julia <arg1> <arg2>
int main(int argc, char **argv)
{
    t_fractal fractal;

    if ((argc == 2 && !ft_strncmp(argv[1], "mandelbrot", 10)) 
        || (argc == 4 && !ft_strncmp(argv[1], "julia", 5)))
    // if (argc == 2 && (!ft_strncmp(argv[1], "mandelbrot", 10) || !ft_strncmp(argv[1], "julia", 5)))
    {
        ft_putstr_fd(WELCOME_MSG, STDOUT_FILENO);
        fractal.name = argv[1];
   
        if (!ft_strncmp(fractal.name, "julia", 5))
		{
			fractal.julia_x = ft_atod(argv[2]);///falta map it to u
			fractal.julia_y = ft_atod(argv[3]); ///not working properly
            printf("x julia %f y julia %f\n", fractal.julia_x, fractal.julia_x);
		}
        fractal_init(&fractal); //inicia window y image
        fractal_render(&fractal);
        event_init(&fractal);
        mlx_loop(fractal.mlx_connection);
    }
    else
    {
        ft_putstr_fd(ERR_MSG, STDERR_FILENO);
        exit(EXIT_FAILURE);
    }
    return (0);
}