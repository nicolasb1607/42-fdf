/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   default_values.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nburat-d <nburat-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 12:10:45 by nburat-d          #+#    #+#             */
/*   Updated: 2022/01/31 18:34:37 by nburat-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_fdf.h"

void set_zoom(t_app *app)
{
	while (app->map.width * app->map.zoom > WINDOW_WIDTH)
		app->map.zoom--;
	while (app->map.height * app->map.zoom > WINDOW_HEIGHT)
		app->map.zoom--;
	//set_pos(app);
}

// void set_pos(t_app *app)
// {
// 	int p1;
// 	int p2;
// 	int difx;
// 	int dify;

// 	p1 = app->map.width * app->map.zoom;
// 	p2 = app->map.height * app->map.zoom;
// 	dif

// }

void iso_zoom(t_app *app)
{
	int iso_pw;
	int iso_ph;
	
	iso_pw = app->map.width * app->map.zoom * cos(app->map.angle);
	iso_ph = (app->map.height + app->map.width) * app->map.zoom * sin(app->map.angle);
	while (iso_pw > WINDOW_WIDTH)
	{
		app->map.zoom -= 0.5;
		iso_pw = app->map.width * app->map.zoom * cos(app->map.angle);
	}
	while (iso_ph > WINDOW_HEIGHT)
	{
		app->map.zoom -= 0.5;
		iso_ph = (app->map.height + app->map.width) * app->map.zoom * sin(app->map.angle);
	}
	//set_pos(app);
}