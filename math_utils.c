#include "fractol.h"

double scale_to_range(int input, int min_input, int max_input, double min_output, double max_output) 
{
    return min_output + ((double)(input - min_input) / (max_input - min_input)) * (max_output - min_output);
}

