/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayylaaba <ayylaaba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 00:27:12 by ayylaaba          #+#    #+#             */
/*   Updated: 2023/08/19 18:08:45 by ayylaaba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	check_new_line(char *str)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i])
	{
		if (str[i] == '1' && str[i + 1] == '1' && str[i + 2] == '1' && str[i + 3] == '1')
			break;
		i++;
	}
	while(str[i])
	{
		if(str[i] == '\n' && str[i + 1] == '\n')
		{
			while(str[i] == '\n')
				i++;
			if(!str[i])
				return ;
			ft_perror("there is a new line in the map\n");
		}
		i++;
	}
}

void	ft_check_errors(char *map_content, t_picture *test, char **av)
{
	test->map_v2 = ft_split(map_content, '\n');
	test->map_v3 = test->map_v2 + 6;
	if (check_map_extantion(av[1]) || check_character(test->map_v2, test->map_v3, test)
		|| check_wall_text(test->count,test->map_v2) || check_double_element(test->count, test->map_v2))
	{
		if (check_map_extantion(av[1]))
		{
			ft_perror("extenion Is Not Valid\n");
		}
		if (check_wall_text(test->count, test->map_v2))
		{
			ft_perror("Texture Is Not Valid\n");
		}
		if (check_double_element(test->count, test->map_v2))
		{
			ft_perror("Texture Is Duplicat\n");
		}
		if (check_character(test->map_v2, test->map_v3, test))
		{
			ft_perror("Error space around '0'\n");
		}
	}
	check_new_line(map_content);
}

void ft_perror(char *s)
{
	write(2, s, ft_strlen(s));
	exit(1);
}

int	ft_exit(void)
{
	write(1, "safi barka elik \n", 17);
	exit(0);
}