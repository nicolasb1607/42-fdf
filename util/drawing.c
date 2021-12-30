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

int render_rect(t_img *img, t_rect rect)
{
	int	i;
	int j;

	i = rect.y;
	while (i < rect.y + rect.height)
	{
		j = rect.x;
		while (j < rect.x + rect.width)
			img_pix_put(img, j++, i, rect.color);
		++i;
	}
	return (0);
}

void	img_pix_put(t_img *img, int x, int y, int color)
{
	char *pixel;

	pixel = img->addr + (y * img->line_len + x * (img->bpp / 8));
	*(int *)pixel = color;
}

int	render(t_app *app)
{
	if(app->win == NULL)
		return (0);
	render_background(&app->img, 0x00FFFFFF);
	
	ft_trace_line(&app->img, 300, 0, 0, 300);
	ft_trace_line(&app->img, 300, 200, 0, 300);
	ft_trace_line(&app->img, 0, 0, WINDOW_WIDTH, WINDOW_HEIGHT);
	
	mlx_put_image_to_window(app->init, app->win, app->img.mlx_img, 0,0);

	return (0);
}