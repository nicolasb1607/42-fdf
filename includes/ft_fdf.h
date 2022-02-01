/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fdf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nburat-d <nburat-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 13:52:27 by nburat-d          #+#    #+#             */
/*   Updated: 2022/02/01 14:42:27 by nburat-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FDF_H
# define FT_FDF_H

# include <stdlib.h>
# include <stdio.h>
# include "mlx.h"
# include <X11/keysym.h> 
# include "./get_next_line.h"
# include <fcntl.h>
# include <math.h>

# define W_WIDTH 1920
# define W_HEIGHT 1080

typedef struct s_map
{
	int		width;
	int		height;
	int		**z_val;
	double	zoom;
	int		iso_view;
	int		deep_level;
	float	angle;
	int		color;
	int		pos_x;
	int		pos_y;
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
	void	*init;
	void	*win;
	t_img	img;
	t_map	map;
}	t_app;

typedef struct s_point
{
	int	x;
	int	y;
	int	z;
}	t_point;

typedef struct s_line
{
	int	x;
	int	y;
	int	dx;
	int	dy;
	int	swap;
	int	temp;
	int	s1;
	int	s2;
	int	p;
	int	i;
}	t_line;

//-----------windows control function
int		handle_keypress2(int keysym, t_app *app);
int		handle_keypress1(int keysym, t_app *app);
int		ft_close_program(t_app *app);
int		ft_get_mouse_spot(int button, int x, int y, t_point *point);
//-----------image rendering function
void	img_pix_put(t_img *img, int x, int y, int color);
void	render_background(t_img *img, int color);
int		render(t_app *app);
int		draw(t_app *app);
void	bres(t_point p1, t_point p2, t_app *app);
//-----------view change
void	isometric(t_point *p1, t_app *app);
void	set_zoom(t_app *app);
void	iso_zoom(t_app *app);
void	set_pos(t_app *app);
void	iso_pos(t_app *app);
void	apply_zoom(t_point *p1, t_point *p2, t_app *app);
void	apply_color(t_point *p1, t_point *p2, t_app *app);
void	change_pos(t_point *p1, t_point *p2, t_app *app);
//-------------------------Map parsing 
void	read_file(char *file, t_app *app);
char	**ft_split(char const *s, char c);
char	**free_tab(char **tab);
int		ft_wordcount(char const *s, char c);
int		ft_atoi(const char *nptr);

#endif