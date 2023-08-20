/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcing_player_texture.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayylaaba <ayylaaba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 16:44:57 by ayylaaba          #+#    #+#             */
/*   Updated: 2023/08/19 16:38:52 by ayylaaba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void    init_count(t_count *c)
{
    c->count = 0;
    c->count1 = 0;
    c->count2 = 0;
    c->count3 = 0;
    c->count4 = 0;
    c->i = 0;
}

int     check_map_extantion(char *map)
{
    int i;

    i = 0;
    while (map[i])
        i++;
    while (i >= 0)
    {
        if (map[i] == '.' && map[i])
        {
            if (map[i + 1] == 'c' && map[i + 2] == 'u' && map[i + 3] == 'b' && !map[i + 4])
                return (0);
        }
        i--;
    }
    return (1);
}

int     check_double_element(t_count *c, char **map)
{
    init_count(c);
    while (map[c->i])
    {
        c->trim = ft_strtrim(map[c->i], " ");
        if (c->trim[0] != 1)
        {
            c->a = ft_split(map[c->i], ' ');
            if (!ft_strcmp(c->a[0], "NO"))
                c->count++;
            else if (!ft_strcmp(c->a[0], "SO"))
                c->count1++;
            else if (!ft_strcmp(c->a[0], "EA"))
                c->count2++;
            else if (!ft_strcmp(c->a[0], "WE"))
                c->count3++;
            else if (!ft_strcmp(c->a[0], "F") || !ft_strcmp(c->a[0], "C"))
                c->count4++;
        }
        ft_free(c->a);
        free(c->trim);
        c->i++;
    }
    if (c->count + c->count1 + c->count2 + c->count3 == 4 && c->count4 == 2)
        return (0);
    return (1);
}

int     check_wall_text(t_count *c, char **src)
{
    int     i;
    char    *trim;

    i = 0;
    init_count(c);
    while (src[i])
    {
        trim = ft_strtrim(src[i], " ");
        if (trim[0] == 'N' && trim[1] == 'O')
            c->count++;
        else if (trim[0] == 'W' && trim[1] == 'E')
            c->count1++;
        else if (trim[0] == 'E' && trim[1] == 'A')
            c->count2++;
        else if (trim[0] == 'S' && trim[1] == 'O')
            c->count3++;
        free(trim);
        i++;
    }
    if (c->count + c->count1 + c->count2 + c->count3 == 4)
        return (0);
    return (1);
}
