#include "../includes/ft_fdf.h"

int isometric(int *x, int *y, int z)
{
	// (void)z;
	*x = (*x - *y) * cos(0.8);
	*y = (*x + *y) * sin(0.8) - z;
	return (0);
}

// void bresenham(float x1, float y1, float x2, float y2, t_app *app)
// {
// 	float temp;
// 	float m;
// 	float y;
// 	int color = 0x00FFFFFF;
// 	int z1;
// 	int z2;

// 	z1 = app->map.z_val[(int)y1][(int)x1];
// 	z2 = app->map.z_val[(int)y2][(int)x2];

// 	if (z1 || z2)
// 		color = 0x00FF0000;
// 	else
// 		color = 0x00FFFFFF;

// 	// x1 = x1 * app->map.zoom + app->map.pos_x;
// 	// x2 = x2 * app->map.zoom + app->map.pos_x;
// 	// y1 = y1 * app->map.zoom + app->map.pos_y;
// 	// y2 = y2 * app->map.zoom + app->map.pos_y;

// 	if (x1 > x2)
// 	{
// 		temp = x1;
// 		x1 = x2;
// 		x2 = temp;
// 		temp = y1;
// 		y1 = y2;
// 		y2 = temp;
// 	}

// 	isometric(&x1, &y1, z1);
// 	isometric(&x2, &y2, z2);

// 	m = (y2 - y1) / (x2 - x1);
// 	if (x1 < x2)
// 	{
// 		while (x1 < x2)
// 		{
// 			y = m * x1 + y1 + 0.5;
// 			img_pix_put(&app->img, x1++, y, color);
// 		}
// 	}
// 	if (x1 == x2 && y1 < y2)
// 	{
// 		while (y1 < y2)
// 			img_pix_put(&app->img, x1, y1++, color);
// 	}
// }

int ft_trace_line(int xa, int ya, int xb, int yb, t_app *app)
{
	float xd;
	float yd;
	float m;
	float y;
	int color;
	int za;
	int zb;

	za = app->map.z_val[ya][xa];
	zb = app->map.z_val[yb][xb];

	xd = xb - xa;
	yd = yb - ya;
	m = yd / xd;

	if (za || zb)
		color = 0x00FF0000;
	else
		color = 0x00FFFFFF;

	xa = xa * app->map.zoom + app->map.pos_x;
	xb = xb * app->map.zoom + app->map.pos_x;
	ya = ya * app->map.zoom + app->map.pos_y;
	yb = yb * app->map.zoom + app->map.pos_y;

	isometric(&xa, &ya, za);
	isometric(&xb, &yb, zb);

	while (xa < xb)
	{
		y = m * xa + ya + 0.5;
		img_pix_put(&app->img, xa++, y, color);
	}
	while (xa == xb && ya < yb)
		img_pix_put(&app->img, xa, ya++, color);
	return (0);
}

int draw_map(t_app *app)
{
	int x;
	int y;

	y = 0;
	while (y < app->map.height)
	{
		x = 0;
		while (x < app->map.width)
		{
			if (x < app->map.width - 1)
				ft_trace_line(x, y, x + 1, y, app);
			if (y < app->map.height - 1)
				ft_trace_line(x, y, x, y + 1, app);
			x++;
		}
		y++;
	}
	return (0);
}
