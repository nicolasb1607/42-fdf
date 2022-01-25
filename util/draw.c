#include "../includes/ft_fdf.h"

int draw(t_app *app)
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
				bres(x, y, x + 1, y, app);
			if (y < app->map.height - 1)
				bres(x, y, x, y + 1, app);
			x++;
		}
		y++;
	}
	return (0);
}
