#ifndef FT_FDF_H
# define FT_FDF_H

# include <stdlib.h>
# include <stdio.h>
# include "mlx.h"
# include <X11/keysym.h> 
// Allow to use keysymbole rather than keycode manage inputs

# define WINDOW_WIDTH 1920/2
# define WINDOW_HEIGHT 1080/2




typedef struct s_rect
{
	int	x;
	int	y;
	int width;
	int height;
	int color;
}	t_rect;

typedef struct s_img
{
	void	*mlx_img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}	t_img;

typedef struct s_app
{
    void    *init;
    void    *win;
	t_img	img;
}   t_app;

typedef struct s_point
{
    int x;
    int y;
}   t_point;


int ft_get_keycode(int keycode);
int ft_get_mouse_spot(int button, int x, int y, t_point *point);
int handle_keypress(int keysym, t_app *app);
int ft_close_program(t_app *app);
int ft_trace_line(t_img *img, int xa, int ya, int xb, int yb);
void	img_pix_put(t_img *img, int x, int y, int color);
void	render_background(t_img *img, int color);
int render_rect(t_img *img, t_rect rect);
int	render(t_app *app);

#endif