/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_helper.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhassani <mhassani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 23:20:09 by mhassani          #+#    #+#             */
/*   Updated: 2023/08/21 00:22:48 by mhassani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	**fill_map_with_spaces(t_picture *data, int max)
{
	int		i;
	int		j;
	char	**str;

	i = 0;
	while (data->map_v3 && data->map_v3[i])
		i++;
	str = malloc(sizeof(char *) * (i + 1));
	i = -1;
	while (data->map_v3 && data->map_v3[++i])
	{
		str[i] = malloc(max + 1);
		j = 0;
		while (data->map_v3[i] && data->map_v3[i][j])
		{
			str[i][j] = data->map_v3[i][j];
			j++;
		}
		while (j < max && ft_strlen(data->map_v3[i]) < max)
			str[i][j++] = ' ';
		str[i][j] = '\0';
	}
	str[i] = NULL;
	return (str);
}

int	player_space(char **map, int i, int j)
{
	if (map[i + 1][j] == ' ')
		return (1);
	else if (map[i - 1][j] == ' ')
		return (1);
	else if (map[i][j + 1] == ' ')
		return (1);
	else if (map[i][j - 1] == ' ')
		return (1);
	return (0);
}

void	check_zero(t_picture *data, char **map)
{
	if (map[data->k][data->l - 1] == ' ' || map[data->k][data->l + 1] == ' ')
		ft_perror("ERROR\n");
	else if (map[data->k - 1][data->l] == ' ' || map[data->k
		+ 1][data->l] == ' ')
		ft_perror("ERROR\n");
}

void	test(t_picture *data, char **map)
{
	data->k = 0;
	while (map && map[data->k])
	{
		data->l = 0;
		while (map[data->k] && map[data->k][data->l])
		{
			if (map[data->k][data->l] == '0')
				check_zero(data, map);
			data->l++;
		}
		data->k++;
	}
	ft_free(map);
}

int	longest_str(t_picture *data)
{
	int	i;
	int	max;

	i = 0;
	max = 0;
	max = ft_strlen(data->map_v3[i]);
	while (data->map_v3 && data->map_v3[i] && ft_strlen(data->map_v3[i + 1]))
	{
		if (max < ft_strlen(data->map_v3[i + 1]))
			max = ft_strlen(data->map_v3[i + 1]);
		i++;
	}
	return (max);
}
