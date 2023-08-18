/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcing_char_extention.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhassani <mhassani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 16:41:59 by ayylaaba          #+#    #+#             */
/*   Updated: 2023/08/18 18:27:53 by mhassani         ###   ########.fr       */
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
int     check_player_pos(char **str)
{
    int i;
    int count;
    char    *trim;
    int j;

    i = 0;
    count = 0;
    while (str[i])
    {
        j = 0;
        trim = ft_strtrim(str[i], " ");
        while (trim[j])
        {
            if ((trim[0] == '0' || trim[0] == '1') && trim[j] == 'N')
                count++;
            else  if ((trim[0] == '0' || trim[0] == '1') && trim[j] == 'S')
                count++;
            else  if ((trim[0] == '0' || trim[0] == '1') && trim[j] == 'W')
                count++;
            else  if ((trim[0] == '0' || trim[0] == '1') && trim[j] == 'E')
                count++;
            j++;
        }
        free(trim);
        i++;
    }
    if (count == 1)
        return (0);
    return (1);
}

int     character(char **map)
{
    int     i;
    int     j;
    char    *trim;

    i = 0;
    while (map[i])
    {
        j = 0;
        trim = ft_strtrim(map[i], " ");
        if (trim[0] == '1')
        {
            while (map[i][j])
            {
                if (map[i][j] != '1' && map[i][j] != '0' && map[i][j] != 'W' && map[i][j] != 'E' && map[i][j] != ' ' && map[i][j] != 'N' && map[i][j] != 'S')
                    return (1);
                if (map[i][j] == 'W' || map[i][j] == 'E' || map[i][j] == 'N' || map[i][j] == 'S')
                {
                    if (player_space(map, i, j))
                    {
                        return (1);
                    }
                }
                j++;
            }
        }
        free(trim);
        i++;
    }
    return (0);
}

int    front_end_wall(char *str)
{
    int i;

    i = 0;
    while (str[i])
    {
        if (str[i] != '1')
            return (1);
        i++;
    }
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
        // trim = ft_strtrim(map[j], "\t");
        if (trim[0] != '1' || trim[ft_strlen(trim) - 1] != '1')
            return (1);
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

int     check_character(char **s, char **s2, t_picture *data)
{
    int     i;
    int     j;
    char    *trim;

    i = 0;
    if (check_wall(s2))
        ft_perror("Wall Is Not Valid\n");
    if (check_player_pos(s) || character(s2) || check_color(s, data) || check_text_ext(s, data)) // add texture handling
    {
        if (check_player_pos(s))
            ft_perror("Issue In Player\n");
        if (character(s2))
            ft_perror("Character Is Not Valid\n");
    //     if (check_text_ext(s))
    //         ft_perror("Texture Name or Extention Is Not Valid\n");
    }
    // exit(1);
    while (s[i])
    {
        trim = ft_strtrim(s[i], " ");
        if (trim[0] == '1')
        {
            j = 0;
            while (s[i][j])
            {
                if (s[i][j] == '0')
                {
                    if (s[i][j - 1] == ' ' || s[i][j + 1] == ' ')
                    {
                        free(trim);   
                        return (1);
                    }
                    else if (s[i - 1][j] == ' ' || s[i + 1][j] == ' ')
                    {
                        free(trim);   
                        return (1);
                    }
                }
                j++;
            }
        }
        free(trim);
        i++;
    }
    return (0);
}

