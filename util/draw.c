#include "../includes/ft_fdf.h"

int isometric(int *x, int *y, int z)
{
	*x = (*x - *y) * cos(0.3);
	*y = (*x + *y) * sin(0.3) - z;
	return (0);
}

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

	printf("xa before iso = %d\n", xa);
	printf("ya before iso = %d\n", ya);
	printf("xb before iso = %d\n", xb);
	printf("yb before iso = %d\n", yb);

	// isometric(&xa, &ya , za);
	// isometric(&xb, &yb, zb);

	printf("xa = %d\n", xa);
	printf("ya = %d\n", ya);
	printf("xb = %d\n", xb);
	printf("yb = %d\n", yb);

	xd = xa - xb;
	yd = ya - yb;
	m = yd / xd;


	if (za || zb)
		color = 0x00FF0000;
	else
		color = 0x00FFFFFF;

	xa = xa * app->map.zoom + app->map.pos_x;
	xb = xb * app->map.zoom + app->map.pos_x;
	ya = ya * app->map.zoom + app->map.pos_y;
	yb = yb * app->map.zoom + app->map.pos_y;

	

	
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
		{
			img_pix_put(&app->img, xa, ya++, color);
		}
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
		printf("value of y = %d\n", y);
		while (x <= app->map.width - 1 && y < app->map.height - 1)
		{

			if (x < app->map.width - 1)
			{
				printf("before trace line\n");
				ft_trace_line(x, y, x, y + 1, app); // tracage horizontal
				printf("value X = %d\n", x);
				printf("value Y = %d\n", y);
				ft_trace_line(x, y, x + 1, y, app); // tracage vertical
			}
			else
			{
				printf("else loop\n");
				ft_trace_line(x, y, x, y + 1, app);
			}
			x++;
		}
		while (x < app->map.width - 1 && y == app->map.height - 1)
		{
			printf("other loop\n");
			ft_trace_line(x, y, x + 1, y, app);
			x++;
		}
		printf("end of draw\n");
		y++;
	}
	return (0);
}
