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
    // int new_colour = fractal->count * 64 * 255 / MAX_ITERATIONS; /// this 32 i can increase it is intensity

    // return (new_colour);
    int red = 0;  // No red
    int green = fractal->count * 64 * 255 / fractal->max_iter;
    int blue = 0;  // No blue
    //printf("max iter %d", fractal->count);
    // Combine the color channels
    int new_colour = (red << 16) | (green << 8) | blue;
    return new_colour;
}

int colour_clown(t_fractal *fractal)
{
    int new_colour = 0;

    new_colour = WHITE / fractal->count;
    return new_colour;
}