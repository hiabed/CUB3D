/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcing_color.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhassani <mhassani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 11:18:47 by ayylaaba          #+#    #+#             */
/*   Updated: 2023/08/20 20:21:11 by mhassani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

long long	ft_atoi(const char *str)
{
	int	i;
	long long	result;
	long long	sign;

	i = 0;
	result = 0;
	sign = 1;
    if (!str || !str[0])
       return (0);
	while (str[i] && (str[i] == ' ' || str[i] == '\t' || str[i] == '\f'
		|| str[i] == '\r' || str[i] == '\n' || str[i] == '\v'))
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
    int i = 0;

    number = ft_split(str, ',');
    if (!ft_isdigit(number[0]) || !ft_isdigit(number[1]) || !ft_isdigit(number[2]))
    {
        ft_free(number);
        ft_perror("Is Not Valid RGB\n");
    }
    if (ft_atoi(number[0]) < 0 || ft_atoi(number[1]) < 0 || ft_atoi(number[2]) < 0)
    {
        ft_free(number);   
        ft_perror("Is Not Valid RGB\n");
    }
    while (i < 3)
    {
        if (!(ft_atoi(number[i]) >= 0 && ft_atoi(number[i]) <= 255) 
            || (ft_atoi(number[i]) > INT_MAX))
            {
                ft_free(number);
                ft_perror("Is Not Valid RGB\n");
            }
        i++;
    }
    if (ch == 'C')
        data->c_color = (ft_atoi(number[0]) * 256 * 256) + (ft_atoi(number[1]) * 256) + ft_atoi(number[2]);
    else if (ch == 'F')
        data->f_color = (ft_atoi(number[0]) * 256 * 256) + (ft_atoi(number[1]) * 256) + ft_atoi(number[2]);
    ft_free(number);
    return (0);
}

int     comma(char *str)
{
    int     i;
    int     count;

    i = 0;
    count = 0;
    while (str[i])
    {
        if (str[i] == ',')
            count++;
        i++;
    }
    if (count != 2)
        return (1);
    return (0);
}

int     check_color(char **map, t_picture *data)
{
    int     i;
    int     j;
    char    *trim;
    char    *line_content;
    char    ch;
    
    i = 0;
    while (map[i])
    {
        j = 0;
        trim = ft_strtrim(map[i], " ");
        if (trim[0] == 'C' || trim[0] == 'F')
        {
            ch = trim[0];
            line_content = get_content(trim, ' ');
            if (comma(line_content))
            {
                free(line_content);
                free(trim);
                ft_perror ("more than comma in RGB\n");  
            }
            if (check_number(line_content, ch, data))
            {
                free(line_content);
                free(trim);
                return (1);
            }
            free(line_content);
        }
        free(trim);
        i++;
    } 
    return (0);
}
