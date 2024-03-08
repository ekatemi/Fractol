#include "fractol.h"

/*modifyes all pixels and store them in img struct, then we push all this pixels to the window using
mlx_put_image_to_window function */
void	my_mlx_pixel_put(t_fractal *data, int x, int y, int color)
{
	char	*dst;

	dst = data->img.pixel_ptr + (y * data->img.line_len + x * (data->img.bpp / 8));
	*(unsigned int*)dst = color;
}
//set margins -2 +2 to x and y
void set_minmax(t_fractal *fractal)
{
fractal->min_r = -2 * fractal->zoom + fractal->move_x;
fractal->max_r = +2 * fractal->zoom + fractal->move_x;
fractal->min_i = -2 * fractal->zoom + fractal->move_y;
fractal->max_i = +2 * fractal->zoom + fractal->move_y;
}
//linear translate from 0 - WIDTH to NewMin - NewMax

double linear_extr(int n, char c, t_fractal *fractal)
{
	double res;

	res = 0.0;
	if (c == 'r') //real (x)
		res = fractal->min_r + ((double)n / WIDTH) * (fractal->max_r - fractal->min_r);
	else if (c == 'i') //img (y)
		res = fractal->min_i + ((double)(HEIGHT - n) / HEIGHT) * (fractal->max_i - fractal->min_i);
	return (res);
}

    // double mouse_real = fractal->min_r + ((double)x / WIDTH) * (fractal->max_r - fractal->min_r);
    // double mouse_imag = fractal->min_i + ((double)(HEIGHT - y) / HEIGHT) * (fractal->max_i - fractal->min_i);





