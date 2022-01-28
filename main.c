#include "includes/ft_fdf.h"

int main(int ac, char **av)
{
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
		// /*setup the img */
		app.img.mlx_img = mlx_new_image(app.init, WINDOW_WIDTH, WINDOW_HEIGHT);
		app.img.addr = mlx_get_data_addr(app.img.mlx_img, &app.img.bpp, &app.img.line_len, &app.img.endian);
		
		
		app.map.pos_x = WINDOW_WIDTH / 2;
		app.map.pos_y = WINDOW_HEIGHT / 2;
		app.map.zoom = 1;
		app.map.deep_level = 1;
		app.map.angle = 0.463646716;

		read_file(av[1], &app);

		mlx_key_hook(app.win, &handle_keypress, &app);
		
		mlx_hook(app.win, 17, 0, &ft_close_program, &app);
		
		// Draw stuff on the image prior to put the image on the window to avoid flickering
		mlx_loop_hook(app.init, &render, &app);

		//close window with ESC key or by clicking the red cross
		

		// End the render loop (standarfor the mlx lib)
		mlx_loop(app.init);

		// free mem allocated for the image
		
	}
	return (0);
}