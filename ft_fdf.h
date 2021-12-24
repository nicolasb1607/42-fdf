#ifndef FT_FDF_H
# define FT_FDF_H


typedef struct s_app
{
    void    *init;
    void    *win;
}   t_app;

int ft_trace_line(t_app *app, int xa, int ya, int xb, int yb);

#endif