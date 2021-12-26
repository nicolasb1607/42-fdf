#ifndef FT_FDF_H
# define FT_FDF_H

# include "./mlx_int.h"
# include "./mlx.h"

typedef struct s_app
{
    void    *init;
    void    *win;
}   t_app;

int ft_get_keycode(int keycode);
int ft_get_mouse_spot(int button, int x, int y);
int ft_close_program(t_app *app);
int ft_trace_line(t_app *app, int xa, int ya, int xb, int yb);

#endif