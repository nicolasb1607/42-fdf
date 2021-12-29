#include "../includes/ft_fdf.h"

int main()
{
	t_app app;
	

	app.init = mlx_init();
	if (app.init == 0)
		return (0); 
	app.win = mlx_new_window(app.init, 500, 300, "Fils de Fer");
	if (app.win == 0)
	{
		free(app.win);
		return (0);
	}
	mlx_loop_hook(app.init, ft_no_event_handler, &app);


	ft_trace_line(&app, 200, 45, 500, 25);
	mlx_hook(app.win, 17, 0, &ft_close_program, &app);
	mlx_loop(app.init);

	mlx_destroy_display(app.init);
	free(app.init);

	return (0);
}