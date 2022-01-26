/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   view_change.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nburat-d <nburat-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 17:05:20 by nburat-d          #+#    #+#             */
/*   Updated: 2022/01/26 17:53:31 by nburat-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_fdf.h"

void	isometric(int *x, int *y, int z, t_app *app)
{
	int	prev_x;
	int	prev_y;

	prev_x = *x;
	prev_y = *y;
	*x = (prev_x - prev_y) * cos(app->map.angle);
	*y = (prev_x + prev_y) * sin(app->map.angle) - z * 3;
}

void	apply_zoom(int *x1, int *y1, int *x2, int *y2, t_app *app)
{
	*x1 *= app->map.zoom;
	*y1 *= app->map.zoom;
	*x2 *= app->map.zoom;
	*y2 *= app->map.zoom;
}

void	apply_color(int x1, int y1, int x2, int y2, t_app *app)
{
	int	z1;
	int	z2;

	z1 = app->map.z_val[y1][x1];
	z2 = app->map.z_val[y2][x2];
	if (z1 || z2)
		app->map.color = 0x00FF0000;
	else
		app->map.color = 0x00FFFFFF;
}

void	change_pos(int *x1, int *y1, int *x2, int *y2, t_app *app)
{
	*x1 = *x1 + app->map.pos_x;
	*x2 = *x2 + app->map.pos_x;
	*y1 = *y1 + app->map.pos_y;
	*y2 = *y2 + app->map.pos_y;
}
