/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_keys.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhassani <mhassani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 00:56:26 by ayylaaba          #+#    #+#             */
/*   Updated: 2023/08/20 23:36:03 by mhassani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	key_released(int key, t_picture *test)
{
	if (key == 65361)
		test->r_left = 0;
	else if (key == 65363)
		test->r_right = 0;
	else if (key == 119)
		test->m_up = 0;
	else if (key == 115)
		test->m_down = 0;
	else if (key == 100)
		test->m_left = 0;
	else if (key == 97)
		test->m_right = 0;
	return (0);
}

int	give_key(int key, t_picture *test)
{
	if (key == 65361)
		test->r_left = 1;
	if (key == 65363)
		test->r_right = 1;
	if (key == 119)
		test->m_up = 1;
	if (key == 115)
		test->m_down = 1;
	if (key == 100)
		test->m_left = 1;
	if (key == 97)
		test->m_right = 1;
	if (key == 65307)
	{
		write (1, "exit\n", 5);
		exit(0);
	}
	return (0);
}
