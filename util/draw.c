#include "../includes/ft_fdf.h"

int ft_trace_line(t_img *img, int xa, int ya, int xb, int yb)
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
		while (xa > xb)
		{
			y = m * xb + yb + 0.5;
			img_pix_put(img, xb++, y, 0x00000000);
		}
	}
	else if (xa < xb)
	{
		while (xa <= xb)
		{
			y = m * xa + ya + 0.5;
			img_pix_put(img, xa++, y, 0x00000000);
		}
	}
	return (0);
}