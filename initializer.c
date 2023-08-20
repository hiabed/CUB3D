/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initializer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhassani <mhassani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 00:28:13 by ayylaaba          #+#    #+#             */
/*   Updated: 2023/08/20 23:24:11 by mhassani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	initialize_images(t_picture *data)
{
	data->imgs = malloc(4 * sizeof(t_imgs));
	data->imgs[0].img = mlx_xpm_file_to_image(data->ptr, data->north_xpm,
			&data->imgs[0].width, &data->imgs[0].height);
	if (!data->imgs[0].img)
		ft_perror("can't load the image\n");
	data->imgs[0].add = mlx_get_data_addr(data->imgs[0].img,
			&data->imgs[0].bits, &data->imgs[0].line, &data->imgs[0].wa33);
	data->imgs[1].img = mlx_xpm_file_to_image(data->ptr, data->east_xpm,
			&data->imgs[1].width, &data->imgs[1].height);
	if (!data->imgs[1].img)
		ft_perror("can't load the image\n");
	data->imgs[1].add = mlx_get_data_addr(data->imgs[1].img,
			&data->imgs[1].bits, &data->imgs[1].line, &data->imgs[1].wa33);
	data->imgs[2].img = mlx_xpm_file_to_image(data->ptr, data->west_xpm,
			&data->imgs[2].width, &data->imgs[2].height);
	if (!data->imgs[2].img)
		ft_perror("can't load the image\n");
	data->imgs[2].add = mlx_get_data_addr(data->imgs[2].img,
			&data->imgs[2].bits, &data->imgs[2].line, &data->imgs[2].wa33);
	data->imgs[3].img = mlx_xpm_file_to_image(data->ptr, data->south_xpm,
			&data->imgs[3].width, &data->imgs[3].height);
	if (!data->imgs[3].img)
		ft_perror("can't load the image\n");
	data->imgs[3].add = mlx_get_data_addr(data->imgs[3].img,
			&data->imgs[3].bits, &data->imgs[3].line, &data->imgs[3].wa33);
}

t_picture	*initialize_structure(int ac, char **av)
{
	t_picture	*test;
	int			fd;
	char		*map_content;

	test = malloc(sizeof(t_picture));
	test->inf = malloc(sizeof(t_inf));
	test->count = malloc(sizeof(t_count));
	if (ac != 2)
		ft_perror("wrong argment\n");
	if (!test)
	{
		printf("Error\n");
		return (NULL);
	}
	test->move_check = 0;
	test->m_up = 0;
	test->m_down = 0;
	test->m_left = 0;
	test->m_right = 0;
	test->r_left = 0;
	test->r_right = 0;
	fd = open(av[1], O_RDONLY);
	map_content = get_next_line(fd);
	if (!map_content || !map_content[0] || fd < 0)
		ft_perror("Empty map");
	ft_check_errors(map_content, test, av);
	initialize_the_angle_of_player(test);
	return (test);
}

void	initialize_the_angle_of_player(t_picture *test)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (test->map_v3[j])
	{
		i = 0;
		while (test->map_v3[j][i])
		{
			if (test->map_v3[j][i] == 'N')
				test->deta = 90;
			else if (test->map_v3[j][i] == 'S')
				test->deta = 270;
			else if (test->map_v3[j][i] == 'E')
				test->deta = 0;
			else if (test->map_v3[j][i] == 'W')
				test->deta = 180;
			i++;
		}
		j++;
	}
}

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
				test->x_p = x * 64 + 32;
				test->y_p = y * 64 + 32;
				test->color = 0x00FDFD55;
				map[y][x] = '0';
			}
			x++;
		}
		y++;
	}
}
