#include "mlx.h"
#include "ft_fdf.h"
#include <stdio.h>

int ft_trace_line(t_app *app, int xa, int ya, int xb, int yb)
{
	float xd;
	float yd;
	float m;
	int y;

	xd = xa - xb;
	yd = ya - yb;
	m = yd / xd;

	while (xa <= xb)
	{
		y = m * xa + ya;
		printf("xa : %d, y = %d\n", xa, y);
		mlx_pixel_put(app->init, app->win, xa, y, 0x00FFFFFF);
		xa++;
	}

	return 0;
}