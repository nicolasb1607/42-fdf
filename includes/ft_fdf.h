#ifndef FT_FDF_H
# define FT_FDF_H

# include <stdlib.h>
# include <stdio.h>
# include "./mlx.h"

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
int ft_close_program(t_app *app);
int ft_trace_line(t_app *app, int xa, int ya, int xb, int yb);
int	ft_no_event_handler();

#endif