/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcing_color.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhassani <mhassani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 11:18:47 by ayylaaba          #+#    #+#             */
/*   Updated: 2023/08/21 00:08:11 by mhassani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

long long	ft_atoi(const char *str)
{
	int			i;
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

void	check_color_number(char **n)
{
	if (!ft_isdigit(n[0]) || !ft_isdigit(n[1])
		|| !ft_isdigit(n[2]))
	{
		ft_free(n);
		ft_perror("Is Not Valid RGB\n");
	}
	if (ft_atoi(n[0]) < 0 || ft_atoi(n[1]) < 0
		|| ft_atoi(n[2]) < 0)
	{
		ft_free(n);
		ft_perror("Is Not Valid RGB\n");
	}
}

int	check_number(char *str, char ch, t_picture *data)
{
	char	**n;

	data->d->j = -1;
	n = ft_split(str, ',');
	check_color_number(n);
	while (++data->d->j < 3)
	{
		if (!(ft_atoi(n[data->d->j]) >= 0 && ft_atoi(n[data->d->j]) <= 255)
			|| (ft_atoi(n[data->d->j]) > INT_MAX))
		{
			ft_free(n);
			ft_perror("Is Not Valid RGB\n");
		}
	}
	if (ch == 'C')
		data->c_color = (ft_atoi(n[0]) * 256 * 256) + (ft_atoi(n[1])
				* 256) + ft_atoi(n[2]);
	else if (ch == 'F')
		data->f_color = (ft_atoi(n[0]) * 256 * 256) + (ft_atoi(n[1])
				* 256) + ft_atoi(n[2]);
	ft_free(n);
	return (0);
}

int	comma(char *str)
{
	int	i;
	int	count;

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

int	check_color(char **map, t_picture *data)
{
	data->d->i = -1;
	while (map[++data->d->i])
	{
		data->s->trim = ft_strtrim(map[data->d->i], " ");
		if (data->s->trim[0] == 'C' || data->s->trim[0] == 'F')
		{
			data->s->ch = data->s->trim[0];
			data->s->line_content = get_content(data->s->trim, ' ');
			if (comma(data->s->line_content))
			{
				free(data->s->line_content);
				free(data->s->trim);
				ft_perror("more than comma in RGB\n");
			}
			if (check_number(data->s->line_content, data->s->ch, data))
			{
				free(data->s->line_content);
				free(data->s->trim);
				return (1);
			}
			free(data->s->line_content);
		}
		free(data->s->trim);
	}
	return (0);
}
