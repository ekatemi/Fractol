#include "fractol.h"

int colour_pixel(t_fractal *fractal)  // maybe better to do a struct for this
{

    int colorValue = ((fractal->red << 16) | (fractal->green << 8) | fractal->blue);
    return ((colorValue * 255 * fractal->count) / fractal->max_iter);
}