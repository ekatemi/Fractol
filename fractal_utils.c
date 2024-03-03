#include "fractol.h"

//this funk modifyes all pixels and store them in img struct, then we push all this pixels to the window using
//mlx_put_image_to_window function;
void	my_mlx_pixel_put(t_fractal *data, int x, int y, int color)
{
	char	*dst;

	dst = data->img.pixel_ptr + (y * data->img.line_len + x * (data->img.bpp / 8)); ///calculates offset
	*(unsigned int*)dst = color;
}

void set_minmax(t_fractal *fractal)
{
fractal->min_r = -2 * fractal->zoom + fractal->move_x;
fractal->max_r = +2 * fractal->zoom + fractal->move_x;
//fractal->max_r = fractal->min_r * -1 * WIDTH / HEIGHT + fractal->move_x;
fractal->min_i = -2 * fractal->zoom + fractal->move_y;
fractal->max_i = +2 * fractal->zoom + fractal->move_y;
//fractal->max_i = fractal->min_i * -1 * HEIGHT / WIDTH + fractal->move_y;
}






