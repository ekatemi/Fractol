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

enum {
	ON_KEYDOWN = 2,
	ON_KEYUP = 3,
	ON_MOUSEDOWN = 4,
	ON_MOUSEUP = 5,
	ON_MOUSEMOVE = 6,
	ON_EXPOSE = 12,
	ON_DESTROY = 17,
    ON_EXIT = 53 ///my var check it
};

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

//***  KEY HANDLERS  ***//
//mlx_key_hook(data.win_ptr, &handle_keypress, &data);
int handle_keypress(int keysym, t_fractal *data);

//
//*** string utils ***
int	ft_strncmp(const char *s1, const char *s2, size_t n);
void	ft_putstr_fd(char *s, int fd);

#endif