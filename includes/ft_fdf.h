#ifndef FT_FDF_H
# define FT_FDF_H

# include <stdlib.h>
# include <stdio.h>
# include "mlx.h"
# include <X11/keysym.h> // Allow to use keysymbole rather than keycode to manage inputs
# include "./get_next_line.h"
# include <fcntl.h>

# define WINDOW_WIDTH 1920/2
# define WINDOW_HEIGHT 1080/2

typedef struct s_map
{
	int	width;
	int	height;
	int	**z_val;
	int	zoom; 

}	t_map;

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
	t_map	map;
}   t_app;

typedef struct s_point
{
    int x;
    int y;
}   t_point;


int		handle_keypress(int keysym, t_app *app);
int		ft_close_program(t_app *app);
int		ft_get_mouse_spot(int button, int x, int y, t_point *point);
int		ft_trace_line(int xa, int ya, int xb, int yb, t_app *app);
int		draw_map(t_app *app);
void	img_pix_put(t_img *img, int x, int y, int color);
void	render_background(t_img *img, int color);
int		render(t_app *app);
void read_file(char *file, t_app *app);
char	**ft_split(char const *s, char c);
int		ft_wordcount(char const *s, char c);
int		ft_atoi(const char *nptr);

#endif