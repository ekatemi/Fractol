#include "fractol.h"

//input mandelbrot
//input julia <arg1> <arg2>
int main(int argc, char **argv)
{
    t_fractal fractal;

    if ((argc == 2 && !ft_strncmp(argv[1], "mandelbrot", 10)) 
        || (argc == 4 && !ft_strncmp(argv[1], "julia", 5)))
    {
        ft_putstr_fd(WELCOME_MSG, STDOUT_FILENO);
        fractal.name = argv[1];
        if (!ft_strncmp(fractal.name, "julia", 5))
		{
			fractal.julia_shift_x = ft_atod(argv[2]);
			fractal.julia_shift_y = ft_atod(argv[3]);
		}
        fractal_init(&fractal); //inicia window y image
        mandelbrot_render(&fractal); //modifica image
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