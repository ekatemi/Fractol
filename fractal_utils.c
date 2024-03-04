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

// double scale_to_range(int input, int min_input, int max_input, double min_output, double max_output) 
// {
//     return min_output + ((double)(input - min_input) / (max_input - min_input)) * (max_output - min_output);
// }

t_complex   sum_complex(t_complex z1, t_complex z2)
{
    t_complex   result;

    result.x = z1.x + z2.x;
    result.y = z1.y + z2.y;
    return result;
}


/*
 * real = (x^2 - y^2)
 * i =  2*x*y
*/
t_complex   square_complex(t_complex z)
{
    t_complex   result;
    
    result.x = (z.x * z.x) - (z.y * z.y);
    result.y = 2 * z.x * z.y;
    return result;
}




