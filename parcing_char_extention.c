/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcing_char_extention.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhassani <mhassani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 16:41:59 by ayylaaba          #+#    #+#             */
/*   Updated: 2023/08/21 00:35:29 by mhassani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_player_pos(char **str, t_inf *info, int i, int j)
{
	info->count = 0;
	while (str[++i])
	{
		j = -1;
		info->trim = ft_strtrim(str[i], " ");
		while (info->trim[++j])
		{
			if ((info->trim[0] == '0' || info->trim[0] == '1')
				&& info->trim[j] == 'N')
				info->count++;
			else if ((info->trim[0] == '0' || info->trim[0] == '1')
				&& info->trim[j] == 'S')
				info->count++;
			else if ((info->trim[0] == '0' || info->trim[0] == '1')
				&& info->trim[j] == 'W')
				info->count++;
			else if ((info->trim[0] == '0' || info->trim[0] == '1')
				&& info->trim[j] == 'E')
				info->count++;
		}
		free(info->trim);
	}
	if (info->count == 1)
		return (0);
	return (1);
}

int	character(char **map)
{
	int	i;
	int	j;

	i = -1;
	while (map[++i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] != '1' && map[i][j] != '0' && map[i][j] != 'W'
				&& map[i][j] != 'E' && map[i][j] != ' ' && map[i][j] != 'N'
				&& map[i][j] != 'S')
				return (1);
			if (map[i][j] == 'W' || map[i][j] == 'E' || map[i][j] == 'N'
				|| map[i][j] == 'S')
			{
				if (player_space(map, i, j))
					return (1);
			}
			j++;
		}
	}
	return (0);
}

int	front_end_wall(char *str)
{
	int		i;
	char	*trim;

	i = 0;
	trim = ft_strtrim(str, " ");
	while (trim[i])
	{
		if (trim[i] == ' ')
			i++;
		else if (trim[i] != '1')
		{
			free(trim);
			return (1);
		}
		i++;
	}
	free(trim);
	return (0);
}

int	check_wall(char **map)
{
	int		i;
	int		j;
	char	*trim;

	j = 0;
	i = 0;
	while (map && map[j])
	{
		trim = ft_strtrim(map[j], " ");
		if (trim[0] != '1' || trim[ft_strlen(trim) - 1] != '1')
		{
			free(trim);
			return (1);
		}
		free(trim);
		j++;
	}
	i = 0;
	while (map[i])
		i++;
	i--;
	if (front_end_wall(map[0]) || front_end_wall(map[i]))
		return (1);
	return (0);
}

int	check_character(char **s, char **s2, t_picture *data)
{
	int		max;
	char	**map;

	max = 0;
	if (check_wall(s2))
		ft_perror("Error\n");
	if (check_player_pos(s, data->inf, -1, -1) || character(s2) \
		|| check_color(s, data) || check_text_ext(s, data))
	{
		if (check_player_pos(s, data->inf, -1, -1))
			ft_perror("Issue In Player\n");
		if (character(s2))
			ft_perror("Error\n");
	}
	max = longest_str(data);
	map = fill_map_with_spaces(data, max);
	test(data, map);
	return (0);
}
