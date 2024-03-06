#include "fractol.h"

//input mandelbrot
//input julia <arg1> <arg2>
int main(int argc, char **argv)
{
    t_fractal fractal;

    if (argc == 2 && argv[1] && (!ft_strncmp(argv[1], "mandelbrot", 10) || !ft_strncmp(argv[1], "julia", 5)))
    {
        ft_putstr_fd(WELCOME_MSG, STDOUT_FILENO);
        fractal.name = argv[1];
        printf("%s\n", argv[1]);
        fractal_init(&fractal); //inicia window y image
        event_init(&fractal);
        render_fractal(&fractal); 
        mlx_loop(fractal.mlx_connection);
    }
    else
    {
        ft_putstr_fd(ERR_MSG, STDERR_FILENO);
        exit(EXIT_FAILURE);
    }
    return (0);
}