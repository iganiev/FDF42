/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_key_hooks.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iganiev <iganiev@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 02:07:48 by iganiev           #+#    #+#             */
/*   Updated: 2023/05/22 08:13:18 by iganiev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	zoom_key_hook(int keycode, t_dot *data)
{
	if (keycode == 6)
		data->zoom += 2;
	if (keycode == 7)
		data->zoom -= 2;
	draw_again(data);
	return (0);
}

int	map_view_keyhook(int keycode, t_dot *data)
{
	if (keycode == 49)
	{
		data->alpha = 0;
		data->betta = 0;
		data->gamma = 0;
	}
	if (keycode == 34)
	{
		data->alpha = 35.526 * (M_PI / 180);
		data->betta = 0 * (M_PI / 180);
		data->gamma = 45 * (M_PI / 180);
	}
	draw_again(data);
	return (0);
}

int	translate_key_hook(int keycode, t_dot *data)
{
	if (keycode == 126)
		data->move_y -= 10;
	if (keycode == 125)
		data->move_y += 10;
	if (keycode == 123)
		data->move_x -= 10;
	if (keycode == 124)
		data->move_x += 10;
	if (keycode == 47)
		data->move_z += 10;
	if (keycode == 43)
		data->move_z -= 10;
	draw_again(data);
	return (0);
}

int	z_axis_key_hook(int keycode, t_dot *data)
{
	if (keycode == 24 || keycode == 69)
		data->z_scale += 0.1;
	if (keycode == 27 || keycode == 78)
		data->z_scale -= 0.1;
	draw_again(data);
	return (0);
}

int	rotation_key_hook(int keycode, t_dot *data)
{
	if (keycode == 0)
		data->alpha += 10 * (M_PI / 180);
	if (keycode == 2)
		data->alpha -= 10 * (M_PI / 180);
	if (keycode == 13)
		data->gamma += 10 * (M_PI / 180);
	if (keycode == 1)
		data->gamma -= 10 * (M_PI / 180);
	draw_again(data);
	return (0);
}
