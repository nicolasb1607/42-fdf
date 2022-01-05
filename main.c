#include "includes/ft_fdf.h"

int main(int ac, char **av)
{
	// t_app app;
	// int i = 0;
	// int j;

	// if (ac == 2)
	// {
	// 	read_file(av[1], &app);
	// 	while (i < app.map.height)
	// 	{

	// 		j = 0;
	// 		while (j < app.map.width)
	// 		{
	// 			printf("%3d", app.map.z_val[i][j]);
	// 			j++;
	// 		}
	// 		printf("\n");
	// 		i++;
	// 	}
	// }
	// return (0);

	t_app app;

	if (ac == 2)
	{

		app.init = mlx_init();
		if (app.init == NULL)
			return (0);
		app.win = mlx_new_window(app.init, WINDOW_WIDTH, WINDOW_HEIGHT, "Fils de Fer");
		if (app.win == NULL)
		{
			free(app.win);
			return (0);
		}
		/*setup the img */
		app.img.mlx_img = mlx_new_image(app.init, WINDOW_WIDTH, WINDOW_HEIGHT);
		app.img.addr = mlx_get_data_addr(app.img.mlx_img, &app.img.bpp, &app.img.line_len, &app.img.endian);
		read_file(av[1], &app);
		
		// Draw stuff on the image prior to put the image on the window to avoid flickering
		mlx_loop_hook(app.init, &render, &app);

		mlx_key_hook(app.win, &handle_keypress, &app);
		mlx_hook(app.win, 17, 0, &ft_close_program, &app);

		mlx_loop(app.init);

		mlx_destroy_image(app.init, app.img.mlx_img);
		mlx_destroy_display(app.init);
		free(app.init);
	}
	return (0);
}