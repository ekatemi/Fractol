#include "fractol.h"

// function must: increment the value of color_shift, loop
// back if max count is reached (currently, 5)

// void	shift_color(t_fractal *f)
// {
// 	f->color_shift += 1;
// 	if (f->color_shift > 5)
// 		f->color_shift = 1;
// 	return ;
// }

// static int map_color(int count)
// {
//     return (255 - (count - 1) * 255 / (MAX_ITERATIONS - 1)) << 24;
// }

int colour_pixel(t_fractal *fractal)  // maybe better to do a struct for this
{
    //***var1
    // int new_colour = fractal->count * 64 * 255 / MAX_ITERATIONS; /// this 32 i can increase it is intensity
    // return (new_colour);
    //***var 2
    int red = 0;  // No red
    int green = fractal->count * 64 * 255 / fractal->max_iter;
    int blue = 0;  // No blue
    int new_colour = (red << 16) | (green << 8) | blue;
    return new_colour;
    //var 3
}

int colour_clown(t_fractal *fractal)
{
    int new_colour = 0;

    new_colour = WHITE / fractal->count;
    return new_colour;
}

// int calculate_color(t_fractal *fractal) {
//     double normalized_iterations = fractal->count / (double)fractal->max_iter;
//     int red = 255 * normalized_iterations;
//     int green = 0;
//     normalized_iterations = fractal->count / (double)fractal->max_iter + 200;
//     int blue = 255 - (255 * normalized_iterations);

//     fractal->red = red;
//     fractal->green = green;
//     fractal->blue = blue;
//     return ((fractal->red << 16) | (fractal->green << 8) | fractal->blue);
// }
