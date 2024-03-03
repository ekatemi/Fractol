#include "fractol.h"

/// render fractal mandelbrot

void    mandelbrot_render(t_fractal *fractal)
{
    int x;
    int y;

    double pr; //x
    double pi; //y

    set_minmax(fractal);
    y = 0;
    while(y < HEIGHT)
    {
        pi = fractal->max_i + ((double)(HEIGHT - y) * (fractal->min_i - fractal->max_i) / HEIGHT);
        x = 0;
        while(x < WIDTH)
            {
                pr = fractal->max_r + ((double)(WIDTH - x) * (fractal->min_r - fractal->max_r) / WIDTH);
                if (is_mandelbrot(pr, pi, fractal))
				    my_mlx_pixel_put(fractal, x, y, RED);
				else
				{
					//my_mlx_pixel_put(fractal, x, y, colour_clown(fractal));
					my_mlx_pixel_put(fractal, x, y, colour_pixel(fractal));
				}
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
			//printf("count iterations %d\n", i);
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

// void    julia_render(t_fractal *fractal)
// {
//     int x;
//     int y;

//     double pr; //x
//     double pi; //y

//     y = 0;
//     while(y < HEIGHT)
//     {
//         pi = fractal->max_i + ((double)(HEIGHT - y) * (fractal->min_i - fractal->max_i) / HEIGHT);
//         x = 0;
//         while(x < WIDTH)
//             {
//                 pr = fractal->min_r + ((double)(WIDTH - x) * (fractal->max_r - fractal->min_r) / WIDTH);
//                 if (is_julia(pr, pi, fractal))
// 				    my_mlx_pixel_put(fractal, x, y, RED);
// 				else
// 				{
// 					my_mlx_pixel_put(fractal, x, y, colour_clown(fractal));
// 				}
// 				x++;
//             }
//         y++;
//     }
//     mlx_put_image_to_window(fractal->mlx_connection, fractal->mlx_window, fractal->img.img_ptr, 0, 0);
// }

// int is_julia(double zr, double zi, t_fractal *fractal)
// {
// 	double tmp;
// 	int i;
	
// 	i = 0;
// 	while(i < MAX_ITERATIONS)
// 	{
// 		if ((zr * zr + zi * zi) > 4.0)
// 		{
// 			fractal->count = i;
// 			//printf("count iterations %d\n", i);
// 			return (0);
// 		}
// 		tmp = zr * zr - zi * zi;
// 		zi = 2 * zr * zi - zi * zi + fractal->julia_shift_y;
// 		zr = tmp + fractal->julia_shift_x;
// 		i++;
// 	}
// 		fractal->count = i;
// 	return (1);
// }

// void	julia_shift(int x, int y, t_fractal *fractal)
// {
// 	fractal->julia_shift_x = fractal->min_r + (double)x * (fractal->max_r - fractal->min_i) / WIDTH;
// 	fractal->julia_shift_y = fractal->max_i + (double)y * (fractal->min_i - fractal->max_i) / HEIGHT;
// 	printf("New Julia Parameters: x = %d, y = %d\n", x, y);
// }
