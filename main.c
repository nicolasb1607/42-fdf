#include "includes/ft_fdf.h"

/*

- Determiner le nombre de lignes 
- Determiner le nmobre de colonne

- Creer une matrice contenant chacun des numeros de la map

- Placer les points sur un plan avec une distance variable entre les points. 
(la distance variable permmettra d effectuer un zoom si necessaire)





*/


int main()
{
	t_app app;

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

	// Draw stuff on the image prior to put the image on the window to avoid flickering
	mlx_loop_hook(app.init, &render, &app);

	mlx_key_hook(app.win, &handle_keypress, &app);
	mlx_hook(app.win, 17, 0, &ft_close_program, &app);


	mlx_loop(app.init);

	mlx_destroy_image(app.init, app.img.mlx_img);
	mlx_destroy_display(app.init);
	free(app.init);

	return (0);
}