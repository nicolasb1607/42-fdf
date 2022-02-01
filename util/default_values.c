/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   default_values.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nburat-d <nburat-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 12:10:45 by nburat-d          #+#    #+#             */
/*   Updated: 2022/02/01 14:45:28 by nburat-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_fdf.h"

void	set_zoom(t_app *app)
{
	while (app->map.width * app->map.zoom > W_WIDTH)
		app->map.zoom--;
	while (app->map.height * app->map.zoom > W_HEIGHT)
		app->map.zoom--;
	set_pos(app);
}

void	set_pos(t_app *app)
{
	int	p1;
	int	p2;
	int	difx;
	int	dify;

	p1 = app->map.width / 2 * app->map.zoom;
	p2 = app->map.height / 2 * app->map.zoom;
	difx = W_WIDTH / 2 - p1;
	dify = W_HEIGHT / 2 - p2;
	app->map.pos_x = difx;
	app->map.pos_y = dify;
}

void	iso_pos(t_app *app)
{
	int	p1;
	int	p2;
	int	difx;
	int	dify;

	difx = app->map.zoom * cos(app->map.angle);
	dify = app->map.zoom * sin(app->map.angle);
	p1 = (app->map.width - app->map.height) / 2 * difx;
	p2 = (app->map.height + app->map.width) / 2 * dify;
	difx = W_WIDTH / 2 - p1;
	dify = W_HEIGHT / 2 - p2;
	app->map.pos_x = difx;
	app->map.pos_y = dify;
}

void	iso_zoom(t_app *app)
{
	int	iso_pw;
	int	iso_ph;
	int	difx;
	int	dify;

	difx = app->map.zoom * cos(app->map.angle);
	dify = app->map.zoom * sin(app->map.angle);
	iso_pw = app->map.width * difx;
	iso_ph = (app->map.height + app->map.width) * dify;
	while (iso_pw > W_WIDTH)
	{
		app->map.zoom -= 0.5;
		difx = app->map.zoom * cos(app->map.angle);
		iso_pw = app->map.width * difx;
	}
	while (iso_ph > W_HEIGHT)
	{
		app->map.zoom -= 0.5;
		dify = app->map.zoom * sin(app->map.angle);
		iso_ph = (app->map.height + app->map.width) * dify;
	}
	iso_pos(app);
}
