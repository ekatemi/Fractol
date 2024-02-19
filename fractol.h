#ifndef FRACTOL_H
# define FRACTOL_H

//*** HEADERS ***
#include "mlx/mlx.h"
//#include "ft_printf/printf.h" how to include this?
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <math.h>

#define ERR_MSG "Please enter \n\t\" ./fractol mandelbrot\" \n\t or \n\t\" ./fractol julia <val1> <val2>\"\n"

#define WIDTH 800
#define HEIGHT 800

//to get the memory address on which we will mutate the bytes accordingly 
typedef struct s_img
{
    void    *img_ptr; //pointer to image struct
    char    *pixel_ptr; //points to the actual pixel
    int bpp; //bits per pixel
    int endian; //we dont use it
    int line_len;
}   t_img;


typedef struct s_fractal
{
    char *name;
    //MLX
    void *mlx_connection; //mlx_init
    void *mlx_window; //mlx_new_window
    //IMG
    t_img img;
    //hooks
}   t_fractal;

void fractal_init(t_fractal *fractal);


//*** string utils ***
int	ft_strncmp(const char *s1, const char *s2, size_t n);
void	ft_putstr_fd(char *s, int fd);

#endif