/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayylaaba <ayylaaba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 00:59:50 by ayylaaba          #+#    #+#             */
/*   Updated: 2023/08/19 01:00:43 by ayylaaba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	animate_moves(t_picture *test)
{
	test->speed = 1.5;
	rotation(test);
	move_up(test);
	move_down(test);
	move_left(test);
	move_right(test);
	draw_map(test->map_v3, test);
	return (0);
}

int ft_check_move(t_picture *data ,double x, double y)
{
    if (data->map_v3[(int)(y / 64)][(int)(data->x_p / 64)] != '1')
    {
        if (data->map_v3[(int)(data->y_p / 64)][(int)(x / 64)] != '1')
        {
            if (data->map_v3[(int)(y / 64)][(int)(x / 64)] != '1')
                return 1;
        }
    }
    return (0);
}
