/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcing_char_extention.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhassani <mhassani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 16:41:59 by ayylaaba          #+#    #+#             */
/*   Updated: 2023/08/20 17:20:44 by mhassani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int     player_space( char **map, int i, int j)
{
    if (map[i + 1][j] == ' ')
        return (1);
    else if (map[i  - 1][j] == ' ')
        return (1);
    else if (map[i][j + 1] == ' ')
        return (1);
    else if (map[i + 1][j - 1] == ' ')
        return (1);
    return (0);
}

int     check_player_pos(char **str, t_inf *info)
{
    int i;
    int j;

    i = -1;
    info->count = 0;
    while (str[++i])
    {
        j = -1;
        info->trim = ft_strtrim(str[i], " ");
        while (info->trim[++j])
        {
            if ((info->trim [0] == '0' || info->trim [0] == '1') && info->trim [j] == 'N')
                 info->count++;
            else  if ((info->trim [0] == '0' || info->trim [0] == '1') && info->trim [j] == 'S')
                 info->count++;
            else  if ((info->trim [0] == '0' || info->trim [0] == '1') && info->trim [j] == 'W')
                 info->count++;
            else  if ((info->trim [0] == '0' || info->trim [0] == '1') && info->trim [j] == 'E')
                 info->count++;
        }
        free(info->trim);
    }
    if (info->count== 1)
        return (0);
    return (1);
}

int     character(char **map)
{
    int     i;
    int     j;
    char    *trim;

    i = -1;
    while (map[++i])
    {
        j = -1;
        trim = ft_strtrim(map[i], " ");
        if (trim[0] == '1')
        {
            while (map[i][++j])
            {
                if (map[i][j] != '1' && map[i][j] != '0' && map[i][j] != 'W' && map[i][j] != 'E' && map[i][j] != ' ' && map[i][j] != 'N' && map[i][j] != 'S')
                {
                    free (trim);
                    return (1);
                }
                if (map[i][j] == 'W' || map[i][j] == 'E' || map[i][j] == 'N' || map[i][j] == 'S')
                {
                    if (player_space(map, i, j))
                    {
                        free(trim);
                        return (1);
                    }
                }
            }
        }
        free(trim);
    }
    return (0);
}

int    front_end_wall(char *str)
{
    int i;
    char    *trim;

    i = 0;
    trim = ft_strtrim(str, " ");
    while (trim[i])
    {
        if (trim[i] != '1')
            return (1);
        i++;
    }
    free(trim);
    return (0);
}
int     check_wall(char **map)
{
    int     i;
    int     j;
    char    *trim;

    j = 0;
    i = 0;
    
    while (map[j]) // wall first and last char
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

void    check_zero(t_picture *data, char **map)
{
    if (map[data->k][data->l - 1] == ' ' || map[data->k][data->l + 1] == ' ')
        ft_perror("ERROR\n");
    else if (map[data->k - 1][data->l] == ' ' || map[data->k + 1][data->l] == ' ')
        ft_perror("ERROR\n");
}

void    test(t_picture *data, char **map)
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

int     longest_str(t_picture *data)
{
    int i = 0;
    int max = 0;
    max = ft_strlen(data->map_v3[i]);
    while(data->map_v3 && data->map_v3[i] && ft_strlen(data->map_v3[i + 1]))
    {
        if (max <  ft_strlen(data->map_v3[i + 1]))
            max = ft_strlen(data->map_v3[i + 1]);
        i++;
    }
    return (max);
}

char    **fill_map_with_spaces(t_picture *data, int max)
{
    int i = 0;
    int j;
    while(data->map_v3 && data->map_v3[i])
        i++;
    char **str = malloc(sizeof(char *) * (i + 1));
    i = 0;
    while(data->map_v3 && data->map_v3[i])
    {
        str[i] = malloc(max + 1);
        j = 0;
        while(data->map_v3[i] && data->map_v3[i][j])
        {
            str[i][j] = data->map_v3[i][j];
            j++;
        }
        while(j < max && ft_strlen(data->map_v3[i]) < max)
        {
            str[i][j] = ' ';
            j++;
        }
        str[i][j] = '\0';
        printf ("== %sa\n", str[i]);
        i++;
    }
    str[i] = NULL;
    return str;
}

int     check_character(char **s, char **s2, t_picture *data)
{
    int max = 0;
    char **map;
    if (check_wall(s2))
        ft_perror("Wall Is Not Valid\n");
    if (check_player_pos(s, data->inf) || character(s2) || check_color(s, data) || check_text_ext(s, data)) // add texture handling
    {
        if (check_player_pos(s, data->inf))
            ft_perror("Issue In Player\n");
        if (character(s2))
            ft_perror("Character Is Not Valid\n");
    }
    max = longest_str(data);
    map = fill_map_with_spaces(data, max);
    test(data, map);
    return (0);
}
    
