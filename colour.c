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

// int colour_pixel(t_fractal *fractal)  // maybe better to do a struct for this
// {
//     //***var1
//     int new_colour = RED;
//     new_colour = new_colour * fractal->count / fractal->max_iter; /// this 32 i can increase it is intensity
//     // return (new_colour);
//     //***var 2
//     // int red = 0;  // No red
//     // int green = fractal->count * 64 * 255 / fractal->max_iter;
//     // int blue = 0;  // No blue
//     // new_colour = (red << 16) | (green << 8) | blue;
//     new_colour = (fractal->red << 16) | (fractal->green << 8) | fractal->blue;
//     return new_colour;
//     //var 3
// }

int colour_pixel(t_fractal *fractal)  // maybe better to do a struct for this
{
    int new_colour;
   
    //int red = fractal->count * factor / fractal->max_iter; 
    new_colour = ((fractal->red << 16) | (fractal->green << 8) | fractal->blue) * fractal->count / fractal->max_iter;
    return new_colour;
}