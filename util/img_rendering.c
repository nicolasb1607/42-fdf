#include "../includes/ft_fdf.h"

void	render_background(t_img *img, int color)
{
	int	i;
	int	j;

	i = 0;
	while (i < WINDOW_HEIGHT)
	{
		j = 0;
		while (j < WINDOW_WIDTH)
		{
			img_pix_put(img, j++, i, color);
		}
		++i;
	}
}

void	img_pix_put(t_img *img, int x, int y, int color)
{
	char *pixel;

	pixel = img->addr + (y * img->line_len + x * (img->bpp / 8));
	*(int *)pixel = color;
}

int	render(t_app *app)
{
	app->map.zoom = 50;
	app->map.angle = 0.463646716;
	app->map.pos_x = 500;
	app->map.pos_y = 200;

	if(app->win == NULL)
		return (0);

	// bres(0, 0, 500, 300, app);
	// bres(0, 500, 500, 0, app);
	// bres(500, 0, 0, 400, app);
	// bres(500, 350, 0, 0, app);
	//render_background(&app->img, 0x00000000);
	draw(app);
	//mlx_put_image_to_window(app->init, app->win, app->img.mlx_img, 0,0);

	return (0);
}