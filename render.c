
#include "fractol.h"

int	is_mandelbrot(double cr, double ci, t_fractal *fractal) //cr and ci is scaled x and y
{
	double	zr;
	double	zi;
	double	tmp;
	int		i;

	i = 0;
	zr = 0;
	zi = 0;
	while (i <= fractal->max_iter)
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

void	render_mandelbrot(t_fractal *fractal)
{
	int		x;
	int		y;
	double	pr;
	double	pi;

	y = 0;
	while (y < HEIGHT)
	{
		pi = fractal->max_i + ((double)y * (fractal->min_i - fractal->max_i) / HEIGHT);
		x = 0;
		while (x < HEIGHT)
		{
			pr = fractal->min_r + ((double)x * (fractal->max_r - fractal->min_r) / HEIGHT);
			if (!is_mandelbrot(pr, pi, fractal))
				my_mlx_pixel_put(fractal, x, y, colour_pixel(fractal));
			else
				my_mlx_pixel_put(fractal, x, y, WHITE);
            x++;
        }
        y++;
	}
	mlx_clear_window(fractal->mlx_connection, fractal->mlx_window);
    mlx_put_image_to_window(fractal->mlx_connection, fractal->mlx_window, fractal->img.img_ptr, 0, 0);
	return ;
}

void	render_julia(t_fractal *f)
{
	int		x;
	int		y;
	double	pr;
	double	pi;

	y = 0;
	while (y < HEIGHT)
	{
		pi = f->max_i + ((double)y * (f->min_i - f->max_i) / HEIGHT);
		x = 0;
		while (x < WIDTH)
		{
			pr = f->min_r + ((double)x * (f->max_r - f->min_r) / WIDTH);
			if (!is_julia(pr, pi, f))
				my_mlx_pixel_put(f, x, y, colour_pixel(f));
			else
				my_mlx_pixel_put(f, x, y, WHITE);
		x++;
		}
		y++;
	}
	mlx_clear_window(f->mlx_connection, f->mlx_window);
    mlx_put_image_to_window(f->mlx_connection, f->mlx_window, f->img.img_ptr, 0, 0);
	return ;
}

int	is_julia(double zr, double zi, t_fractal	*fractal)
{
	double	tmp;
	int		i;

	i = 0;
	while (i++ < fractal->max_iter)
	{
		if ((zr * zr + zi * zi) > 4)
		{
			fractal->count = i;
			return (0);
		}
		tmp = zr * zr - zi * zi;
		zi = 2 * zr * zi + fractal->julia_y;
		zr = tmp + fractal->julia_x;
	}
		fractal->count = i;
	return (1);
}

void	render_fractal(t_fractal *data)
{
	set_minmax(data);
	if (!ft_strncmp(data->name, "mandelbrot", 10))
		render_mandelbrot(data);
	if (!ft_strncmp(data->name, "julia", 5))
		render_julia(data);
}