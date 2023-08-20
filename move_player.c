/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhassani <mhassani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 10:35:05 by ayylaaba          #+#    #+#             */
/*   Updated: 2023/08/20 02:19:44 by mhassani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	move_up(t_picture *data)
{
    double x,y;
    data->ray_pos = data->deta * M_PI / 180;
    x = data->x_p + cos(data->ray_pos) * data->speed;
    y = data->y_p - sin(data->ray_pos) * data->speed;
	if (!data->m_up)
		return ;
    if (!ft_check_move(data, x, y))
        return ;
    else if (!is_wall(data, x / 64, y / 64))
    {
        data->x_p += cos(data->ray_pos) * data->speed;
        data->y_p -= sin(data->ray_pos) * data->speed;
        return ;
    }
    // else if (!is_wall(data, data->x_p / 64, y / 64))
    // {
    //     data->y_p -= sin(data->ray_pos) * data->speed;
    //     return ;
    // }
    // else if (!is_wall(data, x / 64, data->y_p / 64))
    // {
    //     data->x_p += cos(data->ray_pos) * data->speed;
    //     return ;
    // }
}

void	move_down(t_picture *data)
{
    double x = data->x_p,y = data->y_p;
    data->ray_pos = (data->deta) * M_PI / 180;
    x -= cos(data->ray_pos) * data->speed;
    y += sin(data->ray_pos) * data->speed;
	if (!data->m_down)
		return ;
    if (!ft_check_move(data, x,y))
        return ;
    else if (!is_wall(data, x / 64, y / 64))
    {
        data->x_p -= cos(data->ray_pos) * data->speed;
        data->y_p += sin(data->ray_pos) * data->speed;
    }
}

void	move_right(t_picture *data)
{
    double x, y;
    data->ray_pos = (data->deta + 90) * M_PI / 180;
    x = data->x_p + cos(data->ray_pos) * data->speed;
    y = data->y_p - sin(data->ray_pos) * data->speed;
	if (!data->m_right)
		return ;
    if (!ft_check_move(data, x,y))
        return ;
    else if (!is_wall(data, x / 64, y / 64))
    {
        // change player position after wall check;
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
     if (!ft_check_move(data, x,y))
        return ;
    else if (!is_wall(data, x / 64, y / 64))
    {
        data->x_p += cos(data->ray_pos) * data->speed;
        data->y_p -= sin(data->ray_pos) * data->speed;
    }
}

void	rotation(t_picture *data)
{
	if (data->r_left)
	{
		data->deta += 1.5;
        if(data->deta >= 360.0)
            data->deta = 0.0;
	}
	else if (data->r_right)
	{
		data->deta -= 1.5;
        if(data->deta >= 360.0)
            data->deta = 0.0;
	}
}
