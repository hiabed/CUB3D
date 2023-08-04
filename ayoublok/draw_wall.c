/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_wall.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhassani <mhassani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 09:37:22 by ayylaaba          #+#    #+#             */
/*   Updated: 2023/08/04 23:21:45 by mhassani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_wall(t_picture * data)
{
	double		start;
	double		end;

	start = 320 - (data->wall_tall / 2);
	end = start + data->wall_tall;
	while (start < end)
	{
		my_put_pixl(data, data->f , start , 0xffffff);
		start++;
	}
}

void	inital_draw_wall(t_picture *data, char **map)
{
	(void)map;
	double	angl;
	double	cur_angl;
	double	g;
	double	rad;
	double	x;
	double	y;

	data->ray_distance = 0;
	angl = data->deta - 30;  //60 degree;
	data->color = 0x0ff0000; //red;
	data->f = -1;
	g =  (float)(60 / 640);
	while (data->f < 640)
	{
		x = data->x_p;
		y = data->y_p;
		rad = angl * M_PI / 180.0;
		data->ray_distance 	= 0;
		while (!is_wall_ray(data, x / 64, y / 64, data->x_p, data->y_p, rad)) //check if the ray hit a wall;
		{
			x += cos(rad);
			y -= sin(rad);
			data->ray_distance++;
		}
		printf("distance : %f\n", data->ray_distance);
		// data->ray_distance = sqrt(pow(y - data->y_p, 2) + pow(x - data->x_p, 2));
		angl += (60.0 / 640.0); // 0.09375.
		cur_angl = (data->deta - angl);
		data->new_ray_distance = (data->ray_distance) * cos(((cur_angl) * M_PI / 180));
		data->dist_p_screen	= 320 / tan(30 * M_PI / 180);
		data->wall_tall	= ((64 / data->new_ray_distance) * data->dist_p_screen);
		data->f++;
		draw_wall(data);
	}
}
