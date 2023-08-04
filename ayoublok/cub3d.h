/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhassani <mhassani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 19:04:51 by ayylaaba          #+#    #+#             */
/*   Updated: 2023/08/04 22:12:13 by mhassani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <fcntl.h>
# include <math.h>
# include <mlx.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 2147
# endif

typedef struct creat_data
{
	// int         x;
	// int         y;
	// int         color;
	// int         wigth;
	// int         hight;
	// void        *image;
}			t_data;

typedef struct creat_picture
{
	t_data	*data;
	char	*map;
	char	**map_v3;
	char	**map_v2;
	double	x_p;
	double	y_p;
	double	angl;
	double	r_left;
	double	r_right;
	double	ray_pos;
	double	wall_tall;
	double	dist_p_screen;
	double	tan_angl;
	int		color;
	int		wigth;
	int		hight;
	void	*image;
	void	*ptr;
	void	*wind;
	void	*mlx;
	int		y;
	int		x;
	int		len;
	int		end;
	double	deta;
	double	teta_ptr;
	int		bit_pixl;
	void	*image_adrr;
	char	*adrr;
	int		m_up;
	int		m_down;
	int		m_left;
	int		m_right;
	int		speed;
	int		move_check;
	double	ray_distance;
	double	new_ray_distance;
	int		player_size;
	int		f;
}			t_picture;

void		draw_map(char **map, t_picture *test);
int			is_wall_ray(t_picture *data, int x, int y, int x_p, int y_p,
				float alpha);
int			is_wall(char **map, int x, int y);
void		rotation(t_picture *data);
void		init_player(char **map, t_picture *test);
char		*get_next_line(int fd);
int			ft_sreach(char *str);
int			ft_strlen(char *str);
char		*ft_strdup(char *s1);
char		**ft_split(char *s, char c);
char		*ft_substr(char *s, int start, int len);
int			ft_strcmp(char *s1, char *s2);
char		*ft_strtrim(char *s1, char *set);
int			ft_isdigit(char *str);
char		*ft_strrchr(char *s, int c);
void		ft_perror(void);
int			check_map_extantion(char *map);
int			character(char **map);
int			check_double_element(char **map);
int			check_wall_text(char **src);
int			check_character(char **s);
int			check_color(char **map);
int			check_text_ext(char **map);
char		*get_content(char *str, char c);
void		move_up(t_picture *data);
void		move_down(t_picture *data);
void		move_right(t_picture *data);
void		move_left(t_picture *data);
void		my_put_pixl(t_picture *test, int x, int y, int color);
void		inital_draw_wall(t_picture *data, char **map);

#endif