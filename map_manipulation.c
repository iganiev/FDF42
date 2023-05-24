/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_manipulation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iganiev <iganiev@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 13:55:09 by iganiev           #+#    #+#             */
/*   Updated: 2023/05/22 08:46:21 by iganiev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	zoom_map(t_dot *data)
{
	data->vars.x *= data->zoom;
	data->vars.x1 *= data->zoom;
	data->vars.y *= data->zoom;
	data->vars.y1 *= data->zoom;
	data->vars.z *= data->zoom;
	data->vars.z1 *= data->zoom;
}

void	translate_map(t_dot *data)
{
	data->vars.x += data->move_x;
	data->vars.x1 += data->move_x;
	data->vars.y += data->move_y;
	data->vars.y1 += data->move_y;
	data->vars.z += data->move_z;
	data->vars.z1 += data->move_z;
}

void	rotation_matrix(float *x, float *y, int z, t_dot *data)
{
	float	temp_x;
	float	temp_y;

	temp_x = *x - ((data->column / 2) * data->zoom);
	temp_y = *y - ((data->row / 2) * data->zoom);
	*x = (temp_x * cos(data->alpha) * cos(data->betta)) - \
		(temp_y * (sin(data->alpha)) + \
		(z * cos(data->alpha) * sin(data->betta)));
	*y = (temp_x * cos(data->betta) * sin(data->alpha) * cos(data->gamma)) + \
		(temp_y * cos(data->alpha) * cos(data->gamma)) + \
		(z * cos(data->gamma) * sin(data->alpha) * sin(data->betta)) - \
		(z * sin(data->gamma) * cos(data->betta));
	*y += ((data->column / 2) * data->zoom);
	*x += ((data->row / 2) * data->zoom);
}

void	rotate_map(t_dot *data)
{
	rotation_matrix(&data->vars.x, &data->vars.y, data->vars.z, data);
	rotation_matrix(&data->vars.x1, &data->vars.y1, data->vars.z1, data);
}
