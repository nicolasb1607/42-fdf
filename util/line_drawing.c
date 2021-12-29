#include "../includes/ft_fdf.h"

int ft_trace_line(t_app *app, int xa, int ya, int xb, int yb)
{
	float xd;
	float yd;
	float m;
	float y;

	xd = xa - xb;
	yd = ya - yb;
	m = yd / xd;
	if (xa > xb)
	{
		while (xb <= xa)
		{
			y = m * xb + yb + 0.5;
			if(app->win != NULL)
				mlx_pixel_put(app->init, app->win, xb, y, 0x00FFFFFF);
			xb++;
		}
	}
	while (xa <= xb)
	{
		y = m * xa + ya + 0.5;
		mlx_pixel_put(app->init, app->win, xa, y, 0x00FFFFFF);
		xa++;
	}
	return (0);
}