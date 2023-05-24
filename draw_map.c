/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iganiev <iganiev@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 09:02:35 by iganiev           #+#    #+#             */
/*   Updated: 2023/05/22 08:42:38 by iganiev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	color_pixel(t_dot *data)
{
	int	tmp_x;
	int	tmp_x1;
	int	tmp_y;
	int	tmp_y1;

	tmp_x = data->vars.x;
	tmp_x1 = data->vars.x1;
	tmp_y = data->vars.y;
	tmp_y1 = data->vars.y1;
	if (data->vars.z || data->vars.z1)
	{
		if (data->col_matrix[tmp_y][tmp_x])
			data->color = data->col_matrix[tmp_y][tmp_x];
		else
			data->color = 0xff7f;
	}
	else
		data->color = 0xfffafa;
}

void	bresenham(t_dot *data)
{
	float	delta_x;
	float	delta_y;
	int		max_delta;

	data->vars.z = data->matrix[(int)data->vars.y][(int)data->vars.x] * \
										data->z_scale;
	data->vars.z1 = data->matrix[(int)data->vars.y1][(int)data->vars.x1] * \
										data->z_scale;
	color_pixel(data);
	zoom_map(data);
	translate_map(data);
	rotate_map(data);
	delta_x = data->vars.x1 - data->vars.x;
	delta_y = data->vars.y1 - data->vars.y;
	max_delta = max_param(fabs(delta_x), fabs(delta_y));
	delta_x /= max_delta;
	delta_y /= max_delta;
	while (((int)(data->vars.x - data->vars.x1)) || \
			(int)(data->vars.y - data->vars.y1))
	{
		my_mlx_pixel_put(&data->img_buff, data->vars.x, \
							data->vars.y, data->color);
		data->vars.x += delta_x;
		data->vars.y += delta_y;
	}
}

void	draw_line(t_dot *data, int x, int y)
{
	if (x < data->column - 1)
	{
		data->vars.x = x;
		data->vars.y = y;
		data->vars.x1 = x + 1;
		data->vars.y1 = y;
		bresenham(data);
	}
	if (y < data->row - 1)
	{
		data->vars.x = x;
		data->vars.y = y;
		data->vars.x1 = x;
		data->vars.y1 = y + 1;
		bresenham(data);
	}
}

void	draw_map(t_dot *data)
{
	int	x;
	int	y;

	y = -1;
	while (++y < data->row)
	{
		x = -1;
		while (++x < data->column)
		{
			draw_line(data, x, y);
		}
	}
}
