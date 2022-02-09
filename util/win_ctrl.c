/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   win_ctrl.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nburat-d <nburat-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 17:57:34 by nburat-d          #+#    #+#             */
/*   Updated: 2022/02/09 19:10:25 by nburat-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_fdf.h"

void	free_map(int **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}

int	ft_close_program(t_app *app)
{
	ft_putstr("Exiting program\n");
	mlx_destroy_image(app->init, app->img.mlx_img);
	mlx_destroy_window(app->init, app->win);
	mlx_destroy_display(app->init);
	free_map(app->map.z_val);
	free(app->init);
	app->win = NULL;
	exit (0);
}

int	handle_keypress2(int keysym, t_app *app)
{
	if (keysym == XK_Right)
		app->map.angle += 0.02;
	if (keysym == XK_Left)
		app->map.angle -= 0.02;
	if (keysym == XK_i)
		app->map.deep_level += 1;
	if (keysym == XK_k)
		app->map.deep_level -= 1;
	if (keysym == XK_p)
		app->map.iso_view *= -1;
	render(app);
	return (0);
}

int	handle_keypress1(int keysym, t_app *app)
{
	if (keysym == XK_Escape)
		ft_close_program(app);
	if (keysym == XK_a)
		app->map.pos_x -= 20;
	if (keysym == XK_d)
		app->map.pos_x += 20;
	if (keysym == XK_w)
		app->map.pos_y -= 20;
	if (keysym == XK_s)
		app->map.pos_y += 20;
	if (keysym == XK_Up)
		app->map.zoom += 0.2;
	if (keysym == XK_Down)
		app->map.zoom -= 0.2;
	handle_keypress2(keysym, app);
	return (0);
}
