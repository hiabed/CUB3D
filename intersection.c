/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersection.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhassani <mhassani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 19:27:21 by mhassani          #+#    #+#             */
/*   Updated: 2023/08/12 20:29:39 by mhassani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_picture	*ver_int(t_picture *data, float angle, float x_i, float y_i)
{
	float	rad;
	
	rad = angle * M_PI / 180;
	// if(cos(rad) == 0)
	// {
	// 	data->ray_distance_ver = 2147483647;
	// 	return data;
	// }
	if (cos(rad) < 0) // player look left
	{
		x_i = (int)(data->x_p / 64) * 64;
		y_i = data->y_p + (data->x_p - x_i) * tan(rad);
	}
	if (cos(rad) > 0) // player look rhit
	{
		x_i = (int)(data->x_p / 64) * 64 + 64;
		y_i = data->y_p + (data->x_p - x_i) * tan(rad);
	}
	while (!is_wall(data, (x_i / 64) - (cos(rad) < 0), y_i / 64))
	{
		if (cos(rad) < 0){
			x_i -= 64;
			y_i = data->y_p + (data->x_p - x_i) * tan(rad);
		}
		if (cos(rad) > 0){
			x_i += 64;
			y_i = data->y_p + (data->x_p - x_i) * tan(rad);
		}
	}
	data->ray_distance_ver = sqrt(pow(x_i - data->x_p, 2) + pow(y_i - data->y_p, 2));
	data->tx_ver = x_i;
	data->ty_ver = y_i;
	return (data);
}

t_picture	*hor_int(t_picture *data, float angle, float x_i, float y_i)
{
	float	rad;
	
	rad = angle * M_PI / 180;
	// if(cos(rad) == 0)
	// {
	// 	data->ray_distance_ver = 2147483647;
	// 	return data;
	// }
	if (sin(rad) > 0) // player look left
		y_i = (int)(data->y_p / 64) * 64;
	if (sin(rad) < 0) // player look rhit
		y_i = (int)(data->y_p / 64) * 64 + 64;
	x_i = data->x_p + (data->y_p - y_i) / tan(rad);
	while (!is_wall(data, x_i / 64, (y_i / 64) - (sin(rad) > 0)))
	{
		if (sin(rad) > 0)
			y_i -= 64;
		if (sin(rad) < 0)
			y_i += 64;
		x_i = data->x_p + (data->y_p - y_i) / tan(rad);
		
	}
	data->ray_distance_hor = sqrt(pow(x_i - data->x_p, 2) + pow(y_i - data->y_p, 2));
	data->tx_hor = x_i;
	data->ty_hor = y_i;
	return (data);
}