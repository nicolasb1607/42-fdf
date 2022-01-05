#include "../includes/ft_fdf.h"

int ft_trace_line(int xa, int ya, int xb, int yb, t_app *app)
{
	float xd;
	float yd;
	float m;
	float y;
	int color;

	xd = xa - xb;
	yd = ya - yb;
	m = yd / xd;

	if (app->map.z_val[ya][xa] || app->map.z_val[yb][xb])
		color = 0x00FF0000;
	else
		color = 0x00FFFFFF;

	xa *= app->map.zoom;
	xb *= app->map.zoom;
	ya *= app->map.zoom;
	yb *= app->map.zoom;

	

	if (xa > xb)
	{
		while (xa > xb)
		{
			y = m * xb + yb + 0.5;
			img_pix_put(&app->img, xb++, y, color);
		}
	}
	else if (xa < xb)
	{
		while (xa < xb || y < yb)
		{
			y = m * xa + ya + 0.5;
			img_pix_put(&app->img, xa++, y, color);
		}
	}
	else if (xa == xb)
	{
		while (ya <= yb)
			img_pix_put(&app->img, xa, ya++, color);
	}
	return (0);
}

int draw_map(t_app *app)
{
	int x;
	int y;

	y = 0;
	while (y <= app->map.height)
	{
		x = 0;
		while (x <= app->map.width - 1 && y < app->map.height - 1)
		{
			if (x < app->map.width - 1)
			{
				ft_trace_line(x, y, x, y + 1, app); // tracage horizontal
				ft_trace_line(x, y, x + 1, y, app); // tracage vertical
				
			}
			else
				ft_trace_line(x, y, x, y + 1, app);
			x++;
		}
		while (x < app->map.width - 1 && y == app->map.height - 1)
		{
			ft_trace_line(x, y, x + 1, y, app);
			x++;
		}
		y++;
	}
	return (0);
}
