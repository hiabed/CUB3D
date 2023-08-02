/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhassani <mhassani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 10:35:05 by ayylaaba          #+#    #+#             */
/*   Updated: 2023/08/02 19:36:09 by mhassani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_player(char **map, t_picture *test)
{
	int	x;
	int	y;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == 'N' || map[y][x] == 'S' || map[y][x] == 'E'
				|| map[y][x] == 'W')
			{
				test->x_p = x * 64 + 32; // we add 32 to make player in centre
				test->y_p = y * 64 + 32;
				test->color = 0x00FDFD55;
				map[y][x] = '0';
			}
			x++;
		}
		y++;
	}
}

void	move_up(t_picture *data)
{
    double x,y;
    data->ray_pos = data->deta * M_PI / 180;
    x = data->x_p + cos(data->ray_pos) * data->speed;
    y = data->y_p - sin(data->ray_pos) * data->speed;
	if (!data->m_up)
		return ;
    else if (!is_wall_ray(data, x / 64, y / 64, data->x_p, data->y_p, data->deta * M_PI / 180))
    {
        data->x_p += cos(data->ray_pos) * data->speed;
        data->y_p -= sin(data->ray_pos) * data->speed;
    }
}

void	move_down(t_picture *data)
{
       double x = data->x_p,y = data->y_p;
    data->ray_pos = (data->deta) * M_PI / 180;
    x -= cos(data->ray_pos) * data->speed;
    y += sin(data->ray_pos) * data->speed;
	if (!data->m_down)
		return ;

    else if (!is_wall_ray(data, x / 64, y / 64, data->x_p, data->y_p, data->deta * M_PI / 180))
    {
        data->x_p -= cos(data->ray_pos) * data->speed;
        data->y_p += sin(data->ray_pos) * data->speed;
    }
}

void	move_right(t_picture *data)
{
    double x, y;
    data->ray_pos = (data->deta + 90) * M_PI / 180;
    // for check;
    x = data->x_p + cos(data->ray_pos) * data->speed;
    y = data->y_p - sin(data->ray_pos) * data->speed;
	if (!data->m_right)
		return ;
    else if (!is_wall_ray(data, x / 64, y / 64, data->x_p, data->y_p, data->deta * M_PI / 180))
    {
        //change player position after check;
        data->x_p += cos(data->ray_pos) * data->speed;
        data->y_p -= sin(data->ray_pos) * data->speed;
    }
}

void	move_left(t_picture *data)
{
    double x, y;
    data->ray_pos = (data->deta - 90) * M_PI / 180;
    x = data->x_p + cos(data->ray_pos) * data->speed;
    y = data->y_p - sin(data->ray_pos) * data->speed;
	if (!data->m_left)
		return ;
    else if (!is_wall_ray(data, x / 64, y / 64, data->x_p, data->y_p, data->deta * M_PI / 180))
    {
        data->x_p += cos(data->ray_pos) * data->speed;
        data->y_p -= sin(data->ray_pos) * data->speed;
    }
}

void	rotation(t_picture *data)
{
	if (data->r_left)
	{
		data->deta += 3;
	}
	else if (data->r_right)
	{
		data->deta -= 3;
	}
}
