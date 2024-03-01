#include "fractol.h"

// void set_minmax(t_fractal *fractal)
// {
// fractal->min_r = -2;
// fractal->max_r = 0.5;
// //fractal->max_r = fractal->min_r * -1 * WIDTH / HEIGHT;
// fractal->min_i = -1.25;
// fractal->max_i = 1.25;
// //fractal->max_i = fractal->min_i * -1 * HEIGHT / WIDTH;
// }

void set_minmax(t_fractal *fractal)
{
    // Calculate the aspect ratio of the screen
    double aspect_ratio = (double)WIDTH / (double)HEIGHT;

    // Set the initial min and max values
    fractal->min_r = -2;
    fractal->max_r = 0.5;
    fractal->min_i = -1.25;
    fractal->max_i = 1.25;

    // Adjust min and max values based on the aspect ratio
    if (aspect_ratio > 1.0) {
        // Landscape-oriented screen
        fractal->min_r *= aspect_ratio;
        fractal->max_r *= aspect_ratio;
    } else {
        // Portrait-oriented screen
        fractal->min_i /= aspect_ratio;
        fractal->max_i /= aspect_ratio;
    }
}

//it is not necessary but that way it works in every window

