/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_functions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iganiev <iganiev@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 13:59:39 by iganiev           #+#    #+#             */
/*   Updated: 2023/05/17 18:49:39 by iganiev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	use_mlx(t_dot *data)
{
	data->mlx_ptr = mlx_init();
	data->win_ptr = mlx_new_window(data->mlx_ptr, data->img_buff.win_width, \
									data->img_buff.win_length, "FDF");
	data->img_buff.img = mlx_new_image(data->mlx_ptr, data->img_buff.win_width, \
										data->img_buff.win_length);
	data->img_buff.addr = mlx_get_data_addr(data->img_buff.img, \
											&data->img_buff.bits_per_pixel, \
						&data->img_buff.line_length, &data->img_buff.endian);
	draw_map(data);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, \
									data->img_buff.img, 0, 0);
	mlx_hook(data->win_ptr, 2, 1L << 0, key_hooks, data);
	mlx_hook(data->win_ptr, 17, 1L << 2, close_win, data);
	mlx_loop(data->mlx_ptr);
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	x += data->win_width / 2;
	y += data->win_length / 3;
	if ((x >= 0 && y >= 0) && \
			(x < data->win_width && y < data->win_length))
	{
		dst = data->addr + (y * data->line_length + x * \
				(data->bits_per_pixel / 8));
		*(unsigned int *)dst = color;
	}
}

void	draw_again(t_dot *data)
{
	mlx_destroy_image(data->mlx_ptr, data->img_buff.img);
	data->img_buff.img = mlx_new_image(data->mlx_ptr, data->img_buff.win_width, \
										data->img_buff.win_length);
	data->img_buff.addr = mlx_get_data_addr(data->img_buff.img, \
											&data->img_buff.bits_per_pixel, \
						&data->img_buff.line_length, &data->img_buff.endian);
	draw_map(data);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, \
									data->img_buff.img, 0, 0);
}

int	key_hooks(int keycode, t_dot *data)
{
	if (keycode == 6 || keycode == 7)
		zoom_key_hook(keycode, data);
	else if (keycode == 49 || keycode == 34)
		map_view_keyhook
		(keycode, data);
	else if (keycode == 126 || keycode == 125 || keycode == 124 || \
				keycode == 123 || keycode == 47 || keycode == 43)
		translate_key_hook(keycode, data);
	else if (keycode == 0 || keycode == 1 || keycode == 2 || keycode == 13)
		rotation_key_hook(keycode, data);
	else if (keycode == 24 || keycode == 27 || keycode == 78 || keycode == 69)
		z_axis_key_hook(keycode, data);
	else if (keycode == 53)
		esc_win(keycode, data);
	return (0);
}
