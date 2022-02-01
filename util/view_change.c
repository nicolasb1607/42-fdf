/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   view_change.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nburat-d <nburat-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 17:05:20 by nburat-d          #+#    #+#             */
/*   Updated: 2022/02/01 14:32:01 by nburat-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_fdf.h"

void	isometric(t_point *p1, t_app *app)
{
	int	prev_x;
	int	prev_y;
	int	prev_z;

	prev_x = p1->x;
	prev_y = p1->y;
	prev_z = p1->z * app->map.deep_level;
	p1->x = (prev_x - prev_y) * cos(app->map.angle);
	p1->y = (prev_x + prev_y) * sin(app->map.angle) - prev_z;
}

void	apply_zoom(t_point *p1, t_point *p2, t_app *app)
{
	p1->x *= app->map.zoom;
	p1->y *= app->map.zoom;
	p2->x *= app->map.zoom;
	p2->y *= app->map.zoom;
}

void	apply_color(t_point *p1, t_point *p2, t_app *app)
{
	if (p1->z || p2->z)
		app->map.color = 0x00FF0000;
	else
		app->map.color = 0x00FFFFFF;
}

void	change_pos(t_point *p1, t_point *p2, t_app *app)
{
	p1->x = p1->x + app->map.pos_x;
	p2->x = p2->x + app->map.pos_x;
	p1->y = p1->y + app->map.pos_y;
	p2->y = p2->y + app->map.pos_y;
}
