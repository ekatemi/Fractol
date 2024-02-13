#include "minilibx_opengl_20191021/mlx.h"

// int main(void)
// {
//     void *mlx;
 
//     mlx = mlx_init();
//     if (!mlx)
//     {
//     // Handle the error.
//         return (1);
//     }
//     // Do some cool graphical stuff here…
//     // Clean up before exiting. The Display struct and the xvar struct
//     mlx_destroy_display(mlx);
//     free(mlx);
//     return (0);
// }
typedef struct  s_complex
{
    double real;
    double i;
}   t_complex;


int main()
{
    t_complex z;
    t_complex c;

    z.real = 0;
    z.i = 0;
}