/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nburat-d <nburat-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 14:41:17 by nburat-d          #+#    #+#             */
/*   Updated: 2022/02/01 14:46:39 by nburat-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_fdf.h"

void	app_initialization(t_app *app)
{
	app->map.pos_x = 0;
	app->map.pos_y = 0;
	app->map.zoom = 100;
	app->map.iso_view = 1;
	app->map.deep_level = 1;
	app->map.angle = 0.463646716;
	iso_zoom(app);
	render(app);
}

int	main(int ac, char **av)
{
	t_app	app;

	if (ac == 2)
	{
		app.init = mlx_init();
		if (app.init == NULL)
			return (0);
		app.win = mlx_new_window(app.init, W_WIDTH, W_HEIGHT, "Fils de Fer");
		if (app.win == NULL)
		{
			free(app.win);
			return (0);
		}
		app.img.mlx_img = mlx_new_image(app.init, W_WIDTH, W_HEIGHT);
		app.img.addr = mlx_get_data_addr(app.img.mlx_img, &app.img.bpp,
				&app.img.line_len, &app.img.endian);
		read_file(av[1], &app);
		app_initialization(&app);
		mlx_key_hook(app.win, &handle_keypress1, &app);
		mlx_hook(app.win, 17, 0, &ft_close_program, &app);
		mlx_loop(app.init);
	}
	return (0);
}
