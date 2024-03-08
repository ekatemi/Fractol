#ifndef FRACTOL_H
# define FRACTOL_H

//*** HEADERS ***
#include "mlx/mlx.h"
//#include "ft_printf/printf.h" how to include this?
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <math.h>

#define ERR_MSG "Please enter \n\t\" ./fractol mandelbrot\" \n\t \
or \n\t\" ./fractol julia <val1> <val2>\"\n"

#define WELCOME_MSG "\033[1;32mWelcome to \033[1;34m🌈FRACTOL!\033[1;32m🌈\n" \
                    "\033[0;33m+ \033[0mresolution in\n" \
                    "\033[0;33m- \033[0mresolution out\n" \
                    "\033[0;33m← → ↑ ↓\033[0m move left/right/up/down\n" \
                    "\033[0;33mesc\033[0m close and exit"

#define WIDTH 600
#define HEIGHT 600
//#define MAX_ITERATIONS 250

//*** COLOURS *** //
#define RED 0x00FF0000
#define BLUE 0x000000FF
#define WHITE 0xFFFFFFF
#define BLACK 0x0000000

# define mandelbrot 1
# define julia 2

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

// typedef struct s_complex
// {
//     double  x;
//     double  y;
// }   t_complex;

//to get the memory address on which we will mutate the bytes accordingly 
typedef struct s_img
{
    void    *img_ptr; //pointer to image struct
    char    *pixel_ptr; //points to the actual pixel
    int bpp; //bits per pixel
    int endian; //we dont use it
    int line_len;
}   t_img;

//typedef void (*RenderFunction)(t_fractal*);

typedef struct s_fractal
{
    char *name;
    //MLX
    void *mlx_connection; //mlx_init
    void *mlx_window; //mlx_new_window
    //IMG
    t_img img;
    //COLOURS
    int red;
    int green;
    int blue;
    int colorsh;
   

    //positioning
    //double center_i;
    //double center_r;
    double min_r;
    double max_r;
    double min_i;
    double max_i;
    //iterations
    int max_iter;
    int count;
    //changing C in julia
    double julia_y;
    double julia_x;
    //hooks
    double zoom;
    double zoom_factor;
    double move_y;
    double move_x;
    //render function
    //RenderFunction render_function;
}   t_fractal;

//*** INIT FRACTAL STRUCT AND EVENTS***//
void fractal_init(t_fractal *fractal);
void event_init(t_fractal *fractal);

//***  KEY HANDLERS  ***//
int clean_exit(t_fractal *data);
int handle_keypress(int keysym, t_fractal *data);
int handle_mouse_zoom(int keycode, int x, int y, t_fractal *fractal);
//void	mouse_zoom(t_fractal *f, double zoom, int x, int y);
//int handle_julia(int keycode, int x, int y, t_fractal *fractal);

//*** RENDER FRACTAL ***
void	my_mlx_pixel_put(t_fractal *data, int x, int y, int color);
//int	is_mandelbrot(double cr, double ci, t_fractal *fractal);
void	render_mandelbrot(t_fractal *fractal);
void	render_julia(t_fractal *f);
void    render_burning(t_fractal *data);
//int is_julia(double zr, double zi, t_fractal *fractal);
//void	julia_shift(int x, int y, t_fractal *fractal);
void	render_fractal(t_fractal *data);

//*** COLORS ***//
int colour_pixel(t_fractal *fractal);


//*** string utils ***
int	ft_strncmp(const char *s1, const char *s2, size_t n);
void	ft_putstr_fd(char *s, int fd);

//coordinates utils
void set_minmax(t_fractal *fractal);
double linear_extr(int n, char c, t_fractal *fractal);


#endif