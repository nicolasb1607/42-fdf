/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nburat-d <nburat-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 13:55:52 by nburat-d          #+#    #+#             */
/*   Updated: 2022/01/26 17:20:23 by nburat-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_fdf.h"


int sign(int x)
{
	if (x > 0)
		return 1;
	else if (x < 0)
		return -1;
	else
		return 0;
}

void swap(t_line *line)
{
	line->temp = line->dx;
	line->dx = line->dy;
	line->dy = line->temp;
	line->swap = 1;
}

void bres(int x1, int y1, int x2, int y2, t_app *app)
{
	t_line line;

	int z1 = app->map.z_val[y1][x1];
	int z2 = app->map.z_val[y2][x2];
	
	apply_color(x1, y1, x2, y2, app);
	apply_zoom(&x1, &y1, &x2, &y2, app);
	isometric(&x1, &y1, z1, app);
	isometric(&x2, &y2, z2, app);

	change_pos(&x1, &y1, &x2, &y2, app);
	line.x = x1;
	line.y = y1;
	line.dx = abs(x2 - x1);
	line.dy = abs(y2 - y1);
	line.s1 = sign(x2 - x1);
	line.s2 = sign(y2 - y1);
	line.swap = 0;
	
	img_pix_put(&app->img, x1, y1, app->map.color);
	if (line.dy > line.dx)
		swap(&line);
	line.p = 2 * line.dy - line.dx;
	for (line.i = 0; line.i < line.dx; line.i++)
	{

		img_pix_put(&app->img, line.x, line.y, app->map.color);
		while (line.p >= 0)
		{
			line.p = line.p - 2 * line.dx;
			if (line.swap)
				line.x += line.s1;
			else
				line.y += line.s2;
		}
		line.p = line.p + 2 * line.dy;
		if (line.swap)
			line.y += line.s2;
		else
			line.x += line.s1;
	}
	img_pix_put(&app->img, x2, y2, app->map.color);
}
