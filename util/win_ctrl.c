/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   win_ctrl.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nburat-d <nburat-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 17:57:34 by nburat-d          #+#    #+#             */
/*   Updated: 2022/01/26 17:57:40 by nburat-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_fdf.h"

int	ft_close_program(t_app *app)
{
	printf("Exiting program\n");
	mlx_destroy_window((*app).init, (*app).win);
	app->win = NULL;
	return (0);
}

int	handle_keypress(int keysym, t_app *app)
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
		app->map.zoom += 2;
	if (keysym == XK_Down)
		app->map.zoom -= 2;
	if (keysym == XK_Right)
		app->map.angle += 0.02;
	if (keysym == XK_Left)
		app->map.angle -= 0.02;
	return (0);
}

int	ft_get_mouse_spot(int button, int x, int y, t_point *point)
{
	point->x = x;
	point->y = y;
	printf("the button is pressed : %d, %d, %d\n", button, point->x, point->y);
	return (0);
}
