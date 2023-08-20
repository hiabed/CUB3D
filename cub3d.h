/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhassani <mhassani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 19:04:51 by ayylaaba          #+#    #+#             */
/*   Updated: 2023/08/20 02:22:23 by mhassani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <fcntl.h>
# include <math.h>
# include <mlx.h>
# include <limits.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 2147
# endif

typedef struct s_count
{
	int     i;
    int     count;
    int     count1;
    int     count2;
    int     count3;
    int     count4;
    char    **a;
    char    *trim;
	
} t_count;



typedef struct s_infos
{
	double	rad;
	double	x;
	double	y;
	double	angle;
	double	cur_angl;
	int		count;
	char	*trim;
}	t_inf;

typedef struct s_imgs
{
	void	*img;
	int		width;
	int		height;
	char	*add;
	int		line;
	int		bits;
	int		wa33;
	int 	end;
	int 	x;
	float 	y;
	float 	grid;
}	t_imgs;

typedef struct creat_picture
{
	char *tmp;
	    char    *trim;
	int		i;
	int		k;
	int		l;
	int		j;
	float	rad_v2;
	t_imgs	*imgs;
	t_inf 	*inf;
	t_count *count;
	int c_color;
	int f_color;
	int		start;
	int		begin;
	int		old_s;
	char	dir_h;
	char	dir_v;
	char	*map;
	char	**map_v3;
	char	**map_v2;
	float	x_p;
	float	y_p;
	float	angl;
	float	r_left;
	float	r_right;
	float	ray_pos;
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
	float	deta;
	float	teta_ptr;
	int		bit_pixl;
	void	*image_adrr;
	char	*adrr;
	int		m_up;
	int		m_down;
	int		m_left;
	int		m_right;
	float	speed;
	int		move_check;
	int		ray_distance;
	int		player_size;
	int		middle_ray;
	int		wall_check;
	int		f;
	double	dist_p_screen;
	double	wall_tall;
	float	tx_hor;
	float	ty_hor;
	float	ray_distance_hor;
	float	tx_ver;
	float	ty_ver;
	float	ray_distance_ver;
	float	new_ray_distance;
	float	ray_distancee;
	float	tx;
	float	ty;
	char 	*north_xpm;
	char 	*south_xpm;
	char 	*east_xpm;
	char 	*west_xpm;
	char 	*hold_path;
}			t_picture;

void		initialize_images(t_picture *data);
int 		check_text_ext(char **map, t_picture *data);
void		my_put_pixl(t_picture *test, int x, int y, int color);
void		draw_walls(t_picture *data);
void		draw_wall(t_picture * data, t_imgs *imgs, int s);
int			is_wall(t_picture *data, float x, float y);
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
void 		ft_perror(char *s);
int			check_map_extantion(char *map);
int			character(char **map);
int    		check_double_element(t_count *c, char **map);
int			check_wall_text(t_count *c, char **src);
int     	check_character(char **s, char **s2, t_picture *data);
int     	check_number(char *str, char ch, t_picture *data);
void		move_up(t_picture *data);
void		move_down(t_picture *data);
void		move_right(t_picture *data);
void		move_left(t_picture *data);
t_picture	*ver_int(t_picture *data, float angle, float x_i, float y_i);
t_picture	*hor_int(t_picture *data, float angle, float x_i, float y_i);
int     	check_color(char **map, t_picture *data);
char	**ft_free(char **s);
void	draw_horizontal_ray(t_picture *data, float angle);
void	draw_vertical_ray(t_picture *data, float angle);
t_picture	*initialize_structure(int ac, char **av);
void	initialize_the_angle_of_player(t_picture *test);
void	ft_check_errors(char *map_content, t_picture *test, char **av);
void ft_perror(char *s);
int	ft_exit(void);
void	check_new_line(char *str);
void	put_player(t_picture *test, int color);
void	draw_map(char **map, t_picture *test);
char	*get_content(char *str, char c);
int	check_textures(char *line_content, char *wall_pos, t_picture *data);
void	draw_squar(t_picture *test, int old_x, int old_y, int color);
int	key_released(int key, t_picture *test);
int	give_key(int key, t_picture *test);
int	animate_moves(t_picture *test);
int ft_check_move(t_picture *data ,double x, double y);

#endif