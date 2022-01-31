/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nburat-d <nburat-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 13:55:52 by nburat-d          #+#    #+#             */
/*   Updated: 2022/01/31 18:46:46 by nburat-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_fdf.h"

int	sign(int x)
{
	if (x > 0)
		return (1);
	else if (x < 0)
		return (-1);
	else
		return (0);
}

void	swap(t_line *line)
{
	line->temp = line->dx;
	line->dx = line->dy;
	line->dy = line->temp;
	line->swap = 1;
}

void	ft_put_pixel(t_line *line, t_app *app)
{
	if (line->dy > line->dx)
		swap(line);
	line->p = 2 * line->dy - line->dx;
	line->i = 0;
	while (line->i < line->dx)
	{
		if (line->x > 0 && line->x < WINDOW_WIDTH && line->y > 0
			&& line->y < WINDOW_HEIGHT)
			img_pix_put(&app->img, line->x, line->y, app->map.color);
		while (line->p >= 0)
		{
			line->p = line->p - 2 * line->dx;
			if (line->swap)
				line->x += line->s1;
			else
				line->y += line->s2;
		}
		line->p = line->p + 2 * line->dy;
		if (line->swap)
			line->y += line->s2;
		else
			line->x += line->s1;
		line->i++;
	}
}

void	bres(t_point p1, t_point p2, t_app *app)
{
	t_line	line;
	int		z1;
	int		z2;

	z1 = app->map.z_val[p1.y][p1.x];
	z2 = app->map.z_val[p2.y][p2.x];
	apply_color(p1.x, p1.y, p2.x, p2.y, app);
	apply_zoom(&p1.x, &p1.y, &p2.x, &p2.y, app);
	isometric(&p1.x, &p1.y, z1, app);
	isometric(&p2.x, &p2.y, z2, app);
	//change_pos(&p1.x, &p1.y, &p2.x, &p2.y, app);
	line.x = p1.x;
	line.y = p1.y;
	line.dx = abs(p2.x - p1.x);
	line.dy = abs(p2.y - p1.y);
	line.s1 = sign(p2.x - p1.x);
	line.s2 = sign(p2.y - p1.y);
	line.swap = 0;
	if (p1.x > 0 && p1.x < WINDOW_WIDTH && p1.y > 0 && p1.y < WINDOW_HEIGHT)
		img_pix_put(&app->img, p1.x, p1.y, app->map.color);
	ft_put_pixel(&line, app);
	if (p2.x > 0 && p2.x < WINDOW_WIDTH && p2.y > 0 && p2.y < WINDOW_HEIGHT)
		img_pix_put(&app->img, p2.x, p2.y, app->map.color);
}
