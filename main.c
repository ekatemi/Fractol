#include "fractol.h"





// void color_image(t_fractal *data, int color)
// {
//     int x;
//     int y;

//     x = 0;
//     while(x < WIDTH)
//     {
//         y = 0;
//         while(y < HEIGHT)
//             {
//                 my_mlx_pixel_put(data, x, y, color);
//                 y++;
//             }
//         x++;
//     }
// }


//input mandelbrot
//input julia <arg1> <arg2>
int main(int argc, char **argv)
{
    t_fractal fractal;

    if ((argc == 2 && !ft_strncmp(argv[1], "mandelbrot", 10)) 
        || (argc == 4 && !ft_strncmp(argv[1], "julia", 5)))
    {
        fractal.name = argv[1];
        fractal_init(&fractal); //inicia window y image
        set_minmax(&fractal); //set min max values of fractal with minx -2
        fractal_render(&fractal); //modifica image
       
        // int color = 0x00FF0000;
        // color_image(&fractal, color);
        // /* Display the image in the window */
        // mlx_put_image_to_window(fractal.mlx_connection, fractal.mlx_window, fractal.img.img_ptr, 0, 0);
        
        mlx_key_hook(fractal.mlx_window, &handle_keypress, &fractal);
    
        mlx_loop(fractal.mlx_connection); //infinite loop to keep modifying
       // mlx_destroy_window(fractal.mlx_connection, fractal.mlx_window);
        //free(fractal.mlx_connection);
    }
    else
    {
        ft_putstr_fd(ERR_MSG, STDERR_FILENO);
        exit(EXIT_FAILURE);
    }
    return (0);
}