/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nburat-d <nburat-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 13:55:52 by nburat-d          #+#    #+#             */
/*   Updated: 2022/01/25 16:54:06 by nburat-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_fdf.h"

void isometric(int *x, int *y, int z, t_app *app)
{
	int prev_x;
	int prev_y;

	prev_x = *x;
	prev_y = *y;
	*x = (prev_x - prev_y) * cos(app->map.angle);
	*y = (prev_x + prev_y) * sin(app->map.angle) - z * 3;
}

void apply_zoom(int *x1, int *y1, int *x2, int *y2, t_app *app)
{
	*x1 *= app->map.zoom;
	*y1 *= app->map.zoom;
	*x2 *= app->map.zoom;
	*y2 *= app->map.zoom;
}

void apply_color(int x1, int y1, int x2, int y2, t_app *app)
{
	int z1;
	int z2;

	z1 = app->map.z_val[y1][x1];
	z2 = app->map.z_val[y2][x2];

	if (z1 || z2)
		app->map.color = 0x00FF0000;
	else
		app->map.color = 0x00FFFFFF;
}

void change_pos(int *x1, int *y1, int *x2, int *y2, t_app *app)
{
	*x1 = *x1 + app->map.pos_x;
	*x2 = *x2 + app->map.pos_x;
	*y1 = *y1 + app->map.pos_y;
	*y2 = *y2 + app->map.pos_y;
}

int sign(int x)
{
	if (x > 0)
		return 1;
	else if (x < 0)
		return -1;
	else
		return 0;
}

void bres(int x1, int y1, int x2, int y2, t_app *app)
{
	int x;
	int y;
	int dx;
	int dy;
	int swap;
	int temp;
	int s1;
	int s2;
	int p;
	int i;

	int z1 = app->map.z_val[y1][x1];
	int z2 = app->map.z_val[y2][x2];
	
	apply_color(x1, y1, x2, y2, app);
	apply_zoom(&x1, &y1, &x2, &y2, app);
	isometric(&x1, &y1, z1, app);
	isometric(&x2, &y2, z2, app);

	change_pos(&x1, &y1, &x2, &y2, app);
	x = x1;
	y = y1;
	dx = abs(x2 - x1);
	dy = abs(y2 - y1);
	s1 = sign(x2 - x1);
	s2 = sign(y2 - y1);
	swap = 0;
	//mlx_pixel_put(app->init, app->win, x1, y1, app->map.color);
	img_pix_put(&app->img, x1, y1, app->map.color);
	if (dy > dx)
	{
		temp = dx;
		dx = dy;
		dy = temp;
		swap = 1;
	}
	p = 2 * dy - dx;
	for (i = 0; i < dx; i++)
	{
		//mlx_pixel_put(app->init, app->win, x, y, app->map.color);
		img_pix_put(&app->img, x, y, app->map.color);
		while (p >= 0)
		{
			p = p - 2 * dx;
			if (swap)
				x += s1;
			else
				y += s2;
		}
		p = p + 2 * dy;
		if (swap)
			y += s2;
		else
			x += s1;
	}
	img_pix_put(&app->img, x2, y2, app->map.color);
	//mlx_pixel_put(app->init, app->win, x2, y2, app->map.color);
}
