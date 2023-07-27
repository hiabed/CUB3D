/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayylaaba <ayylaaba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 12:28:19 by ayylaaba          #+#    #+#             */
/*   Updated: 2023/07/14 19:09:55 by ayylaaba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	*ft_strjoin(char *s1, char *s2, int i, int j)
{
	char	*get;

	if (!s1)
	{
		s1 = malloc(1);
		if (!s1)
			return (0);
		s1[0] = '\0';
	}
	get = malloc (ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!get)
	{
		free(s1);
		return (NULL);
	}
	while (s1[i])
	{
		get[i] = s1[i];
		i++;
	}
	while (s2[j])
		get[i++] = s2[j++];
	get[i] = '\0';
	free(s1);
	return (get);
}

char	*ft_read(int fd, char *s)
{
	char	*ptr;
	int		n;

	ptr = malloc (sizeof(char) * BUFFER_SIZE + 1);
	if (!ptr)
		return (NULL);
	n = 1;
	while (ft_sreach(s) == 0 && n != 0)
	{
		n = read(fd, ptr, BUFFER_SIZE);
		if (n == -1)
		{
			free(s);
			free(ptr);
			return (0);
		}
	ptr[n] = '\0';
	s = ft_strjoin (s, ptr, 0, 0);
	}
	free(ptr);
	return (s);
}

char	*get_next_line(int fd)
{
	static char	*newbuf;
	int			i;
	int			j;

	i = 0;
	j = 0;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	newbuf = ft_read(fd, newbuf);
	if (newbuf == NULL)
		return (NULL);
	return (newbuf);
}

// int		main()
// {
// 	int	fd;

// 	fd = open("main", O_CREAT | O_RDONLY);
// 	printf("%s", get_next_line(fd));
// }