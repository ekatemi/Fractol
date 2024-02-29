#include "fractol.h"

//this funk modifyes all pixels and store them in img struct, then we push all this pixels to the window using
//mlx_put_image_to_window function;
void	my_mlx_pixel_put(t_fractal *data, int x, int y, int color)
{
	char	*dst;

	dst = data->img.pixel_ptr + (y * data->img.line_len + x * (data->img.bpp / 8)); ///calculates offset
	*(unsigned int*)dst = color;
}

// void color_image(t_fractal *data, int color)
// {
//     int x;
//     int y;

//     x = 0;
//     while(x < WIDTH)
//     {
//         y = 0;
//         while(y < HEIGHT)
//             {
//                 my_mlx_pixel_put(data, x, y, color);
//                 y++;
//             }
//         x++;
//     }
// }


/// render fractal mandelbrot
void fractal_render(t_fractal *fractal)
{
    int x;
    int y;

    double pr; //x
    double pi; //y

    y = 0;
    while(y < HEIGHT)
    {
        pi = fractal->max_i + ((double)(HEIGHT - y) * (fractal->min_i - fractal->max_i) / HEIGHT);
        x = 0;
        while(x < WIDTH)
            {
                pr = fractal->max_r + ((double)(WIDTH - x) * (fractal->min_r - fractal->max_r) / WIDTH);
                if (is_mandelbrot(pr, pi, fractal) == 0)
				    my_mlx_pixel_put(fractal, x, y, RED);
			    // else
				//     my_px_put(f->img_data, x, y, create_trgb(0, 0, 0, 0));
                x++;
            }
        y++;
    }
    mlx_put_image_to_window(fractal->mlx_connection, fractal->mlx_window, fractal->img.img_ptr, 0, 0);
}
//z = z * z + c
//z = a + bi = z * z = (a + b) * (a + b) = a * a - b * b + 2abi
int	is_mandelbrot(double cr, double ci, t_fractal *fractal)
{
	double	zr;
	double	zi;
	double	tmp;
	int		i;

	i = 0;
	zr = 0;
	zi = 0;
	while (i <= MAX_ITERATIONS)
	{
		if ((zr * zr + zi * zi) > 4.0)
		{
			fractal->count = i;
			return (0);
		}
		tmp = 2 * zr * zi + ci;
		zr = zr * zr - zi * zi + cr;
		zi = tmp;
		i++;
	}
		fractal->count = i;
	return (1);
}


