#include "ft_fdf.h"
#include <mlx.h>

int main()
{
	t_app app;

	app.init = mlx_init();
	if (app.init == 0)
		return (0);
	app.win = mlx_new_window(app.init, WINDOW_WIDTH, WINDOW_HEIGHT, "Fils de Fer");
	if (app.win == 0)
	{
		free(app.win);
		return (0);
	}
	/*setup the img */
	app.img.mlx_img = mlx_new_image(app.init, WINDOW_WIDTH, WINDOW_HEIGHT);
	app.img.addr = mlx_get_data_addr(app.img.mlx_img, &app.img.bpp, &app.img.line_len, &app.img.endian);

	mlx_loop_hook(app.init, ft_no_event_handler, &app);
	//ft_trace_line(&app, 200, 45, 500, 25);
	mlx_hook(app.win, 17, 0, &ft_close_program, &app);
	mlx_loop(app.init);

	mlx_destroy_display(app.init);
	free(app.init);

	return (0);
}