#include "../includes/ft_fdf.h"



void	trace_line(int x1, int y1, int x2, int y2, t_app app)
{
	int dx;
	int dy;
	int e;
	int color = 0x00FFFFFF;

	e = x2 - x1;
	dx = e *2;
	dy = (y2 - y1) * 2;
	while (x1 <= x2)
	{
		mlx_pixel_put(app.init, app.win, x1, y1, color);
		x1 += 1;
		e = e - dy;
		if (e <= 0)
		{
			y1 += 1;
			e = e + dx;
		}
	}
}
