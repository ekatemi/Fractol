#ifndef FRACTOL_H
# define FRACTOL_H

//*** HEADERS ***
#include "mlx/mlx.h"
//#include "ft_printf/printf.h" how to include this?
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
// #include <math.h>

#define ERR_MSG "Please enter \n\t\" ./fractol mandelbrot\" \n\t or \n\t\" ./fractol julia <val1> <val2>\"\n"

#define WIDTH 800
#define HEIGHT 800
//#define MAX_ITERATIONS 250

//*** COLOURS *** //
#define RED 0x00FF0000
#define BLUE 0x000000FF
#define WHITE 0xFFFFFFF
#define BLACK 0x0000000

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

//COMPLEX VALUES

typedef struct s_complex
{
    double  x;
    double  z;
}   t_complex;

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
    //positioning
    double center_i;
    double center_r;
    double min_r;
    double max_r;
    double min_i;
    double max_i;
    //iterations
    int max_iter;
    int count;
    double julia_shift_y;
    double julia_shift_x;
    //hooks
    double zoom;
    double move_y;
    double move_x;
}   t_fractal;

//*** INIT FRACTAL STRUCT ***//
void fractal_init(t_fractal *fractal);
int clean_exit(t_fractal *data);

//***  KEY HANDLERS  ***//
void event_init(t_fractal *fractal);
int handle_keypress(int keysym, t_fractal *data);
int handle_mouse(int keycode, int x, int y, t_fractal *fractal);
void	mouse_zoom(t_fractal *f, double zoom, int x, int y);

//*** RENDER FRACTAL ***
void	my_mlx_pixel_put(t_fractal *data, int x, int y, int color);
//void color_image(t_fractal *data, int color); ///just test, delete later
int	is_mandelbrot(double cr, double ci, t_fractal *fractal);
void mandelbrot_render(t_fractal *fractal);
//void    julia_render(t_fractal *fractal);

//*** COLORS ***//
int colour_pixel(t_fractal *fractal);
int colour_clown(t_fractal *fractal);

//*** string utils ***
int	ft_strncmp(const char *s1, const char *s2, size_t n);
void	ft_putstr_fd(char *s, int fd);

//math utils
void set_minmax(t_fractal *fractal);

#endif