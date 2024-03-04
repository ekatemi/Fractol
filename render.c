#include "fractol.h"



// int	is_mandelbrot(double cr, double ci, t_fractal *fractal)
// {
// 	double	zr;
// 	double	zi;
// 	double	tmp;
// 	int		i;

// 	i = 0;
// 	zr = 0;
// 	zi = 0;
// 	while (i <= fractal->max_iter)
// 	{
// 		if ((zr * zr + zi * zi) > 4.0)
// 		{
// 			fractal->count = i;
// 			//printf("count iterations %d\n", i);
// 			return (0);
// 		}
// 		tmp = 2 * zr * zi + ci;
// 		zr = zr * zr - zi * zi + cr;
// 		zi = tmp;
// 		i++;
// 	}
// 		fractal->count = i;
// 	return (1);
// }

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
// 	while(i < fractal->max_iter)
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

static void	toggle_fractal(t_complex *z, t_complex *c, t_fractal *fractal)
{	
	if (!ft_strncmp(fractal->name, "julia", 5))
	{
		c->x = fractal->julia_x;
		c->y = fractal->julia_y;
	}
	else
	{
		fractal->move_x = -0.5;
		c->x = z->x;
		c->y = z->y;
	}
}

static void handle_pixel(int x, int y, t_fractal *fractal)
{
	t_complex z;
	t_complex c;
	int i;
	//int color;

	i = 0;
	//scale real x,y to fractal range set in minmax function
	z.x = (fractal->max_r - fractal->min_r) * (x - 0) / WIDTH + fractal->min_r;
	z.y = (fractal->max_i - fractal->min_i) * (y - 0) / HEIGHT + fractal->min_i;
	//choose fractal
	toggle_fractal(&z, &c, fractal);
	while (i <= fractal->max_iter)
	{
		//z 
		z = sum_complex(square_complex(z), c);
		if ((z.x * z.x) + (z.y * z.y) > 4)
		{
			fractal->count = i;
			my_mlx_pixel_put(fractal, x, y, colour_pixel(fractal));
			return ;
		}
		i++;	
	}
	// we are inside mandelbrot
	my_mlx_pixel_put(fractal, x, y, WHITE);
}


void    fractal_render(t_fractal *fractal)
{
    int x;
    int y;

    y = 0;
	set_minmax(fractal);
    while(y < HEIGHT)
    {
        x = 0;
        while(x < WIDTH)
            {
                handle_pixel(x, y, fractal);
				x++;
            }
        y++;
    }
	mlx_clear_window(fractal->mlx_connection, fractal->mlx_window);
    mlx_put_image_to_window(fractal->mlx_connection, fractal->mlx_window, fractal->img.img_ptr, 0, 0);
}