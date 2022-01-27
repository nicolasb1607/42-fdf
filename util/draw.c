/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nburat-d <nburat-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 18:01:13 by nburat-d          #+#    #+#             */
/*   Updated: 2022/01/27 11:05:41 by nburat-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_fdf.h"

void	draw_pixel(t_point p0, t_point p1, t_app *app)
{
	if (p0.x < app->map.width - 1)
	{
		p1.x = p0.x + 1;
		p1.y = p0.y;
		bres(p0, p1, app);
	}
	if (p0.y < app->map.height - 1)
	{
		p1.x = p0.x;
		p1.y = p0.y + 1;
		bres(p0, p1, app);
	}
}

int	draw(t_app *app)
{
	t_point	p0;
	t_point	p1;

	p0.y = 0;
	while (p0.y < app->map.height)
	{
		p0.x = 0;
		while (p0.x < app->map.width)
		{
			draw_pixel(p0, p1, app);
			p0.x++;
		}
		p0.y++;
	}
	return (0);
}
