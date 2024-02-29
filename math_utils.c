#include "fractol.h"

void set_minmax(t_fractal *fractal)
{
fractal->min_r = -2;
fractal->max_r = fractal->min_r * -1 * WIDTH / HEIGHT;
fractal->min_i = -2;
fractal->max_i = fractal->min_i * -1 * HEIGHT / WIDTH;
}

