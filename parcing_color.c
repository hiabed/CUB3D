/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcing_color.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhassani <mhassani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 11:18:47 by ayylaaba          #+#    #+#             */
/*   Updated: 2023/08/17 21:03:22 by mhassani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int     check_number(char *str, char ch, t_picture *data)
{
    char    **number;

    number = ft_split(str, ',');
    if (!ft_isdigit(number[0]) || !ft_isdigit(number[1]) || !ft_isdigit(number[2]))
        return (1);
    if (atoi(number[0]) <= 0 || atoi(number[1]) <= 0 || atoi(number[2]) <= 0)
        return (1);
    if (ch == 'C')
        data->c_color = (atoi(number[0]) * 256 * 256) + (atoi(number[1]) * 256) + atoi(number[2]);
    else if (ch == 'F')
        data->f_color = (atoi(number[0]) * 256 * 256) + (atoi(number[1]) * 256) + atoi(number[2]);
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
            c = 0;
        }
        free(trim);
        i++;
    }
    free(line_content);
    return (0);
}
