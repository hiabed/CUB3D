/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhassani <mhassani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 18:50:00 by ayylaaba          #+#    #+#             */
/*   Updated: 2023/08/04 23:24:38 by mhassani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_perror(void)
{
	write(2, "ERROR\n", 6);
	exit(1);
}

int	ft_exit(void)
{
	write(1, "safi barka elik \n", 17);
	exit(0);
}

void	my_put_pixl(t_picture *test, int x, int y, int color)
{
	char	*hold_pic_addr;

	if (x < 0 || x >= 640 || y < 0 || y >= 640)
		return ;
	hold_pic_addr = test->adrr + (y * test->len + x * (test->bit_pixl / 8));
	*(unsigned int *)hold_pic_addr = color;
}

char	*get_content(char *str, char c)
{
	int		i;
	int		i2;
	char	*content;

	i = 0;
	i2 = 0;
	while (str[i] && str[i] != c) // skip object (C or F)
		i++;
	while (str[i] == '\t' || str[i] == ' ') // skip space
	{
		i++;
		i2++;
	}
	content = malloc(sizeof(char) * (ft_strlen(str + i) + 1));
	if (!content)
		return (NULL);
	i2 = 0;
	while (str[i])
		content[i2++] = str[i++];
	content[i2] = '\0';
	return (content);
}

int	check_text_ext(char **map)
{
	int		i;
	char	*trim;
	char	*ext;
	char	**wall_pos;
	char	*line_content;

	i = 0;
	while (map[i])
	{
		trim = ft_strtrim(map[i], " ");
		wall_pos = ft_split(trim, ' ');
		if (!ft_strcmp(wall_pos[0], "NO") || !ft_strcmp(wall_pos[0], "WE")
			|| !ft_strcmp(wall_pos[0], "SO") || !ft_strcmp(wall_pos[0], "EA"))
		{
			line_content = get_content(trim, ' ');
			if (!line_content || !line_content[0])
				return (1);
			ext = ft_strrchr(line_content, '.');
			ext++;
			if (ft_strcmp(ext, "xpm"))
				return (1);
		}
		i++;
	}
	return (0);
}

int	is_wall_ray(t_picture *data, int x, int y, int x_p, int y_p, float alpha)
{
	double coss = cos(alpha);
	double sinn = sin(alpha);
	if (data->map_v3[y][x] == '1')
		return (1);
	else if (x != x_p || y != y_p)
	{
		if(coss > 0 && sinn < 0)
		{
			if (data->map_v3[y - 1][x] == '1' && data->map_v3[y][x - 1] == '1')
				return (1);
		}
		else if (coss > 0 && sinn > 0)
		{
			if (data->map_v3[y + 1][x] == '1' && data->map_v3[y][x - 1] == '1')
				return (1);
		}

	}
	else if (x != x_p || y != y_p)
	{
		if (coss < 0 && sinn > 0)
		{
			if (data->map_v3[y + 1][x] == '1' && data->map_v3[y][x + 1] == '1')
				return (1);
		}
		else if (coss < 0 && sinn < 0)
		{
			if (data->map_v3[y - 1][x] == '1' && data->map_v3[y][x + 1] == '1')
				return (1);
		}
	}
	return (0);
}

void	draw_map(char **map, t_picture *test)
{
	test->image_adrr = mlx_new_image(test->ptr, 640, 640);
	test->adrr = mlx_get_data_addr(test->image_adrr, &test->bit_pixl,
	 		&test->len, &test->end);
	inital_draw_wall(test, map);
	mlx_put_image_to_window(test->ptr, test->wind, test->image_adrr, 0, 0);
}

int	give_key(int key, t_picture *test)
{
	if (key == 123)
		test->r_left = 1;
	if (key == 124)
		test->r_right = 1;
	if (key == 13) //w
		test->m_up = 1;
	if (key == 1) //s
		test->m_down = 1;
	if (key == 2) //d
		test->m_left = 1;
	if (key == 0)
		test->m_right = 1;
	if (key == 53) //esc
	{
		write(1, "thella ;)\n", 10);
		exit(0);
	}
	return (0);
}

int	animate_moves(t_picture *test)
{
	test->speed = 2;
	rotation(test);
	move_up(test);
	move_down(test);
	move_left(test);
	move_right(test);
	draw_map(test->map_v3, test);
	return (0);
}

int	key_released(int key, t_picture *test)
{
	if (key == 123)
		test->r_left = 0;
	else if (key == 124)
		test->r_right = 0;
	else if (key == 13)
		test->m_up = 0;
	else if (key == 1)
		test->m_down = 0;
	else if (key == 2)
		test->m_left = 0;
	else if (key == 0)
		test->m_right = 0;
	return (0);
}

t_picture	*initialize_structure(int ac, char **av)
{
	t_picture	*test;
	int			fd;
	char		*map_content;

	test = malloc(sizeof(t_picture));
	if (ac != 2)
		ft_perror();
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
	test->map = ft_strdup(av[1]);
	fd = open(test->map, O_RDONLY);
	map_content = get_next_line(fd);
	test->map_v2 = ft_split(map_content, '\n');
	test->map_v3 = test->map_v2 + 6;
	test->deta = 90;
	return (test);
}

int	main(int ac, char **av)
{
	t_picture	*test;

	test = initialize_structure(ac, av); // intial the all stract's member.
	if (check_map_extantion(test->map) || check_character(test->map_v2)
		|| check_wall_text(test->map_v2) || check_double_element(test->map_v2))
		ft_perror();
	init_player(test->map_v3, test); // get player pos (x, y).
	test->ptr = mlx_init();
	test->wind = mlx_new_window(test->ptr, 640, 640, "cub3d");
	test->image_adrr = mlx_new_image(test->ptr, 640, 640);
	test->adrr = mlx_get_data_addr(test->image_adrr, &test->bit_pixl, &test->len, &test->end); // this fun 
	test->r_left = 0;
	test->r_right = 0;
	draw_map(test->map_v3, test); // start from here.
	mlx_hook(test->wind, 17, 0, ft_exit, NULL);
	mlx_hook(test->wind, 2, 0, give_key, test);
	mlx_hook(test->wind, 3, 0, key_released, test);
	mlx_loop_hook(test->ptr, animate_moves, test);
	mlx_loop(test->ptr);
}