/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing_part.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhassani <mhassani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 00:33:33 by ayylaaba          #+#    #+#             */
/*   Updated: 2023/08/20 23:09:36 by mhassani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	put_player(t_picture *data, int color)
{
	int	i;

	(void)color;
	data->color = 0x0ff0000;
	data->inf->angle = data->deta + 30;
	i = 0;
	data->f = 0;
	while (data->f < 640)
	{
		hor_int(data, data->inf->angle, data->inf->x, data->inf->y);
		ver_int(data, data->inf->angle, data->inf->x, data->inf->y);
		if (data->ray_distance_hor <= data->ray_distance_ver)
			i = 1;
		else if (data->ray_distance_ver <= data->ray_distance_hor)
			i = 0;
		data->inf->cur_angl = (data->deta - data->inf->angle);
		if (!i)
			data->new_ray_distance = data->ray_distance_ver
				* cos(((data->inf->cur_angl) * M_PI / 180));
		else
			data->new_ray_distance = data->ray_distance_hor
				* cos(((data->inf->cur_angl) * M_PI / 180));
		data->dist_p_screen = 320 / tan(30 * M_PI / 180);
		data->wall_tall = ((64 / data->new_ray_distance) * data->dist_p_screen);
		draw_walls(data);
		data->f++;
		data->inf->angle -= 64.0 / 640.0;
	}
}

void	draw_map(char **map, t_picture *test)
{
	(void)map;
	put_player(test, 0x00FDFD55);
	mlx_put_image_to_window(test->ptr, test->wind, test->image_adrr, 0, 0);
}

void	draw_squar(t_picture *test, int old_x, int old_y, int color)
{
	int	x;
	int	y;

	x = old_x;
	while (x <= old_x + 62)
	{
		y = old_y;
		while (y <= old_y + 62)
			my_put_pixl(test, x, y++, color);
		x++;
	}
}
