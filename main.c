/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhassani <mhassani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 18:50:00 by ayylaaba          #+#    #+#             */
/*   Updated: 2023/08/20 23:08:33 by mhassani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	is_wall(t_picture *data, float x, float y)
{
	int	j;
	int	i;

	j = 0;
	while (data->map_v3 && data->map_v3[j])
		j++;
	if (y >= j || x < 0 || y < 0)
		return (1);
	i = 0;
	while (data->map_v3[(int)y] && data->map_v3[(int)y][(int)i])
		i++;
	if (x >= i)
		return (1);
	if (data->map_v3[(int)y][(int)x] == '1')
	{
		return (1);
	}
	return (0);
}

int	main(int ac, char **av)
{
	t_picture	*test;

	test = initialize_structure(ac, av);
	init_player(test->map_v3, test);
	test->ptr = mlx_init();
	test->wind = mlx_new_window(test->ptr, 640, 640, "cub3d");
	test->image_adrr = mlx_new_image(test->ptr, 640, 640);
	test->adrr = mlx_get_data_addr(test->image_adrr, &test->bit_pixl,
			&test->len, &test->end);
	if (!test->adrr)
		ft_perror("Error\n");
	test->r_left = 0;
	test->r_right = 0;
	initialize_images(test);
	draw_map(test->map_v3, test);
	put_player(test, test->color);
	mlx_hook(test->wind, 17, 0, ft_exit, NULL);
	mlx_hook(test->wind, 2, 3, give_key, test);
	mlx_hook(test->wind, 3, 0, key_released, test);
	mlx_loop_hook(test->ptr, animate_moves, test);
	mlx_loop(test->ptr);
}
