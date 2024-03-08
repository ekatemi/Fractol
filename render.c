
#include "fractol.h"

void	render_fractal(t_fractal *data)
{
	set_minmax(data);
	if (!ft_strncmp(data->name, "mandelbrot", 10))
		render_mandelbrot(data);
	if (!ft_strncmp(data->name, "julia", 5))
		render_julia(data);
}