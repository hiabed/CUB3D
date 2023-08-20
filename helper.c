/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayylaaba <ayylaaba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 00:39:06 by ayylaaba          #+#    #+#             */
/*   Updated: 2023/08/19 18:25:01 by ayylaaba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	*get_content(char *str, char c)
{
	int		i;
	int		i2;
	char	*content;

	i = 0;
	i2 = 0;
	while (str[i] && str[i] != c) // skip object (C or F)
		i++;
	while (str[i] == '\t' || str[i] == ' ') // skip space
	{
		i++;
		i2++;
	}
	content = malloc(sizeof(char) * (ft_strlen(str + i) + 1));
	if (!content)
		return (NULL);
	i2 = 0;
	while (str[i])
		content[i2++] = str[i++];
	content[i2] = '\0';
	return (content);
}
