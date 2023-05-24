/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iganiev <iganiev@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 17:21:18 by iganiev           #+#    #+#             */
/*   Updated: 2023/05/22 11:00:35 by iganiev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "libft/libft.h"
# include "printf42/ft_printf.h"
# include "mlx/mlx.h"
# include <math.h>
// # include <stdio.h>
# include <fcntl.h>

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;

	int		win_width;
	int		win_length;
}	t_data;

typedef struct s_var
{
	int		fd;
	char	*line_from_map;
	char	*line;
	int		n_prev_line_elems;
	char	**splitted_line;
	int		current_elems;

	float	x;
	float	y;
	float	x1;
	float	y1;
	int		z;
	int		z1;
}	t_var;

typedef struct dot
{
	int		row;
	int		column;
	int		**matrix;
	int		**col_matrix;

	int		zoom;
	int		move_x;
	int		move_y;
	int		move_z;
	float	z_scale;
	int		color;
	double	alpha;
	double	betta;
	double	gamma;

	t_data	img_buff;
	t_var	vars;

	void	*mlx_ptr;
	void	*win_ptr;
}	t_dot;

void	init_var(t_dot *data);
void	read_map(char *map, t_dot *data);
int		get_row(char *map);
int		get_column(char *map);
void	fill_matrix(int *matrix, char *line, int expected_columns);

void	fill_col_matrix(int *matrix, char *line, int expected_columns);
void	get_color(char *map, t_dot *data);

int		valid_map(char *map_file);
int		empty_map(char *map);
int		valid_parameter(char *file, char *extention);

void	clean_map(t_dot *data);
void	clean_color(t_dot *data);
int		esc_win(int key, t_dot *data);
int		close_win(t_dot *data);

float	max_param(float x, float y);
int		ft_atoi_base(const char *str, int str_base);
int		ft_strcmp(char *s1, char *s2);
int		element_count(char const *str, char c);

void	bresenham(t_dot *data);
void	color_pixel(t_dot *data);
void	draw_line(t_dot *data, int x, int y);
void	draw_map(t_dot *data);

void	zoom_map(t_dot *data);
void	translate_map(t_dot *data);
void	rotation_matrix(float *x, float *y, int z, t_dot *data);
void	rotate_map(t_dot *data);

void	use_mlx(t_dot *data);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
void	draw_again(t_dot *data);

int		zoom_key_hook(int keycode, t_dot *data);
int		map_view_keyhook(int keycode, t_dot *data);
int		translate_key_hook(int keycode, t_dot *data);
int		z_axis_key_hook(int keycode, t_dot *data);
int		rotation_key_hook(int keycode, t_dot *data);
int		key_hooks(int keycode, t_dot *data);

#endif