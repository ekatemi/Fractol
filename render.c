#include "fractol.h"

//this funk modifyes all pixels and store them in img struct, then we push all this pixels to the window using
//mlx_put_image_to_window function;
void	my_mlx_pixel_put(t_fractal *data, int x, int y, int color)
{
	char	*dst;

	dst = data->img.pixel_ptr + (y * data->img.line_len + x * (data->img.bpp / 8)); ///calculates offset
	*(unsigned int*)dst = color;
}

void color_image(t_fractal *data, int color)
{
    int x;
    int y;

    x = 0;
    while(x < WIDTH)
    {
        y = 0;
        while(y < HEIGHT)
            {
                my_mlx_pixel_put(data, x, y, color);
                y++;
            }
        x++;
    }
}

void handle_pixel(int x, int y, t_fractal *fractal)
{
    
}

/// render fractal mandelbrot
void fractal_render(t_fractal *fractal)
{
    int x;
    int y;

    y = 0;
    while(y < HEIGHT)
    {
        x = 0;
        while(y < WIDTH)
            {
                handle_pixel(x, y, fractal);
                x++;
            }
        x++;
    }

}

