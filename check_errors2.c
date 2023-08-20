/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_errors2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhassani <mhassani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 00:57:51 by ayylaaba          #+#    #+#             */
/*   Updated: 2023/08/20 23:03:20 by mhassani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_textures(char *line_content, char *wall_pos, t_picture *data)
{
	char	*ext;
	int		x;

	data->tmp = ft_strdup(line_content);
	x = 0;
	if (!ft_strcmp(wall_pos, "NO"))
		data->north_xpm = data->tmp;
	if (!ft_strcmp(wall_pos, "SO"))
		data->south_xpm = data->tmp;
	if (!ft_strcmp(wall_pos, "EA"))
		data->east_xpm = data->tmp;
	if (!ft_strcmp(wall_pos, "WE"))
		data->west_xpm = data->tmp;
	if (!line_content || !line_content[0])
		return (1);
	ext = ft_strrchr(data->tmp, '.');
	ext++;
	if (ft_strcmp(ext, "xpm"))
		return (1);
	return (0);
}

int	check_text_ext(char **map, t_picture *data)
{
	int		i;
	char	*trim;
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
			check_textures(line_content, wall_pos[0], data);
			free(line_content);
		}
		// free(data->tmp);
		free(trim);
		ft_free(wall_pos);
		i++;
	}
	return (0);
}
