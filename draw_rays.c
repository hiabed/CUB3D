/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_rays.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhassani <mhassani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 00:29:13 by ayylaaba          #+#    #+#             */
/*   Updated: 2023/08/20 23:03:09 by mhassani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_horizontal_ray(t_picture *data, float angle)
{
	int		i;
	float	x;
	float	y;
	float	rad;

	rad = angle * M_PI / 180;
	x = data->x_p;
	y = data->y_p;
	i = 0;
	while (i <= data->ray_distance_hor)
	{
		my_put_pixl(data, x, y, data->color);
		x += cos(rad);
		y -= sin(rad);
		i++;
	}
}

void	draw_vertical_ray(t_picture *data, float angle)
{
	int i;
	float x;
	float y;
	float rad;

	x = data->x_p;
	y = data->y_p;
	rad = angle * M_PI / 180;
	i = 0;
	while (i <= data->ray_distance_ver)
	{
		my_put_pixl(data, x, y, data->color);
		x += cos(rad);
		y -= sin(rad);
		i++;
	}
}
