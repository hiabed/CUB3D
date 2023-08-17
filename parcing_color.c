/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcing_color.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhassani <mhassani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 11:18:47 by ayylaaba          #+#    #+#             */
/*   Updated: 2023/08/17 21:39:10 by mhassani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_atoi(const char *str)
{
	int	i;
	int	result;
	int	sign;

	i = 0;
	result = 0;
	sign = 1;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\f'
		|| str[i] == '\r' || str[i] == '\n' || str[i] == '\v')
		i++;
	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (str[i] >= 48 && str[i] <= 57)
	{
		result = result * 10 + str[i] - '0';
		i++;
	}
	return (sign * result);
}

int     check_number(char *str, char ch, t_picture *data)
{
    char    **number;

    number = ft_split(str, ',');
    if (!ft_isdigit(number[0]) || !ft_isdigit(number[1]) || !ft_isdigit(number[2]))
        return (1);
    if (ft_atoi(number[0]) <= 0 || ft_atoi(number[1]) <= 0 || ft_atoi(number[2]) <= 0)
        return (1);
    if (ch == 'C')
        data->c_color = (ft_atoi(number[0]) * 256 * 256) + (ft_atoi(number[1]) * 256) + ft_atoi(number[2]);
    else if (ch == 'F')
        data->f_color = (ft_atoi(number[0]) * 256 * 256) + (ft_atoi(number[1]) * 256) + ft_atoi(number[2]);
    ft_free(number);
    return (0);
}

int     check_color(char **map, t_picture *data)
{
    int     i;
    int     j;
    int     c;
    char    *trim;
    char    *line_content;
    char    ch;
    
    i = 0;
    c = 0;
    while (map[i])
    {
        j = 0;
        trim = ft_strtrim(map[i], " ");
        if (trim[0] == 'C' || trim[0] == 'F')
        {
            ch = trim[0];
            line_content = get_content(trim, ' ');
            while (line_content[j])
            {
                if (line_content[j] == ',')
                    c++;
                j++;
            }   
            if (c != 2 || check_number(line_content, ch, data))
            {
                return (1);
            }
            free(line_content);
            c = 0;
        }
        free(trim);
        i++;
    }
    return (0);
}
