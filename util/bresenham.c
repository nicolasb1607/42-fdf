#include "../includes/ft_fdf.h"

void	isometric(int *x, int *y , t_app *app)
{
	int prev_x;
	int prev_y;

	prev_x = *x;
	prev_y = *y;
	*x = (prev_x - prev_y) * cos(app->map.angle);
	*y = (prev_x + prev_y) * sin(app->map.angle);
}

void apply_zoom(int *x1, int *y1, int *x2, int *y2, t_app *app)
{
	*x1 *= app->map.zoom;
	*y1 *= app->map.zoom;
	*x2 *= app->map.zoom;
	*y2 *= app->map.zoom;
}

void check_signs(int *x1, int *y1, int *x2, int *y2)
{
	int temp;
	if (*x1 > *x2)
	{
		temp = *x1;
		*x1 = *x2;
		*x2 = temp;
		temp = *y1;
		*y1 = *y2;
		*y2 = temp;
	}
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

void vert_line(int x, int y1, int y2, t_app *app, int color)
{
	int temp;

	if (y1 > y2)
	{
		temp = y1;
		y1 = y2;
		y2 = temp;
	}
	while (y1 <= y2)
		mlx_pixel_put(app->init, app->win, x, y1++, color);
}

void trace_line(int x1, int y1, int x2, int y2, t_app *app)
{
	int dx;
	int dy;
	int e;

	apply_color(x1, y1, x2, y2, app);
	apply_zoom(&x1, &y1, &x2, &y2, app);

	 isometric(&x1, &y1, app);
	 isometric(&x2, &y2, app);

	check_signs(&x1, &y1, &x2, &y2);

	if (x1 == x2)
	{
		vert_line(x1, y1, y2, app, app->map.color);
		return;
	}
	e = x2 - x1;
	dx = e * 2;
	dy = (y2 - y1) * 2;
	while (x1 <= x2)
	{
		mlx_pixel_put(app->init, app->win, x1, y1, app->map.color);
		x1 += 1;
		e = e - dy;
		if (e <= 0)
		{
			y1 += 1;
			e = e + dx;
		}
	}
}

