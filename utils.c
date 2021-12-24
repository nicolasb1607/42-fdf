#include "mlx.h"
#include "ft_fdf.h"

int ft_trace_line(t_app *app, int x, int y)
{
	int i;
	int j; 

	i = 200;
	j = 500;
	while (i < x)
	{
		mlx_pixel_put((*app).init, (*app).win, i, j , 0x00FFFFFF);
		i++;
	}
	return 0;
}